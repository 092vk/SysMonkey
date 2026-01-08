# SysMonkey

![sysMonkey](/public/sysMonkey.png)

SysMonkey is a gui-based system monitoring application designed specifically for heterogeneous computing boards that combine the CPU with FPGA. The tool provides real-time visibility into both the general-purpose SoC CPU and the onboard FPGA accelerator, giving developers a unified view of hardware utilization.

The application continuously samples CPU usage, memory consumption, temperature, and power metrics directly from Linux system interfaces, while also interfacing with custom FPGA counters to measure accelerator activity, data throughput, and workload runtime. Results are displayed through an intuitive GUI featuring live charts, gauges, and logs.

Built for engineers, students, and researchers working on SOCs like Vicharak platforms, the Sys Monkey bridges the gap between software execution and hardware processing, making it easy to profile applications, optimize performance, and debug accelerator workloads.

