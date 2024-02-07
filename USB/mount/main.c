#include <stdio.h>
#include <sys/mount.h>
#include <errno.h>
#include <string.h>

int main() {
    char sda1[] = "/dev/sda1";
    char mount_point[] = "/media/pendrive";
    
    if (mount(sda1, mount_point, "exfat", MS_ACTIVE, NULL)) {
        if (errno == EBUSY) {
            printf("Mountpoint busy\n");
        } else {
            printf("Mount error: %s\n", strerror(errno));
        }
    } else {
        printf("Mount successful\n");
    }
}