#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv){
  ros::init(argc, argv, "basic_simple_talker");
  ros::NodeHandle n;
  ros::NodeHandle pn("~"); // receive from ros launch
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 10);
  ros::Rate loop_rate(10);
  std::string msg_chatter="hello world!";
  pn.getParam("content", msg_chatter); // if not content, just ignore

  while (ros::ok()){
    std_msgs::String msg;
    msg.data = msg_chatter;
    ROS_INFO("publish: %s", msg.data.c_str());
    chatter_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
