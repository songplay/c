#include <linux/init.h>
#include <linux/module.h>


static int  __init
ks4_init(void)
{
	printk("ks4_init");
	return	0;
}

module_init(ks4_init);

static void __exit
ks4_exit(void)
{
	printk("ks4_exit\n");
}

module_exit(ks4_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin");
MODULE_DESCRIPTION("ks4:test");
