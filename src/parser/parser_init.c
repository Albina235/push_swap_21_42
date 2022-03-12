#include "../push_swap.h"

char    **get_line(char **argv)
{
    int i;
    char    *tmp;
    char    *line;
    char    **arr;

    i = 1;
    line = ft_strdup(argv[1]);
    while (argv[++i])
    {
        tmp = line;
        line = ft_strjoin(line, " ");
        free(tmp);
        tmp = line;
        line = ft_strjoin(line, argv[i]);
        free(tmp);
    }
    arr = ft_split(line, ' ');
    free(line);
    return (arr);
}

t_all   *init_struct(char **arr)
{
    t_all   *all;
    int i;

    i = 0;
    while (arr[i])
        i++;
    all = malloc(sizeof(t_all));
    all->a = NULL;
    all->b = NULL;
    all->len_a = i;
    all->len_b = 0;
    all->min_a = 1;
    return (all);
}