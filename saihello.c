#include<linux/syscalls.h>
#include<linux/kernel.h>

SYSCALL_DEFINE0(saihello)
{
    printk("Hello, I am Sai Teja \n");
    return 0;
}