#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

static int process_init(void){
  struct task_struct *task;
  for_each_process(task){
    printk(KERN_ALERT "%s [%d] state: %d\n",
		task->comm,task->pid,task->state);
  }

  return 0;
}

static void process_exit(void){
  printk(KERN_INFO "Exit from module...\n");
}

module_init(process_init);
module_exit(process_exit);

