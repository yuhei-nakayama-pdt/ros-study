#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <ctime> 

int main(int argc, char** argv) {
  ros::init(argc, argv, "basic_twist_publisher");
  ros::NodeHandle n;

  // publish
  ros::Publisher cmd_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Rate loop_rate(10);

  std::time_t start = std::time(0);

  while (ros::ok()) {
    long elapsed = std::time(0) - start;
    geometry_msgs::Twist cmd_vel;
    cmd_vel.linear.x = 1.0;
    cmd_vel.angular.z = elapsed * 0.1;
    cmd_pub.publish(cmd_vel);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
