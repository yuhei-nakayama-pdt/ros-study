#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "basic_twist_publisher");
  ros::NodeHandle n;

  // publish
  ros::Publisher cmd_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Rate loop_rate(10);

  while (ros::ok()) {
    geometry_msgs::Twist cmd_vel;
    cmd_vel.linear.x = 1.0;
    cmd_pub.publish(cmd_vel);
    ros::spinOnce();
    loop_rate.sleep();
    ROS_INFO("published");
  }
  return 0;
}
