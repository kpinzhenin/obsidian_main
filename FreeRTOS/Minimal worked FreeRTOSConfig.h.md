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

/* Count of Thread Local Storage, like global var */
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 5

/* for some optimisation use some marker of start and end of modes marker int FreeRTOS  */
#define configUSE_MINI_LIST_ITEM                1

/* set type for specify the stack depth */
#define configSTACK_DEPTH_TYPE                  uint16_t

/* default value is "size_t". if message's len shortly then 255 
it can be specify by uint8_t*/
#define configMESSAGE_BUFFER_LENGTH_TYPE        size_t

/* blocks of memory, allocated by pvPortMalloc() will be cleared when usnig vPortFree(). Recomended to set 1 */
#define configHEAP_CLEAR_MEMORY_ON_FREE         1

/* for simple not use. is set to 1 then RTOS objects can be created using RAM provided by the application writer. */
#define configSUPPORT_STATIC_ALLOCATION         0

/* set to 1 then RTOS objects can be created using RAM that is automatically allocated from the FreeRTOS heap */
#define configSUPPORT_DYNAMIC_ALLOCATION        1

/* total amount of RAM available in the FreeRTOS heap.
Only used for dynamic allocation. in byte ? */
#define configTOTAL_HEAP_SIZE                   (size_t) (512 * 18)

/* heap placed by FreeRTOS  */
#define configAPPLICATION_ALLOCATED_HEAP        0

/* don't need to realize pvPortMallocStack() and vPortFreeStack()*/
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP 0

/* HOOK FUNCTION RELATED DEFINITIONS */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCHECK_FOR_STACK_OVERFLOW          0
#define configUSE_MALLOC_FAILED_HOOK            0
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0
#define configUSE_SB_COMPLETED_CALLBACK         0

/* not generate RUN time statistic */
#define configGENERATE_RUN_TIME_STATS           0
#define configUSE_TRACE_FACILITY                0
#define configUSE_STATS_FORMATTING_FUNCTIONS    0 

/* don't use co-routine */
#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         1

/* don't use software timers */
#define configUSE_TIMERS                        0
#define configTIMER_TASK_PRIORITY               3
#define configTIMER_QUEUE_LENGTH                ( configMINIMAL_STACK_SIZE * 2 )

/* Interrupt priorities used by the kernel port layer itself. These are genericto all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Normal assert() semantics without relying on the provision of an assert.h header file. */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }


/* Set the following definitions to 1 to include the API function, or zero 
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet 1
#define INCLUDE_uxTaskPriorityGet 1
#define INCLUDE_vTaskDelete 1
#define INCLUDE_vTaskCleanUpResources 1
#define INCLUDE_vTaskSuspend 1
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 1

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */                  
```