#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct Data {
    unsigned long long memTotal;
    unsigned long long memAva;
};

struct Data memUsageCal(){
    struct Data data;

    // read the file /proc/meminfo
    FILE* fptr;
    fptr = fopen("/proc/meminfo", "r");
    char buff[100];

    if(fptr == NULL){
        printf("Can't read the file\n");
        exit(1);
    }
    else{
        printf("the file was opened successfully\n");

        while (fgets(buff,sizeof(buff),fptr)){
            if(strncmp(buff,"MemTotal:", 9) == 0){
                sscanf(buff,"MemTotal: %llu kB",&data.memTotal);
            };
            if(strncmp(buff,"MemAvailable:", 12) == 0){
                sscanf(buff,"MemAvailable: %llu kB",&data.memAva);
            };

            if(data.memTotal && data.memAva) break;
        }
        
        printf("MemTotal : %llu\n", data.memTotal);
        printf("MemAvil %llu\n", data.memAva);
    }

    fclose(fptr);

    return data;
}

void memUsage(){
    // print the mem usage
    
        memUsageCal();
    
}

void main(){
    memUsage();
}