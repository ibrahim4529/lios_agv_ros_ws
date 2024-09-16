import sys
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel
from PySide6.QtCore import QThread, Signal, Slot
from inputs import get_gamepad, UnpluggedError
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3

class JoystickControl(Node):
    def __init__(self):
        super().__init__('joystick_control_qt')
        self.publisher_ = self.create_publisher(Vector3, 'velocity', 1)
        self.velocity = Vector3()
       

class GamepadThread(QThread):
    x_event = Signal(int)
    y_event = Signal(int)
    z_event = Signal(int)
    gamepad_event = Signal(str)

    def run(self):
        while True:
            try:
                events = get_gamepad()
                for event in events:
                    if event.ev_type == "Key" or event.ev_type == "Absolute":
                        if event.code == "ABS_X":
                            self.x_event.emit(event.state)
                        elif event.code == "ABS_Y":
                            self.y_event.emit(event.state)
                        elif event.code == "ABS_Z":
                            self.z_event.emit(event.state)
                    elif event.ev_type == "Key":
                        self.gamepad_event.emit(f"Button {event.code} {'pressed' if event.state == 1 else 'released'}")
                    self.gamepad_event.emit(f"Event: {event.ev_type}, Code: {event.code}, State: {event.state}")
            except UnpluggedError:
                self.gamepad_event.emit("Gamepad disconnected")
                break

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Gamepad Input Example")
        self.label = QLabel("Press a button on the gamepad", self)
        self.setCentralWidget(self.label)
        self.node = JoystickControl()

        # Set up the gamepad thread
        self.gamepad_thread = GamepadThread()
        self.gamepad_thread.gamepad_event.connect(self.publish_event)
        self.gamepad_thread.x_event.connect(self.update_x)
        self.gamepad_thread.y_event.connect(self.update_y)
        self.gamepad_thread.z_event.connect(self.update_z)
        self.gamepad_thread.start()

    @Slot(str)
    def publish_event(self, event):
        self.node.publisher_.publish(self.node.velocity)
        self.label.setText(event)
    
    @Slot(int)
    def update_x(self, x):
        x = self.map(x)
        self.node.velocity.x = x
        
    
    @Slot(int)
    def update_y(self, y):
        y = self.map(y)
        self.node.velocity.y = y
    
    @Slot(int)
    def update_z(self, z):
        z = self.map(z)
        self.node.velocity.z = z

    def map(self, value):
        # map from 0-255 to -1 to 1
        maped_value = (value - 127.5) / 127.5
        if abs(maped_value) < 0.1:
            maped_value = 0.0
        return maped_value
    def closeEvent(self, event):
        self.gamepad_thread.terminate()
        self.gamepad_thread.wait()
        self.node.destroy_node()
        rclpy.shutdown()
        super().closeEvent(event)


def main():
    rclpy.init()
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())

if __name__ == "__main__":
    main()