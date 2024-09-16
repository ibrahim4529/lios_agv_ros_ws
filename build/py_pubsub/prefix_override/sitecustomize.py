import sys
if sys.prefix == '/home/ubuntu/.platformio/penv':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ubuntu/ros_ws/install/py_pubsub'
