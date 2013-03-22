#include <math.h>
#include "TaskJoinOtherShore.h"
#include "sim_tasks/TaskJoinOtherShoreConfig.h"
using namespace task_manager_msgs;
using namespace task_manager_lib;
using namespace sim_tasks;

#define DEBUG_GOTO

TaskJoinOtherShore::TaskJoinOtherShore(boost::shared_ptr<TaskEnvironment> tenv) 
    : TaskDefinitionWithConfig<TaskJoinOtherShoreConfig,TaskJoinOtherShore>("JoinOtherShore","Rotate and join the other shore",true,-1.)
{
    env = boost::dynamic_pointer_cast<SimTasksEnv,TaskEnvironment>(tenv);
}

TaskIndicator TaskJoinOtherShore::iterate()
{
    const geometry_msgs::Pose2D & tpose = env->getPose2D();
    const geometry_msgs::Pose2D & finishLine = env->getFinishLine2D();

    double scalarProduct = cos(finishLine.theta)*(finishLine.x-tpose.x)+sin(finishLine.theta)*(finishLine.y-tpose.y);
    double r = hypot(finishLine.y-tpose.y,finishLine.x-tpose.x);

    float angle_error = remainder(1.57 + finishLine.theta - tpose.theta,2*M_PI);

#ifdef DEBUG_GOTO
    ROS_INFO("scalarProduct %.3f - dist_goal %.3f - angle_error %.3f\n",scalarProduct,r,angle_error);
#endif
    
    const pcl::PointCloud<pcl::PointXYZ> & pointCloud = env->getPointCloud();

    double vel = cfg.velocity;
    double rot = 0;

    float mindistance=1000;
    float distance_i=0;
    float theta_i=0;

    for (unsigned int i=0;i<pointCloud.size();i++) {
        theta_i=atan2(pointCloud[i].y,pointCloud[i].x);
        if (fabs(theta_i) < cfg.angle_range) {
            distance_i=hypot(pointCloud[i].y,pointCloud[i].x);
            if ((distance_i < mindistance)&&(distance_i > 0.01)) {
	            mindistance=distance_i;
            }
        }
    }

#ifdef DEBUG_GOTO
    ROS_INFO("mindistance %.3f",mindistance);
#endif
    
    if ((r > 5) && (mindistance < cfg.distance)) {
        return TaskStatus::TASK_COMPLETED;
    }
    else {
        rot = cfg.k_scal_prod * scalarProduct - cfg.k_alpha * angle_error;
        if (fabs(angle_error) > cfg.angle_error_max) {angle_error = ((angle_error>0)?+1:-1)*cfg.angle_error_max;}
        vel = exp(-pow(angle_error,2)/2);
    }

#ifdef DEBUG_GOTO
    ROS_INFO("Command vel %.2f rot %.2f\n",vel,rot);
#endif

    env->publishVelocity(vel, rot);
	return TaskStatus::TASK_RUNNING;
}

TaskIndicator TaskJoinOtherShore::terminate()
{
    env->publishVelocity(0,0);
	return TaskStatus::TASK_TERMINATED;
}

DYNAMIC_TASK(TaskJoinOtherShore);
