#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlebot_goal_node");

  ros::NodeHandle n;

  geometry_msgs::PoseStamped move_base_simple_goal;
  ros::Publisher publisher_initialpose = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);

  ros::Duration(1.0).sleep();

  move_base_simple_goal.header.frame_id = "map";
  move_base_simple_goal.pose.position.x = 1.8000001907348633;
  move_base_simple_goal.pose.position.y = 0.7999997735023499;
  move_base_simple_goal.pose.orientation.z = 0.7071067966408575;
  move_base_simple_goal.pose.orientation.w = 0.7071067657322372;
  publisher_initialpose.publish(move_base_simple_goal);

  ros::spinOnce();
  ros::Duration(1.0).sleep();

  return 0;
}
