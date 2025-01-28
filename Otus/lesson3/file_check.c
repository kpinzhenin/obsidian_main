#include <stdio.h>

int main(void)
{
	FILE *iofile = NULL;
	int read_count = 0;
	char c;

	// try open the file
	iofile = fopen("file_1.txt", "rb"); // binary read

	if (iofile != NULL)
	{
		//while(fread(&c, sizeof(c), 1, iofile))
		while(!feof(iofile))
		{
			printf("0x%x\n", getc(iofile));
		}

	}
	else
		printf("some thenig wrong \n");
	printf("->%x", EOF);
	fclose(iofile);	
	return 0;
}
