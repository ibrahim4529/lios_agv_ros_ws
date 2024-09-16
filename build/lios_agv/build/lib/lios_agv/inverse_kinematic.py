from pwm_messages.msg import Pwm
import rclpy
from rclpy.node import Node
import pygame
import numpy as np
L = 0.135  # Jarak dari titik tengah ke roda (meter)
r = 0.029  # Jari-jari roda (meter)

class InverseKinematicPublisher(Node):
    def __init__(self):
        super().__init__('inverse_kinematic_publisher')
        self.publisher_ = self.create_publisher(Pwm, 'pwm', 10)
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.distance_from_center = 0.135 # in meters
        self.radius = 0.029 # in meters
        self.max_pwm = 255
        self.omega_max = 10.7

        pygame.init()
        pygame.joystick.init()

        if pygame.joystick.get_count() == 0:
            self.get_logger().error("No joystick found!")
            return
        
        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()
        self.get_logger().info(f"Initialized joystick: {self.joystick.get_name()}")
        self.pwm = Pwm()

    def timer_callback(self):
        pygame.event.pump()
        hat = self.joystick.get_hat(0)
        Vx = self.joystick.get_axis(0)
        Vy = self.joystick.get_axis(1)
        Omega = self.joystick.get_axis(3)
        speed = self.joystick.get_axis(2)

        max_speed = self.map_pwm(speed, -1, 1, 150, self.max_pwm)
        

        if hat[0] == 1:
            self.move_right(max_speed)
        elif hat[0] == -1:
            self.move_left(max_speed)
        if hat[1] == 1:
            self.move_up(max_speed)
        elif hat[1] == -1:
            self.move_down(max_speed)
        elif hat[0] == 0 and hat[1] == 0:
            self.stop()
       
        self.publisher_.publish(self.pwm)

    def map_pwm(self, input, in_min, in_max, out_min, out_max):
        return int((input - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
    
    def move_right(self, speed):
        self.pwm.pwm1 = -speed
        self.pwm.pwm2 = -speed
        self.pwm.pwm3 = speed
        self.pwm.pwm4 = speed
    
    def move_left(self, speed):
        self.pwm.pwm1 = speed
        self.pwm.pwm2 = speed
        self.pwm.pwm3 = -speed
        self.pwm.pwm4 = -speed
    
    def move_up(self, speed):
        self.pwm.pwm1 = -speed
        self.pwm.pwm2 = speed
        self.pwm.pwm3 = -speed
        self.pwm.pwm4 = speed
    
    def move_down(self, speed):
        self.pwm.pwm1 = speed
        self.pwm.pwm2 = -speed
        self.pwm.pwm3 = speed
        self.pwm.pwm4 = -speed
    
    def stop(self):
        self.pwm.pwm1 = 0
        self.pwm.pwm2 = 0
        self.pwm.pwm3 = 0
        self.pwm.pwm4 = 0
       
def main(args=None):
    rclpy.init(args=args)
    inverse_kinematic_publisher = InverseKinematicPublisher()
    try:
        rclpy.spin(inverse_kinematic_publisher)
    except KeyboardInterrupt:
        print("Keyboard Interrupt")
    finally:
        inverse_kinematic_publisher.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()