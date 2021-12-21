#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

SYSCALL_DEFINE2(saiprint,
                char __user *, src,
                int, length)
{
        char buf[256];
        unsigned long len = length;
        unsigned long chunklen = sizeof(buf);
        while( len > 0 ){
                if(len < chunklen ) chunklen =length;
                if( copy_from_user(buf, src, chunklen) ){
                return -EFAULT;
        }
                len -= chunklen;
        }

        printk("%s\n", buffer);

        return 0;
}