/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:46:22 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/06 17:50:13 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ND -1

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
	int	nb;
	int	idx;//METTILO AD UNSIGNED INT
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
	char	*strategy;
	int	adaptive_called;
}	t_count;

//STRUCT INITIALIZERS
void	flags_initializer(t_flags *flag);
void	flags_parser(t_flags *flag, char *str, int *y, t_list *a);
void	count_initializer(t_count *count);

//PARSING
void	args_parser(char **argv, t_list **lst, t_flags *flag, int i);
void	index_list(t_list *lst);

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
char	*ft_strdup(char *str);
size_t	ft_strlen(const char *str);

// ALGORITHMS
void	simple_min_max_extraction_method(t_list **a, t_list **b, t_count *count);
void	chunk_sort(t_list **a, t_list **b, t_count *count);
void	radix_sort(t_list **a, t_list **b, t_count *count);
void	disorder(t_list *lst, t_count *count);
void	push_in_b(t_list **a, t_list **b, t_count *count);
int	*fill_intset(int i, const int chunk, int **intset);
int	target_idx_distance(int nb, t_list *lst);
int	nearest_nb(int *intset, t_list **a, int chunk);
void	push_back_in_a(t_list **a, t_list **b, t_count *count);
void	choose_algorithm(t_list **a, t_list **b, t_count *count);
int	parsing_size(t_list **a, t_list **b, int lst_size, t_count *count);
void	print_stats_on_stderr(t_count *moves);
void	ft_putnbr_moves(int n);
int	is_greatest_number(int nb, t_list *lst);
int	is_smallest_number(int nb, t_list *lst);
int	lesser_number(t_list *lst);
int	greatest_number(t_list *lst);
int	target_distance(int nb, t_list *lst);
void	rotate_to_order(t_list **a, t_count *count);
int	prev_greatest_number(t_list *lst);
int	greatest_index(t_list *lst);
void	which_half(t_list **a, t_count *count, int *intset, int chunk);

//LST_UTILS
t_list	*ft_lstnew(int nb);
int	ft_lstsize(t_list *first_node);
void	ft_lstpush(t_list **first_node, t_list *new);
void	free_lst(t_list *list);

int	is_ordered(t_list *lst);
int	is_reverse_ordered(t_list *lst);

void	ft_lstprint(t_list *lst_a, t_list *lst_b);
void	ft_putnbr(int n);

#endif
