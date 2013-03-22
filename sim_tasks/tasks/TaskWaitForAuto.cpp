#include <math.h>
#include "TaskWaitForAuto.h"
#include "sim_tasks/TaskWaitForAutoConfig.h"
using namespace task_manager_msgs;
using namespace task_manager_lib;
using namespace sim_tasks;

TaskWaitForAuto::TaskWaitForAuto(boost::shared_ptr<TaskEnvironment> tenv) 
    : TaskDefinitionWithConfig<TaskWaitForAutoConfig,TaskWaitForAuto>("WaitForAuto","Wait for the control mux to switch to auto",true,-1.)
{
    env = boost::dynamic_pointer_cast<SimTasksEnv,TaskEnvironment>(tenv);
}

TaskIndicator TaskWaitForAuto::iterate()
{
    if (!env->getManualControl()) {
		return TaskStatus::TASK_COMPLETED;
    }
	return TaskStatus::TASK_RUNNING;
}

TaskIndicator TaskWaitForAuto::terminate()
{
	return TaskStatus::TASK_TERMINATED;
}

DYNAMIC_TASK(TaskWaitForAuto);