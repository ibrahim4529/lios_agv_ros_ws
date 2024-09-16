from pwm_messages.msg import Pwm
import rclpy

class InverseKinematicPublisher(None):
    def __init__(self) -> None:
        super().__init__()
        self.publisher_ = self.create_publisher(Pwm, 'pwm', 10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        pwm = Pwm()
        pwm.pwm1 = 255
        pwm.pwm2 = 255
        pwm.pwm3 = -255
        pwm.pwm4 = -255
        self.publisher_.publish(pwm)
    
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

