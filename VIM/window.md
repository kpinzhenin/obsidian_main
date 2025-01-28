more detail info will be get by
```c
:help windows

```
All CTRL-W commands can also be executed with 
```c
	Ctrl-w 
	//also might be use 
	Ctrl-w-h/j/k/l // for move to down/right/left/dawn
	:wincmd
	
	Ctrl-w-r // moving focus around
```
разбить окно можно на этапе запуска Vim используя аргумент 
```c
	-o // для горизонтального разделения
	-O // для вертикального разделения
	-oN// где N количество горизонтально разделенных окон при открытии
```

### Cоздание/закрытие нового окна в уже открытом файле
с помощью командной строки
```c
	[N]vs[plit] // vertical split
	[N]s[plit] // horizpntal split
	
	Ctrl-w // move to another window
	
	:q // close the current window
	:clo[se] // the same closing window
	
	:hid[e] // hide current window
```

с помощью горячих клавиш:
```c
	Ctrl-w-s Ctrl-w Ctrl-s - horizontal split window
	Ctrl-w-v Ctrl-w Ctrl-v - vertical split window
	
	Ctrl-w-o Ctrl-w Ctrl-o - Onl current window state open, other will close
	Ctrl-w-q Ctrl-w Ctrl-q - quit current window
	Ctrl-w-c Ctrl-w Ctrl-c - close current window
```

 помощью командной строки с выполнением конмады:
```c
	 :vert[ical] {cmd}
	 
	:hor[izontal] {cmd}
	 
	:lefta[bove] {cmd}                            :lefta :leftabove
	:abo[veleft] {cmd}                              :abo :aboveleft
	 
	:rightb[elow] {cmd}                          :rightb :rightbelow
	:bel[owright] {cmd}                             :bel :belowright
	:to[pleft] {cmd}
	
	:bo[tright] {cmd}

```
### Изменение размеров открытого окна
```c
:res[ize] n - set current size of height current window
:res[ize] +/-n - increase/decrease size of height to n

Ctrl-w-= - reisze to same split window size
```