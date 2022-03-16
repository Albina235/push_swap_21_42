#include	"push_swap.h"

static void	get_func(t_all *all, char *line)
{
	if (!ft_strncmp(line, "pa", 3))
		pa(all, 0);
	else if	(!ft_strncmp(line, "pb", 3))
		pb(all, 0);
	else if	(!ft_strncmp(line, "sa", 3))
		sa(all, 0);
	else if	(!ft_strncmp(line, "sb", 3))
		sb(all, 0);
	else if	(!ft_strncmp(line, "ss", 3))
		ss(all, 0);
	else if	(!ft_strncmp(line, "ra", 3))
		ra(all, 0);
	else if	(!ft_strncmp(line, "rb", 3))
		rb(all, 0);
	else if	(!ft_strncmp(line, "rr", 3))
		rr(all, 0);
	else if	(!ft_strncmp(line, "rra", 3))
		rra(all, 0);
	else if	(!ft_strncmp(line, "rrb", 3))
		rrb(all, 0);
	else if	(!ft_strncmp(line, "rrr", 3))
		rrr(all, 0);
	else
		error();
}
static void	checker(t_all *all)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		get_func(all, line);
		free(line);
	}
	if (sort_true(all))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

t_all	*parser(char **argv)
{
	t_all	*all;
	char	**arr;

	arr = get_line(argv);
	check_argv(arr);
	check_repeat(arr);
	all = init_struct(arr);
	add_to_stack(all, arr);
	free_array(arr, 0);
	return (all);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	if (argc > 1)
	{
		all = parser(argv);
		checker(all);
		free_stack(all);
	}
	return (0);
}
