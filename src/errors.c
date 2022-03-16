#include "push_swap.h"

void	error(void)
{
	write(2, "error\n", 6);
	exit(EXIT_SUCCESS);
}

void    free_array(char **arr, int f)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	if (f == -1)
		error();
}

void	free_stack(t_all *all)
{
	t_one	*tmp;

	while (all->len_a--)
	{
		tmp = all->a->next;
		free(all->a);
		all->a = NULL;
		all->a = tmp;
	}
	while (all->len_b--)
	{
		tmp = all->b->next;
		free(all->b);
		all->b = NULL;
		all->b = tmp;
	}
	free(all);
	exit(0);
}
