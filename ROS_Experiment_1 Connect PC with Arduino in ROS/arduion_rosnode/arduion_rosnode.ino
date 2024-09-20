#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/JointState.h>

ros::NodeHandle  nh;  //实例化句柄

int i = 0;  //测试用

void joint_cb(const sensor_msgs::JointState& msg)
{
    float pos=msg.position[0];
    Serial1.println(pos*57.296);
    float pos1=msg.position[1];
    Serial1.println(pos1*57.296);
    float pos2=msg.position[2];
    Serial1.println(pos2*57.296);
    float pos3=msg.position[3];
    Serial1.println(pos3*57.296);
}

ros::Subscriber<sensor_msgs::JointState>sub("/joint_states",joint_cb);

void setup(){
    Serial1.begin(115200);
    nh.initNode();
    nh.subscribe(sub);  
}

void loop(){
nh.spinOnce();
delay(10);//必不可少，测试发现少了延时以后不能进入回调函数
}
