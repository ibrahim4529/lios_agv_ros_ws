import rclpy
from rclpy.node import Node
from pwm_messages.msg import Pwm
import pygame
import numpy as np

# Initialize Pygame and Joystick
pygame.init()

list_joysticks = [pygame.joystick.Joystick(x).get_name() for x in range(pygame.joystick.get_count())]
print("Detected joysticks: ", list_joysticks)
pygame.joystick.init()

# Function to map value from one range to another
def map_value(value, in_min, in_max, out_min, out_max):
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

class RobotController(Node):
    def __init__(self):
        super().__init__('robot_controller')
        self.publisher_ = self.create_publisher(Pwm, 'pwm',1)
        self.max_pwm = 150

        # Inisialisasi Pygame dan Joystick
        pygame.init()
        pygame.joystick.init()
        
        if pygame.joystick.get_count() == 0:
            self.get_logger().error("No joystick found!")
            return

        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()
        self.get_logger().info(f"Initialized joystick: {self.joystick.get_name()}")

        # Check if joystick is detected
        if pygame.joystick.get_count() == 0:
            self.get_logger().error("No joystick detected!")
            return

        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()

    def process_joystick(self):
        pygame.event.pump()
        # read input from joystick buttons < > ^ v
        hat = self.joystick.get_hat(0)

        print("Hat: ", hat)
        if hat[0] == 1:
            self.move_right()
        elif hat[0] == -1:
            self.move_left()
        if hat[1] == 1:
            self.move_up()
        elif hat[1] == -1:
            self.move_down()
        elif hat[0] == 0 and hat[1] == 0:
            self.stop()

        # Hitung nilai PWM
        # vx = self.joystick.get_axis(0)  # Left stick horizontal
        # vy = -self.joystick.get_axis(1)  # Left stick vertical (inverted)
        # omega = self.joystick.get_axis(2)  # Right stick horizontal for rotation

    def move_right(self):
        self.get_logger().info("Moving right")
        pwm = Pwm()
        pwm.pwm1 = 255
        pwm.pwm2 = 255
        pwm.pwm3 = -255
        pwm.pwm4 = -255
        self.publisher_.publish(pwm)
    
    def move_left(self):
        self.get_logger().info("Moving left")
        pwm = Pwm()
        pwm.pwm1 = -255
        pwm.pwm4 = 255
        pwm.pwm2 = -255
        pwm.pwm3 = 255
        self.publisher_.publish(pwm)
    
    def move_up(self):
        self.get_logger().info("Moving up")
        pwm = Pwm()
        pwm.pwm1 = 255
        pwm.pwm2 = -255
        pwm.pwm3 = 255
        pwm.pwm4 = -255
        self.publisher_.publish(pwm)
    
    def move_down(self):
        self.get_logger().info("Moving down")
        pwm = Pwm()
        pwm.pwm1 = -255
        pwm.pwm2 = 255
        pwm.pwm3 = -255
        pwm.pwm4 = 255
        self.publisher_.publish(pwm)
    
    def stop(self):
        self.get_logger().info("Stop")
        pwm = Pwm()
        pwm.pwm1 = 0
        pwm.pwm2 = 0
        pwm.pwm3 = 0
        pwm.pwm4 = 0
        self.publisher_.publish(pwm)
    
    def start(self):
        while rclpy.ok():
            self.process_joystick()
            rclpy.spin_once(self, timeout_sec=0.1)

    
    # def velocity_to_pwm(self, velocity):
    #    # Konversi kecepatan ke PWM, memastikan dalam range yang valid
    #     pwm = int(velocity * self.max_pwm)
    #     return max(-self.max_pwm, min(self.max_pwm, pwm))




def main(args=None):
    rclpy.init(args=args)
    robot_controller = RobotController()
    
    try:
        robot_controller.start()
    except KeyboardInterrupt:
        pass
    finally:
        robot_controller.destroy_node()
        rclpy.shutdown()
        pygame.quit()

if __name__ == '__main__':
    main()