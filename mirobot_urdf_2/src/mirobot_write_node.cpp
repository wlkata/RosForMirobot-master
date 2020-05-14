#include <string>
#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/JointState.h>


serial::Serial _serial;				// serial object

void angle_write_callback(const sensor_msgs::JointState& msg)
{
	std::string Gcode = "";
	std_msgs::String result;
	char angle0[10];
	char angle1[10];
	char angle2[10];
	char angle3[10];
	char angle4[10];
	char angle5[10];

	sprintf(angle0, "%.2f", msg.position[0]*57.296);
	sprintf(angle1, "%.2f", msg.position[1]*57.296);
	sprintf(angle2, "%.2f", msg.position[2]*57.296);
	sprintf(angle3, "%.2f", msg.position[3]*57.296);
  sprintf(angle4, "%.2f", msg.position[4]*57.296);
	sprintf(angle5, "%.2f", msg.position[5]*57.296);
	Gcode = (std::string)"M50 G0 X" + angle0 + " Y" + angle1 + " Z" + angle2 + " A" + angle3 + "B" + angle4 + "C" + angle5 + " F3000" + "\r\n";
	ROS_INFO("%s", Gcode.c_str());
	_serial.write(Gcode.c_str());
	result.data = _serial.read(_serial.available());
}

int main(int argc, char** argv)
{	
	ros::init(argc, argv, "mirobot_write_node");//初始化，节点名称 "Mirobot_write_node"
	ros::NodeHandle nh;

	ros::Subscriber sub_angle = nh.subscribe("/joint_states", 1, angle_write_callback);//指定节点订阅的话题，并指定回调函数
	ros::Rate loop_rate(20);//指定了频率为20Hz

	try//尝试连接机械臂的串口
	{
		_serial.setPort("/dev/ttyUSB0");
		_serial.setBaudrate(115200);
		serial::Timeout to = serial::Timeout::simpleTimeout(1000);
		_serial.setTimeout(to);
		_serial.open();
		_serial.write("M50\r\n");
		ROS_INFO_STREAM("Port has been open successfully");
	}
	catch (serial::IOException& e)
	{
		ROS_ERROR_STREAM("Unable to open port");
		return -1;
	}
	
	if (_serial.isOpen())
	{
		ros::Duration(1).sleep();				
		ROS_INFO_STREAM("Attach and wait for commands");
	}

	while (ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
	
	return 0;
}


