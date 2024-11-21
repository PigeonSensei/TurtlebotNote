#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlebot_initialpose_node");

  ros::NodeHandle n;

  geometry_msgs::PoseWithCovarianceStamped initialpose;
  ros::Publisher publisher_initialpose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1000);

  ros::Duration(1.0).sleep();

  initialpose.header.frame_id = "map";
  initialpose.pose.pose.position.x = -1.9500001668930054;
  initialpose.pose.pose.position.y = -0.599999725818634;
  initialpose.pose.pose.orientation.z = -0.017848642807716874;
  initialpose.pose.pose.orientation.w = 0.999840700286762;
  initialpose.pose.covariance = {
    0.25, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.25, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.06853892326654787
  };

  publisher_initialpose.publish(initialpose);

  ros::spinOnce();
  ros::Duration(1.0).sleep();

  return 0;
}
