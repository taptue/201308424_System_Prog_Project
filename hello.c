/*
* @file		hello.c
* @author	Taptue Cesar
* @date		11 September 2016
* @version 0.1
*/

#include <linux/init.h>		//Macros used to make up functions e.g. __init
#include <linux/module.h>	//Core header for loading LKMs into the kernel
#include <linux/kernel.h>	//Contains types, macros, functions for the ker


/*
*hello_init - the init function, called when the module is loaded.
*Returnd zero if successfully loaded, nonzero otherwise
*/

static char *name = "world";
module_param(name, charp, S_IRUGO);	
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

static int __init helloBBB_init(void)
{
	printk(KERN_INFO "EBB: Hello %s from the BBB LKM!\n", name);
	return 0;
}

/*
*hello_exit - the exit function, called when the module is removed.
*/
static void __exit helloBBB_exit(void)
{
	printk(KERN_INFO "EBB: Goodbye %s from the BBB LKM!\n", name);
}

module_init(helloBBB_init);
module_exit(helloBBB_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Taptue");
MODULE_DESCRIPTION("A Hello, World Module");
MODULE_VERSION("0.1");
