from setuptools import find_packages
from setuptools import setup

setup(
    name='pwm_messages',
    version='0.0.0',
    packages=find_packages(
        include=('pwm_messages', 'pwm_messages.*')),
)
