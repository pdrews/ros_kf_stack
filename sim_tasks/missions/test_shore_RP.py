#!/usr/bin/python
# ROS specific imports
import roslib; roslib.load_manifest('sim_tasks')
import rospy
from math import *
from task_manager_lib.TaskClient import *

rospy.init_node('task_client')
server_node = rospy.get_param("~server","/task_server")
default_period = rospy.get_param("~period",0.05)
tc = TaskClient(server_node,default_period)
rospy.loginfo("Mission connected to server: " + server_node)

tc.WaitForAuto()
tc.AlignWithShore(angle=1.57, ang_velocity=1.5)
tc.FollowShoreRP(velocity=0.5, distance=4.0, side=+1, k_alpha=1.0)

if not rospy.core.is_shutdown():
    tc.SetManual()

rospy.loginfo("Mission completed")

