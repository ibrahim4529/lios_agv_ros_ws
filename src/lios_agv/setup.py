from setuptools import find_packages, setup

package_name = 'lios_agv'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ubuntu',
    maintainer_email='ibrahim.hanif4529@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'controller = lios_agv.robot_control:main',
            'joystick = lios_agv.joystick_control:main',
            'manual = lios_agv.manual_control:main',
        ],
    },
)
