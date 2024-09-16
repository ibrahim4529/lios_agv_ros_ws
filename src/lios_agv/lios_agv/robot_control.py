from pwm_messages.msg import Pwm
from geometry_msgs.msg import Vector3
import rclpy
from rclpy.node import Node
import math


class RobotControl(Node):
    def __init__(self):
        super().__init__('lios_agv_control')
        self.publisher_ = self.create_publisher(Pwm, 'pwm', 1)
        self.velocity_sub = self.create_subscription(Vector3, 'velocity', self.velocity_callback, 1)
        print("Robot Control Node Initialized")
        self.max_pwm = 255
        self.pwm = Pwm()

    def velocity_callback(self, msg):
        vx = msg.x
        vy = msg.y
        Omega = msg.z

        theta1 = math.radians(135)
        theta2 = math.radians(45)
        theta3 = math.radians(315)
        theta4 = math.radians(225)
        
        # Robot parameters
        R = 0.135  # Distance from center to wheel in meters
        
        # Calculate wheel velocities
        v1 = -math.sin(theta1) * vx + math.cos(theta1) * vy + R * Omega
        v2 = -math.sin(theta2) * vx + math.cos(theta2) * vy + R * Omega
        v3 = -math.sin(theta3) * vx + math.cos(theta3) * vy + R * Omega
        v4 = -math.sin(theta4) * vx + math.cos(theta4) * vy + R * Omega
        
        # Find max velocity for normalization
        max_v = max(abs(v1), abs(v2), abs(v3), abs(v4))
        
        # Convert to PWM values (assuming max velocity should correspond to PWM 255)
        pwm1 = int((v1 / max_v) * self.max_pwm) if max_v != 0 else 0
        pwm2 = int((v2 / max_v) * self.max_pwm) if max_v != 0 else 0
        pwm3 = int((v3 / max_v) * self.max_pwm) if max_v != 0 else 0
        pwm4 = int((v4 / max_v) * self.max_pwm) if max_v != 0 else 0

        self.pwm.pwm1 = pwm1
        self.pwm.pwm2 = pwm2
        self.pwm.pwm3 = pwm3
        self.pwm.pwm4 = pwm4
        self.publisher_.publish(self.pwm)
        
        
       
def main(args=None):
    rclpy.init(args=args)
    robot_control = RobotControl()
    try:
        rclpy.spin(robot_control)
    except KeyboardInterrupt:
        print("Keyboard Interrupt")
    finally:
        robot_control.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
