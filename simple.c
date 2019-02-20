#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");

       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

/*

iqbal@iqbal-F17 ~ $ nano 
iqbal@iqbal-F17 ~ $ nano 
iqbal@iqbal-F17 ~ $ nano simple.c
iqbal@iqbal-F17 ~ $ make
make -C /lib/modules/4.10.0-33-generic/build M=/home/iqbal modules
make[1]: Entering directory '/usr/src/linux-headers-4.10.0-33-generic'
  CC [M]  /home/iqbal/simple.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/iqbal/simple.mod.o
  LD [M]  /home/iqbal/simple.ko
make[1]: Leaving directory '/usr/src/linux-headers-4.10.0-33-generic'
iqbal@iqbal-F17 ~ $ 

*/