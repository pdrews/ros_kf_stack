#include <math.h>
#include "TaskWaitForAuto.h"
#include "sim_tasks/TaskWaitForAutoConfig.h"
using namespace task_manager_msgs;
using namespace task_manager_lib;
using namespace sim_tasks;

TaskIndicator TaskWaitForAuto::initialise(const TaskParameters & parameters) 
{
    TaskIndicator ti = Parent::initialise(parameters);
    if (ti != TaskStatus::TASK_INITIALISED) {
        return ti;
    }
    ROS_INFO("Waiting for automatic control. Switch RC controller off and press the red button.");
    return ti;
}


TaskIndicator TaskWaitForAuto::iterate()
{
    if (!env->getManualControl()) {
        ROS_INFO("Automatic control detected. We are free!");
		return TaskStatus::TASK_COMPLETED;
    }
	return TaskStatus::TASK_RUNNING;
}

TaskIndicator TaskWaitForAuto::terminate()
{
	return TaskStatus::TASK_TERMINATED;
}

DYNAMIC_TASK(TaskFactoryWaitForAuto);
