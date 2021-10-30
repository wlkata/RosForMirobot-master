cmake_minimum_required(VERSION 2.8.3)
project(mirobot_urdf_2)

find_package(catkin REQUIRED
	gazebo_ros
	joint_state_publisher
	robot_state_publisher
	rviz
	serial
)

find_package(gazebo REQUIRED)

include_directories(include ${catkin_INCLUDE_DIRS} ${GAZEBO_INCLUDE_DIRS} ${SDFormat_INCLUDE_DIRS})

catkin_package(
	DEPENDS
  gazebo_ros
	joint_state_publisher
	robot_state_publisher
	rviz
	serial
  CATKIN_DEPENDS
  INCLUDE_DIRS
  LIBRARIES
)

find_package(roslaunch)

add_executable(mirobot_write_node src/mirobot_write_node.cpp)
target_link_libraries(mirobot_write_node ${catkin_LIBRARIES})

foreach(dir config launch meshes urdf)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)

