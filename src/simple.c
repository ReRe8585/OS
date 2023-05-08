#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/param.h> 
#include <linux/jiffies.h> 


static int simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");
    printk(KERN_INFO "init_jiffies: %lu\n", jiffies);
    printk(KERN_INFO "HZ: %d\n", HZ);    
    return 0;
}

// 當模組被移除會觸發這個函式 無返回值
static void simple_exit(void) {
    
    printk(KERN_INFO "exit_jiffies: %lu\n", jiffies);
    printk(KERN_INFO "Removing Module\n");
}

module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("NOBODY");

