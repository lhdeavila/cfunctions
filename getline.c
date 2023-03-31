/*
	implementacion getline
	personalizada
*/
#include <stdio.h>

int custom_getline(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}