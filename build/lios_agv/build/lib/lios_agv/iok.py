import math
import numpy as np



# Desired velocities
vx = 0  # Example value for velocity in x-direction
vy = 1  # Example value for velocity in y-direction
theta_dot = 10.7  # Example value for rotational velocity
theta = 0.0  # Example orientation angle of the robot
r = 0.58  # Example radius of the wheels
R = 1.25 # Example distance from the center to the wheels

# # Calculate wheel velocities
# def calculate_wheel_speeds(vx, vy, theta_dot, theta, r, R):
#     transformation_matrix = np.array([
#         [-math.sin(theta + math.pi/4), math.cos(theta + math.pi/4), R],
#         [-math.sin(theta + 3*math.pi/4), math.cos(theta + 3*math.pi/4), R],
#         [-math.sin(theta + 5*math.pi/4), math.cos(theta + 5*math.pi/4), R],
#         [-math.sin(theta + 7*math.pi/4), math.cos(theta + 7*math.pi/4), R]
#     ])
#     desired_velocities = np.array([vx, vy, theta_dot])
#     wheel_speeds = (1/r) * np.dot(transformation_matrix, desired_velocities)
#     print(f"Wheel speeds: {wheel_speeds}")
#     return wheel_speeds
a1 = 45
a2 = 135
a3 = 225
a4 = 315

v1 = 1/0.58 * (math.sin(a1) * vx) + (math.cos(a1) * vy) + R * theta_dot
v2 = 1/0.58 * (math.sin(a2) * vx) + (math.cos(a2) * vy) + R * theta_dot
v3 = 1/0.58 * (math.sin(a3) * vx) + (math.cos(a3) * vy) + R * theta_dot
v4 = 1/0.58 * (math.sin(a4) * vx) + (math.cos(a4) * vy) + R * theta_dot

print(f"Wheel speeds: {v1}, {v2}, {v3}, {v4}")

# # Normalize wheel speeds to fit within the PWM range
# def normalize_wheel_speeds(wheel_speeds, max_pwm=255):
#     max_speed = np.max(np.abs(wheel_speeds))
#     if max_speed > 0:
#         normalized_speeds = (wheel_speeds / max_speed) * max_pwm
#     else:
#         normalized_speeds = wheel_speeds
#     return normalized_speeds

# # Get wheel speeds
# wheel_speeds = calculate_wheel_speeds(vx, vy, theta_dot, theta, r, R)

# # Normalize to PWM range
# pwm_speeds = normalize_wheel_speeds(wheel_speeds)

# # Print the PWM speeds (for debugging purposes)
# print(f"PWM speeds: {pwm_speeds}")

# # Send the PWM speeds to the motor controllers
# # This part depends on your specific hardware and motor control library
# # Example (pseudo-code):
# # motor_controller.set_pwm(wheel_1, pwm_speeds[0])
# # motor_controller.set_pwm(wheel_2, pwm_speeds[1])
# # motor_controller.set_pwm(wheel_3, pwm_speeds[2])
# # motor_controller.set_pwm(wheel_4, pwm_speeds[3])