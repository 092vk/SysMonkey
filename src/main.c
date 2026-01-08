#include<stdio.h>

#include "cpu.c"
#include "mem.c"
// #include "ui.c"


int main(int argc , char *argv[]){
    //combine loop
    struct Data d1 = cpuUsageCal();
    while(1){
        sleep(1);
        struct Data d2 = cpuUsageCal();
        // calculate the diff
        unsigned long long sum_delta = d2.Ssum - d1.Ssum;
        unsigned long long idle_delta = d2.Sidle - d1.Sidle;
        // printf("sum_delta : %llu\n", sum_delta);
        // printf("idle_delta : %llu\n", idle_delta);

        // calculate the cpu usage
        double cpu_usage = (1- (double)idle_delta/(double)sum_delta)*100;
        // printf("Cpu_usage = %0.1lf%%\n", cpu_usage);

        //replace d1 with d2 to avoid recalculation
        d1 = d2;

        //calculate the mem usage
        double memUsagePercent = memUsage();

        // formatting for proper display
        printf("\033[H\033[J");
        printf("====================================\n");
        printf("\n******* SysMonkey *******\n");
        printf("\nCPU_USAGE : %lf %% \n",cpu_usage);
        printf("\nMEM_USAGE : %lf %% \n",memUsagePercent);
        fflush(stdout);

    }
    return 0;
}

