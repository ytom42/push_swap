#include "push_swap.h"
#include <curses.h>

void	print_stack(t_stacks *s)
{
	int	i;
	
	printf("========\n");
	i = 1;
	while (i <= s->b_top)
	{
		printf("[%d] %d", i, s->b[i].n);
		printf("\n");
		i++;
	}
	printf("===b==== top[%d]\n", s->b_top);
	printf("===a==== top[%d]\n", s->a_top);
	i = s->a_top;
	while (i > 0)
	{
		printf("[%d] %d", i, s->a[i].n);
		printf("\n");
		i--;
	}
	printf("========\n");
	getchar();
	system("clear");
}
