import rclpy
from rclpy.node import Node
import pygame
from geometry_msgs.msg import Vector3

class JoystickControl(Node):
    def __init__(self):
        super().__init__('joystick_control')
        self.publisher_ = self.create_publisher(Vector3, 'velocity', 1)
        pygame.init()
        pygame.joystick.init()
        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()
        self.velocity = Vector3()
        self.velocity.x = 0.0
        self.velocity.y = 0.0
        self.velocity.z = 0.0

    def run(self):
        while rclpy.ok():
            self.calculate_input()
            self.publisher_.publish(self.velocity)
            # print(f"Publishing: X: {self.velocity.x}, Y: {self.velocity.y}, Z: {self.velocity.z}")
            rclpy.spin_once(self, timeout_sec=0.1)

    def calculate_input(self):
        pygame.event.get()
        hat = self.joystick.get_hat(0)
        x = self.joystick.get_axis(0)
        y = self.joystick.get_axis(1)
        z = self.joystick.get_axis(3)
        print(f"X: {x}, Y: {y}, Z: {z}")

        # clean x and y and z values
        if abs(x) < 0.1:
            x = 0.0
        if abs(y) < 0.1:
            y = 0.0
        if abs(z) < 0.1:
            z = 0.0
        
        # invert y axis
        y = -y

        if hat[0] == 1:
            x = 1.0
            y = 0.0
            z = 0.0
        elif hat[0] == -1:
            x = -1.0
            y = 0.0
            z = 0.0
        elif hat[1] == 1:
            x = 0.0
            y = 1.0
            z = 0.0
        elif hat[1] == -1:
            x = 0.0
            y = -1.0
            z = 0.0


        self.velocity.x = float(x)
        self.velocity.y = float(y)
        self.velocity.z = float(z)
    
def main(args=None):
    rclpy.init(args=args)
    joystick_control = JoystickControl()
    try:
        joystick_control.run()
    except KeyboardInterrupt:
        print("Keyboard Interrupt")
    finally:
        rclpy.shutdown()
        rclpy.destroy_node(joystick_control)