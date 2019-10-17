#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

#define VMCALL(nr, ret) 		\
	__asm volatile("vmcall"		\
		: "=a" (ret)		\
		: "a" (nr));

static int __init
cmpe283_init(void)
{
	uint64_t ret = 0;

	printk(KERN_INFO "CMPE283 module - calling hypercall\n");
	VMCALL(0x283, ret);

	printk(KERN_INFO "CMPE283 module - answer is 0x%llx\n", ret);
	    
	return 0;
}

static void __exit
cmpe283_cleanup(void)
{
	printk(KERN_INFO "CMPE283 module - exiting\n");
}

module_init(cmpe283_init);
module_exit(cmpe283_cleanup);
