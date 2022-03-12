#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_struct
{
    struct s_struct   *prev;
    int num;
    int index;
    int flag;
    struct s_struct    *next;
}   t_one;

typedef struct s_all
{
    t_one   *a; //stack a
    t_one   *b; //stack b
    int     min_a;
    int     min_i;
    int     max_i;
    int     median;
    int     len_a; //длина стека а (количество двусвязных списков)
    int     len_b;

}   t_all;

/*push_swap.c*/
t_all   *parser(char **argv);
void    sorter(t_all *all);

/*----------------------------parser----------------------------*/
/*parser_init.c*/
char    **get_line(char **argv);
t_all   *init_struct(char **arr);

/*parser_add.c*/
void    add_to_stack(t_all *all, char **arr);
void    create_stack(t_all *all, int *sort, int *org, int len);
t_one   *new_list(int nb, int index);
void    lstadd_back(t_one **a, t_one *new);

/*parser_check*/
void    check_argv(char **arr);
void    check_repeat(char **arr);

/*bouble_sort.c*/
void    bouble_sort(t_all *all, int *sort, int *org, int len);

/*--------------------------------------------------------------*/

/*errors.c*/
void    error(void);
void    free_array(char **arr, int f);
void    free_stack(t_all *all);

/*----------------------------sorter----------------------------*/

/*median.c*/
void    median_a(t_all *all);
void    median_b(t_all *all);
void    move_down_a(t_all *all);
void    move_a_to_b_first(t_all *all);
int    sort_true(t_all *all);

/*sort_b_five.c*/
void    push_down(t_all *all);
void    sort_b_three(t_all *all);
void    after_math_sorting_three(t_all *all, int flag);
void    sort_b_five(t_all *all);

/*sort_big.c*/
int min_in_b_to_a(t_all *all);
void    sent_from_b_to_a(t_all *all);
void    sort_five_from_a_to_b_sec(t_all *all, int f);
void    sort_five_from_a_to_b(t_all *all, int i, int f, int min);

/*sort_big_second.c*/
void    min_in_a_to_b(t_all *all);
void    send_back(t_all *all);

/*sort_five_three.c*/
void    sort_three_a(t_all *all);
int short_path(t_all *all);
void    sort_five(t_all *all);

/*-----------------------------18---------------------------------*/

/*----------------------------functions----------------------------*/

void    push_b(t_all *all);
void    push_a(t_all *all);
void    pb(t_all *all, int flag);
void    pa(t_all *all, int flag);

void    rrr(t_all *all, int flag);
void    rrb(t_all *all, int flag);
void    rra(t_all *all, int flag);

void    rr(t_all *all, int flag);
void    rb(t_all *all, int flag);
void    ra(t_all *all, int flag);

void    ss(t_all *all, int flag);
void    sb(t_all *all, int flag);
void    sa(t_all *all, int flag);
/*-----------------------------------------------------------------*/

#endif