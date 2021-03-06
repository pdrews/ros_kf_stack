#!/usr/bin/python
# ROS specific imports
import roslib; roslib.load_manifest('sim_tasks')
import rospy
from math import *
from task_manager_lib.TaskClient import *

rospy.init_node('task_client')
server_node = rospy.get_param("~server","/task_server")
default_period = rospy.get_param("~period",0.2)
tc = TaskClient(server_node,default_period)

#tc.WaitForAuto()
try:
    #tc.FindFinishLine(angle=1.57)
    tc.Wait(duration=5.00)
    #tc.JoinOtherShore()
    #tc.FindFinishLine(angle=1.57)
    #tc.FollowShore(angle=1.57)
    #tc.JoinOtherShore()

except TaskException, e:
    rospy.logerr("Exception caught: " + str(e))


rospy.loginfo("Mission completed")


