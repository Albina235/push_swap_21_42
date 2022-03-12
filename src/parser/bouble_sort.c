#include "../push_swap.h"

void    bouble_sort(t_all *all, int *sort, int *org, int len)
{
	int	i;
	int	j;
	int	c;

    i = 0;
	while (i < len - 1)
	{
		j = len - 2;
		while (j >= i)
		{
			if (sort[j] > sort[j + 1])
			{
				c = sort[j];
				sort[j] = sort[j + 1];
				sort[j + 1] = c;
			}
			j--;
		}
		i++;
	}
    create_stack(all, sort, org, len);
}