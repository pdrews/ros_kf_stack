#include "ros/ros.h"
#include <sstream>
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Twist.h"
#include "visualization_msgs/MarkerArray.h"

class MotorSimul {
public:
  MotorSimul();
  void twistCallback(const geometry_msgs::Twist::ConstPtr& msg);

protected:
  ros::NodeHandle n;

  visualization_msgs::MarkerArray markers;

  ros::Subscriber twistSub;
  ros::Publisher pubMotorMarkers;
};

MotorSimul::MotorSimul() {

  for (int i=0;i<2;i++) {
    visualization_msgs::Marker marker = visualization_msgs::Marker();
    marker.ns = "MotorSimul";
    marker.header.frame_id = "/kingfisher/base";
    marker.header.stamp = ros::Time::now();
    marker.id = i;
    marker.type = marker.ARROW;
    marker.action = marker.ADD;
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.5;
    marker.pose.position.x = 0.0;
    marker.pose.position.y = i - 0.5;
    marker.pose.position.z = 0.0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.color.a = 1.0;
    marker.color.r = 1.0;
    marker.color.g = 0.75;
    marker.color.b = 0.14;
    markers.markers.push_back(marker);
  }

  twistSub = n.subscribe("/motor/twist",1,&MotorSimul::twistCallback,this);
  pubMotorMarkers = n.advertise<visualization_msgs::MarkerArray>("/motornode/markers",1);

}

void MotorSimul::twistCallback(const geometry_msgs::Twist::ConstPtr& msg) {

  float linear_x = msg->linear.x;
  float angular_z = msg->angular.z;
  float radius = 0.5;

  markers.markers[0].scale.z = 5 * (linear_x - radius*angular_z);
  markers.markers[1].scale.z = 5 * (linear_x + radius*angular_z);
  if (fabs(markers.markers[0].scale.z)<0.01) {
    markers.markers[0].scale.z = 0.01;
  }
  if (fabs(markers.markers[1].scale.z)<0.01) {
    markers.markers[1].scale.z = 0.01;
  }

  ROS_INFO("left %.3f - right %.3f",markers.markers[0].scale.z,markers.markers[1].scale.z);

  pubMotorMarkers.publish(markers);

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "motornode");
  MotorSimul motorsimul;

  ros::spin();
}

