#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// functions to open and calculate the sum and idle
struct Data {
    unsigned long long Ssum;
    unsigned long long Sidle;
};

struct Data cpuUsageCal(){
    struct Data data;

    //open the file and read the values from the first line
    FILE* fptr;
    fptr = fopen("/proc/stat","r");

    char buff[100];
    unsigned long long user, nice , system, idle , iowait, irq, softirq, steal, guest, guest_nice;

    if(fptr == NULL){
        printf("File was not opened\n");
        exit(1);
    }else {
        // printf("The file was opened successfully\n");
        fgets(buff,sizeof(buff),fptr);

        int items_got = sscanf(buff, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",&user,&nice,&system,&idle,&iowait,&irq,&softirq,&steal,&guest,&guest_nice);

        // printf("Items got %d \n",items_got);
        // printf("Got \nuser = %llu, nice = %llu, system = %llu, idle = %llu , iowait = %llu, irq = %llu, softirq= %llu, steal= %llu, guest= %llu, guest_nice= %llu",user,nice,system,idle , iowait, irq, softirq, steal, guest, guest_nice);
        // printf("\n");

        unsigned long long sumRead;
        unsigned long long idleRead;
        sumRead = user+nice+system+idle+iowait+irq+softirq+steal+guest+guest_nice;
        idleRead = idle;

        // printf("Sum= %llu \n",sumRead);
        // printf("Idle= %llu",idle);

        data.Ssum = sumRead;
        data.Sidle= idle;

        //close the file connection
        fclose(fptr);
    }

    return data;
}
