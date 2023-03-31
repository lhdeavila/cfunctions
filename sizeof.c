#include <stdio.h>
void main(){
	printf("enter the array size: ");
	int array_size;
	fscanf(stdin, "%d", &array_size);
	int var_length_array[array_size];
	printf("sizeof array = %zu\n", sizeof var_length_array);
};