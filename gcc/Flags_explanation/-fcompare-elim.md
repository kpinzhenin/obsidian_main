**устраняет избыточные сравнения** после условных операций, если результат сравнения можно вывести из уже выполненных проверок.
```c
int foo(int a, int b) {
    if (a > b) {
        return 1;
    } else {
        return 0;
    }
}
```
сформируется ассемблерный код:
```asm
foo:
    cmp     edi, esi
    jg      .Ltrue
    xor     eax, eax    ; return 0
    ret
.Ltrue:
    mov     eax, 1      ; return 1
    ret
```
оптимизированный с использованием флага:
```
foo:
    xor     eax, eax    ; сразу предполагаем return 0
    cmp     edi, esi
    setg    al          ; если a > b, то al = 1 (иначе остаётся 0)
    ret
```