#include "push_swap.h"

void	swap(t_list **lst, char c)
{
	t_list *one;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	one = *lst;
	*lst = (*lst)->next;
	one->next = (*lst)->next;
	(*lst)->next = one;
}

void	double_swap(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a, 's');
	swap(lst_b, 's');
	write(1, "ss\n", 3);
}

void	push(t_list **lst_dest, t_list **lst_src, char c)
{
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	if (!lst_src || !*lst_src)
		return ;
	t_list *tmp;
	t_list *tmp_b;

	tmp = *lst_src;
	*lst_src = (*lst_src)->next;
	if (!*lst_dest)
	{
		*lst_dest = tmp;
		(*lst_dest)->next = NULL;
		return ;
	}
	tmp->next = *lst_dest;
	tmp_b = *lst_dest;
	*lst_dest = tmp;
}

void	rotate(t_list **lst, char c)
{
	t_list *first;
	t_list *tmp;

	if (c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);

	first = *lst;
	tmp = *lst;
	if (!lst || !*lst || !(*lst)->next)
		return ;
	*lst = ((*lst)->next);

	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = first;
	first->next = NULL;
}

void	double_rotate(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a, 'r');
	rotate(lst_b, 'r');
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_list **lst, char c)
{
	t_list	*last;
	t_list	*prev;
	t_list	*first;

	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);

	last = *lst;
	first = *lst;
	prev = NULL;
	if (!lst || !*lst || !(*lst)->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = first;
	*lst = last;
}

void	double_reverse_rotate(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate(lst_a, 'r');
	reverse_rotate(lst_b, 'r');
	write(1, "rrr\n", 4);
}
