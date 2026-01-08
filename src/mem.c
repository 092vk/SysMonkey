#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct DataM {
    unsigned long long memTotal;
    unsigned long long memAva;
};

struct DataM memUsageCal(){
    struct DataM data;

    // read the file /proc/meminfo
    FILE* fptr;
    fptr = fopen("/proc/meminfo", "r");
    char buff[100];

    if(fptr == NULL){
        printf("Can't read the file\n");
        exit(1);
    }
    else{
        // printf("the file was opened successfully\n");

        while (fgets(buff,sizeof(buff),fptr)){
            if(strncmp(buff,"MemTotal:", 9) == 0){
                sscanf(buff,"MemTotal: %llu kB",&data.memTotal);
            };
            if(strncmp(buff,"MemAvailable:", 12) == 0){
                sscanf(buff,"MemAvailable: %llu kB",&data.memAva);
            };

            if(data.memTotal && data.memAva) break;
        }
        
        // printf("MemTotal : %llu\n", data.memTotal);
        // printf("MemAvil %llu\n", data.memAva);
    }

    fclose(fptr);

    return data;
}

double memUsage(){
    struct DataM d1 = memUsageCal();
    //calculation for percentage
    double percentMem = 100*(1-(double)d1.memAva/(double)d1.memTotal);
    // printf("\nPercentage memeory used : %0.2lf%% \n",percentMem);
    return percentMem;
}