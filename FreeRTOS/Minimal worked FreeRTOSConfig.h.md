Постарался собрать заголовочный для запуска с минимальной функциональностью, зато с минимумом кода
```c
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* Here is a good place to include header files that are required across your application. */
/* #include "something.h" */

// sheduler type
#define configUSE_PREEMPTION                    1

// choice method of task switching ( port or software )
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0

// use "low powe tickless mode" 
#define configUSE_TICKLESS_IDLE                 0

/* This value is required in order to correctly configure timer peripherals */
#define configCPU_CLOCK_HZ                      8000000

/* set CPU clock (for ARM Cortex-M only) 
if there is SysTick let stay it undefined */
#define configSYSTICK_CLOCK_HZ                  800000

/* The frequency of the RTOS tick interrupt. Used to measure time.
High value it is default */
#define configTICK_RATE_HZ                      1000 

/* the number of priorities available to the task */
#define configMAX_PRIORITIES                    15

/* use hook (callBack) function on during tick Interrupt */
#define configUSE_IDLE_HOOK                     0

/* The size of the stack used by the idle task!!!
It is specified in words (32 bit ) */
#define configMINIMAL_STACK_SIZE                128 

/* Max permission len of task's name ( including NULL-terminator ) */
#define configMAX_TASK_NAME_LEN                 16

/* set for 8,16-bit architecture*/
#define configUSE_16_BIT_TICKS                  0

/* This parameter controls the behaviour of tasks at the idle priority. */
#define configIDLE_SHOULD_YIELD                 0

/* switch on/off "direct task notification" */
#define configUSE_TASK_NOTIFICATIONS            0

/* number of index into notifications array */
#define configTASK_NOTIFICATION_ARRAY_ENTRIES   1

/* exclude Mutex functionality */
#define configUSE_MUTEXES                       0

/* exclude Recursive mutex */
#define configUSE_RECURSIVE_MUTEXES             0

/* exclude semaphore functionality */
#define configUSE_COUNTING_SEMAPHORES           0

/* exclude using alternative queue function in build
DEPRICACTED*/
#define configUSE_ALTERNATIVE_API               0

/* exclude stack overflow check */
#define configCHECK_FOR_STACK_OVERFLOW          0

/* debug purpose only */
#define configQUEUE_REGISTRY_SIZE               10

/* exclude queue set functionality */
#define configUSE_QUEUE_SETS                    0

/* don't switch between task with equal priority */
#define configUSE_TIME_SLICING                  0

/* don't use "newlib" */
#define configUSE_NEWLIB_REENTRANT              0

/* without backward compatibility */
#define configENABLE_BACKWARD_COMPATIBILITY     0


#endif /* FREERTOS_CONFIG_H */                  
```