# Mirobot ROS packages
This is the Mirobot ROS package designed by Thor Zhou.
email:wlkata_mirobot@tsinew.com
These packages support Moveit!, RViz and serial communication with Mirobot.

## 1. Download and install
Download ros packages for mirobot

then manually copy package folders *mirobot_urdf_2* *mirobot_moveit_config* and *mirobot_gazebo* into a catkin_ws/src.

Install ros serial package
```bash
$ sudo apt-get install ros-kinetic-serial
```

Compile
```bash
$ catkin_make
```

## 2. Set up enviroment
Source all setup.bash files to set up your enviroment.
```bash
# System configure ROS environment variables automatically every time you open a ternimal
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

## 3. Simulation and Control
Before ROS control, make sure that your manipulator is in the "homing" position.
Connect your mirobot to computer and get USB permission to access mirobot
```bash
$ sudo chmod +777 /dev/ttyUSB0

```
If you are using a virtual machine running Linux, turn off graphics hardware acceleration, otherwise gazebo may not start properly.

### 3.1 Rviz Control Mode: 
Show the xacro model of mirobot in rviz, then drag the scroll bar of each axis in rviz to control the movement of the manipulator.
```bash
roslaunch mirobot_urdf_2 display.launch
```

### 3.2 Moveit+gazebo Control Mode: 
First, install [ros_controller]() by: 

```bash
$ sudo apt-get install ros-kinetic-ros-control ros-kinetic-ros-controllers
```
Install [Moveit!](https://moveit.ros.org/install/) by: 

```bash
$ sudo apt install ros-kinetic-moveit
```
Install [Gazebo_ros_pkgs](http://gazebosim.org/tutorials?tut=ros_installing&cat=connect_ros) by:

```bash
$ sudo apt-get install ros-kinetic-gazebo-ros-pkgs ros-kinetic-gazebo-ros-control
```
Note, if your ROS version is not *kinetic*, in the above commands, replace *kinetic* with your ROS version, e.g. *noetic*.  

Then, display the mirobot model in rviz and gazebo by using the rviz interface of moveit to drag the manipulator for motion planning, click the "execute" button in moveit, and control the virtual manipulator in gazebo to move with the external real manipulator.
```bash
roslaunch mirobot_gazebo mirobot_bringup_moveit.launch
```
## 4. Experiment demos:
Watch the tutorials here: 
https://www.youtube.com/watch?v=acSDDzRKDmg&list=PLrf9BLY5v4umZRIOZqtVRDmIpB0PcmTDz

Find out the experiment demos source code (ROS_experiment_1, 2...) from the file list.


