
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int *a = (int*)malloc(sizeof(int));
	int *b = (int*)malloc(sizeof(int));
	int *c = (int*)malloc(sizeof(int));
	int *d = (int*)malloc(sizeof(int));
	int *e = (int*)malloc(sizeof(int));
	int *f = (int*)malloc(sizeof(int));
	int *g = (int*)malloc(sizeof(int));
	int *h = (int*)malloc(sizeof(int));
	int *i = (int*)malloc(sizeof(int));

	*a = 7;

    printf("a : %i", (*a));

	sleep(1);
	system("leaks tester");


	return (0);
}
