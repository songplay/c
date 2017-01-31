#include <linux/init.h>
#include <linux/module.h>

static int __init
ks2_init(void)
{
	printk("ks2_init\n");
	return	0;
}

static void __exit
ks2_exit(void)
{
	printk("ks2_exit\n");
}

module_init(ks2_init);
module_exit(ks2_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ks2");
MODULE_AUTHOR("Kevin S");
MODULE_VERSION("ks2 v1");
