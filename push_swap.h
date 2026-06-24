#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include <stdio.h>


#define TRUE 1
#define FALSE 0

// strategy selector

typedef struct s_flags
{
	int		bench;
	int		simple;
	int		medium;
	int		complex_s;
	int		adaptive;
}	t_flags;

typedef struct s_list
{
	int		nb;
	struct s_list	*next;
}	t_list;


void	args_parser(char **argv, t_list **lst, t_flags *flag, int i);


//MOVES
void	swap(t_list **lst, char c);
void	double_swap(t_list **lst_a, t_list **lst_b);
void	push(t_list **lst_dest, t_list **lst_src, char c);
void	rotate(t_list **lst, char c);
void	double_rotate(t_list **lst_a, t_list **lst_b);
void	reverse_rotate(t_list **lst, char c);
void	double_reverse_rotate(t_list **lst_a, t_list **lst_b);

void    error_call();

int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_atoi(const char *nptr, int *y);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


void	insertion_sort(t_list **a, t_list **b);

void    tail_of_list(t_list **last);

int is_greatest_number(int nb, t_list *lst);
int lesser_number(t_list *lst);
int greatest_number(t_list *lst);
int ordered_but_need_rotation(t_list *lst);
int target_distance(int nb, t_list *lst);
void    rotate_to_order(t_list **a);
char    determine_rotate_direction(t_list *lst, t_list *start);

//LST_UTILS
t_list  *ft_lstnew(int nb);
int	ft_lstsize(t_list *first_node);
void	ft_lstpush(t_list **first_node, t_list *new);

int	is_ordered(t_list *lst);
int	is_reverse_ordered(t_list *lst);

void	ft_lstprint(t_list *lst_a, t_list *lst_b);
void	ft_putnbr(int n);

#endif
