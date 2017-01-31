#include <linux/init.h>
#include <linux/module.h>

static int __init
ks_init(void)
{
	printk("ks_init\n");
	printk(KERN_NOTICE "ks_init 2\n");
	return	0;
}
module_init(ks_init);

static void __exit
ks_exit(void)
{
	printk("ks_exit\n");
	// printk(KERN_WARNING "ks_exit 2\n");
}
module_exit(ks_exit);

MODULE_DESCRIPTION("Dummy module for testing");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Song");
MODULE_VERSION("ks_module");
