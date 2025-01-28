Полудуплексный канал связи для обмена информацией между процессами.
 Простейший предмет, когда связываются потоки вывода и ввода двух команд `shell` идущих друг за другом.
 Важная, а наверно - главная особенность `pipe` в том, что это реально связь между двумя источниками. т.е. если вздумалось насоздавать процессов и потом главным процессом с помощью пайпов получать от них информацию - придется для каждой пары создавать свой `pipe`
 
 ```c
 #include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <stdlib.h>
#include <sys/wait.h>

#define PING "ping"


int main(void)
{
	printf("create process with id =%d\n\n", getpid());

	pid_t pid;

	for(int i = 0; i < 3; i++)
	{
		int fd[2];
		pipe(fd);

		if ( (pid = fork()) == 0)
		{
			printf("{%d} [%d] -> [%d]\n", i, getppid(), getpid());

			char to_out[80];
			sprintf(to_out, "%s from %d \n", PING, getpid());
			
			close(fd[0]);

			write(fd[1], to_out, strlen(to_out));
			exit(0);
		}
#if 1
		else
		{
			int statloc = 0;
			waitpid(pid, &statloc, 0);

			close(fd[1]);

			char from_child[30];
			read(fd[0], &from_child, 30);

			printf("{%d} [%d] <- [%d] :%s\n",i, getpid(), pid, from_child);
		}
#endif
	}
	return 0;
}
```

В отличие от [`FIFO`]([[FIFO]]) `pipe` должны состоять в родстве и `pipe` должен быть вызван до `fork` чтобы быть унаследован ( или будет не доступен, просле того как был закрыт). 