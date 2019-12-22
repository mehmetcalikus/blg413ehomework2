#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>

asmlinkage long sys_set_nice_inc(pid_t pid, int value){
	
	int retError = 0;
	struct task_struct *current;

	if(value > 0){
		/* error code -1: value negative */
		retError = -1;	
	}
	else
	{	
		current =  get_pid_task(pid, 0);
		current->nice_value = new_nice_value;
		/* error code 0: value non-negative */
		retError = 0;
	}
	
	return retError;
}
