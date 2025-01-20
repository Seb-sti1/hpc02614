```sh
$ nvidia-smi
Mon Jan 20 17:32:08 2025       
+-----------------------------------------------------------------------------------------+
| NVIDIA-SMI 565.57.01              Driver Version: 565.57.01      CUDA Version: 12.7     |
|-----------------------------------------+------------------------+----------------------+
| GPU  Name                 Persistence-M | Bus-Id          Disp.A | Volatile Uncorr. ECC |
| Fan  Temp   Perf          Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute M. |
|                                         |                        |               MIG M. |
|=========================================+========================+======================|
|   0  NVIDIA H100 PCIe               On  |   00000000:41:00.0 Off |                    0 |
| N/A   29C    P0             46W /  350W |       1MiB /  81559MiB |      0%      Default |
|                                         |                        |             Disabled |
+-----------------------------------------+------------------------+----------------------+
|   1  NVIDIA H100 PCIe               On  |   00000000:A1:00.0 Off |                    0 |
| N/A   29C    P0             47W /  350W |       1MiB /  81559MiB |      0%      Default |
|                                         |                        |             Disabled |
+-----------------------------------------+------------------------+----------------------+

+-----------------------------------------------------------------------------------------+
| Processes:                                                                              |
|  GPU   GI   CI        PID   Type   Process name                              GPU Memory |
|        ID   ID                                                               Usage      |
|=========================================================================================|
|  No running processes found                                                             |
+-----------------------------------------------------------------------------------------+
```

```sh
$ nvaccelinfo

CUDA Driver Version:           12070
NVRM version:                  NVIDIA UNIX x86_64 Kernel Module  565.57.01  Thu Oct 10 12:29:05 UTC 2024

Device Number:                 0
Device Name:                   NVIDIA H100 PCIe
Device Revision Number:        9.0
Global Memory Size:            85045477376
Number of Multiprocessors:     114
Concurrent Copy and Execution: Yes
Total Constant Memory:         65536
Total Shared Memory per Block: 49152
Registers per Block:           65536
Warp Size:                     32
Maximum Threads per Block:     1024
Maximum Block Dimensions:      1024, 1024, 64
Maximum Grid Dimensions:       2147483647 x 65535 x 65535
Maximum Memory Pitch:          2147483647B
Texture Alignment:             512B
Clock Rate:                    1755 MHz
Execution Timeout:             No
Integrated Device:             No
Can Map Host Memory:           Yes
Compute Mode:                  default
Concurrent Kernels:            Yes
ECC Enabled:                   Yes
Memory Clock Rate:             1593 MHz
Memory Bus Width:              5120 bits
L2 Cache Size:                 52428800 bytes
Max Threads Per SMP:           2048
Async Engines:                 3
Unified Addressing:            Yes
Managed Memory:                Yes
Concurrent Managed Memory:     Yes
Preemption Supported:          Yes
Cooperative Launch:            Yes
Cluster Launch:                Yes
Unified Function Pointers:     Yes
Unified Memory:                No
Memory Models Flags:           -gpu=mem:separate, -gpu=mem:managed
Default Target:                cc90
```

```
./cudaDeviceQuery 
Device 0: "NVIDIA H100 PCIe".
  Multiprocessors: 114
  Peak Memory Bandwidth (GB/s): 2039.040000
  Maximum number of threads per block: 1024.
```