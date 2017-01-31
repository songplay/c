#include <linux/module.h>

static int __init
ks_init(void)
{
	printk("ks+init\n");
	return	0;
}
module_init(ks_init);

static void __exit
ks_exit(void)
{
	printk("ks_exit\n");
}

module_exit(ks_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin");
MODULE_DESCRIPTION("Kevin's test module");
MODULE_VERSION("v0.1");

