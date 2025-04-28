порядок реализации для статического выделения памяти
 - `vApplicationGetTimerTaskMemory()` рекомендуется в ней производить выделение памяти. При этом должен быть выставлен `configSUPPORT_STATIC_ALLOCATION` и `configUSE_TIMERS`
 - `configSUPPORT_STATIC_ALLOCATION  1` в *FreeRTOSconfig.h* отвечает за настройку выделения памяти.