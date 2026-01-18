Служит для навигации по потокам. Пока что такой путь видится:
```bash
(gdb) info threads
  Id   Target Id           Frame
* 1    Thread 28852.0x7c68 main () at main.c:14
  2    Thread 28852.0x5570 0x00007ff9cb913d24 in ntdll!ZwWaitForWorkViaWorkerFactory ()
   from C:\Windows\SYSTEM32\ntdll.dll
  3    Thread 28852.0x43e8 0x00007ff9cb913d24 in ntdll!ZwWaitForWorkViaWorkerFactory ()
   from C:\Windows\SYSTEM32\ntdll.dll
  4    Thread 28852.0x3b34 0x00007ff9cb913d24 in ntdll!ZwWaitForWorkViaWorkerFactory ()
   from C:\Windows\SYSTEM32\ntdll.dll
  5    Thread 28852.0x7464 0x00007ff9cb8af141 in ntdll!RtlAllocateHeap ()
   from C:\Windows\SYSTEM32\ntdll.dll
(gdb) threads 5 # switch to thread 5

```