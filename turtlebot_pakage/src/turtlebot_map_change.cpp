#include <ros/ros.h>
#include "nav_msgs/LoadMap.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlebot_map_change_node");
  ros::NodeHandle n;

  ros::ServiceClient service_client_change_map;
  service_client_change_map = n.serviceClient<nav_msgs::LoadMap>("/change_map");

  nav_msgs::LoadMap change_map;

  change_map.request.map_url = std::string(getenv("HOME")) + "/map.yaml";

  service_client_change_map.call(change_map);

  return 0;

}
