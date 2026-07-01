#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include <stdio.h>


#define TRUE 1
#define FALSE 0
#define ND -1

// strategy selector


// STRUCTS
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
	int		idx;
	struct s_list	*next;
}	t_list;

typedef struct s_count
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	float	disorder;
}	t_count;

//STRUCT INITIALIZERS
void    flags_initializer(t_flags *flag);
void    flags_parser(t_flags *flag, char *str, int *y, t_list *a);
void    count_initializer(t_count *count);

//PARSING
void	args_parser(char **argv, t_list **lst, t_flags *flag, int i);
void    index_list(t_list *lst);

//MOVES
void	swap(t_list **lst, char c, t_count *count);
void	double_swap(t_list **lst_a, t_list **lst_b, t_count *count);
void	push(t_list **lst_dest, t_list **lst_src, char c, t_count *count);
void	rotate(t_list **lst, char c, t_count *count);
void	double_rotate(t_list **lst_a, t_list **lst_b, t_count *count);
void	reverse_rotate(t_list **lst, char c, t_count *count);
void	double_reverse_rotate(t_list **lst_a, t_list **lst_b, t_count *count);

void	error_call(t_list *lst);

int	round_sqrt(int nb);

int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_atoi(const char *nptr, int *y, t_list *a);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// ALGORITHMS
void	simple_min_max_extraction_method(t_list **a, t_list **b, t_count *count);
void	chunk_sort(t_list **a, t_list **b, t_count *count);
void	disorder(t_list *lst, t_count *count);
void	push_in_b(t_list **a, t_list **b, t_count *count);
int	*fill_intset(int i, const int chunk, int **intset);
int	target_idx_distance(int nb, t_list *lst);
int	nearest_nb(int *intset, t_list **a, int chunk);
void	push_back_in_a(t_list **a, t_list **b, t_count *count);

void    tail_of_list(t_list **last);

int is_greatest_number(int nb, t_list *lst);
int lesser_number(t_list *lst);
int greatest_number(t_list *lst);
int ordered_but_need_rotation(t_list *lst);
int target_distance(int nb, t_list *lst);
void    rotate_to_order(t_list **a, t_count *count);
char    determine_rotate_direction(t_list *lst, t_list *start);
int prev_greatest_number(t_list *lst);

//LST_UTILS
t_list  *ft_lstnew(int nb);
int	ft_lstsize(t_list *first_node);
void	ft_lstpush(t_list **first_node, t_list *new);

int	is_ordered(t_list *lst);
int	is_reverse_ordered(t_list *lst);

void	ft_lstprint(t_list *lst_a, t_list *lst_b);
void	ft_putnbr(int n);

#endif
