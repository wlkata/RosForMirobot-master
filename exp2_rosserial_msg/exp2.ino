/* 
 * Receives a joint_state message (4 values) and sends it to Serial 
 */

#include <ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>


ros::NodeHandle nh;

float r2d = 57.296; 
float x; 

void joint_cb( const sensor_msgs::JointState& msg){

  for(int j=0; j<4; j++){
    x = msg.position[j];   
    Serial.println(x); 
    delay(10); 
  }  
}

ros::Subscriber<sensor_msgs::JointState> s("/joint_states", &joint_cb);

void setup()
{
  // start serial communication
  Serial.begin(115200);
  nh.initNode();
  nh.subscribe(s);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
