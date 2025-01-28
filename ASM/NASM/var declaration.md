Объявление переменных происходит в секции .data
```c
section    .data
empty_str: db 0x0 ;;; data byte
dword_: dw 0x1234 ;;; 0x32 0x12 2x byte
letter_in_dword: dw 'a' ;;; 0x61 0x0 filling do dword

quad_data: dd 0x12345678 ; 0x78 0x56 0x34 0x12

```

$ символ указывает на текущее значение памяти данных либо инструкций, например:
```c
section .data
some_data: dd 2,3,4,5
data_lenght: ($ - data) / 4
```