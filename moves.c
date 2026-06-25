#include "push_swap.h"

void	swap(t_list **lst, char c, t_count *count)
{
	t_list *one;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	if (c == 'a')
	{
		write(1, "sa\n", 3);
		count->sa += 1;
		count->total += 1;
	}
	else if (c == 'b')
	{
		write(1, "sb\n", 3);
		count->sb += 1;
		count->total += 1;
	}
	one = *lst;
	*lst = (*lst)->next;
	one->next = (*lst)->next;
	(*lst)->next = one;
}

void	double_swap(t_list **lst_a, t_list **lst_b, t_count *count)
{
	swap(lst_a, 's', count);
	swap(lst_b, 's', count);
	write(1, "ss\n", 3);
	count->ss += 1;
	count->total += 1;
}

void	push(t_list **lst_dest, t_list **lst_src, char c, t_count *count)
{
	if (c == 'a')
	{
		write(1, "pa\n", 3);
		count->pa += 1;
		count->total += 1;
	}
	else
	{
		write(1, "pb\n", 3);
		count->pb += 1;
		count->total += 1;
	}
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

void	rotate(t_list **lst, char c, t_count *count)
{
	t_list *first;
	t_list *tmp;

	if (c == 'a')
	{
		write(1, "ra\n", 3);
		count->ra += 1;
		count->total += 1;
	}
	else
	{
		write(1, "rb\n", 3);
		count->rb += 1;
		count->total += 1;
	}

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

void	double_rotate(t_list **lst_a, t_list **lst_b, t_count *count)
{
	rotate(lst_a, 'r', count);
	rotate(lst_b, 'r', count);
	write(1, "rr\n", 3);
	count->rr += 1;
	count->total += 1;
}

void	reverse_rotate(t_list **lst, char c, t_count *count)
{
	t_list	*last;
	t_list	*prev;
	t_list	*first;

	if (c == 'a')
	{
		write(1, "rra\n", 4);
		count->rra += 1;
		count->total += 1;
	}
	else
	{
		write(1, "rrb\n", 4);
		count->rrb += 1;
		count->total += 1;
	}

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

void	double_reverse_rotate(t_list **lst_a, t_list **lst_b, t_count *count)
{
	reverse_rotate(lst_a, 'r', count);
	reverse_rotate(lst_b, 'r', count);
	write(1, "rrr\n", 4);
	count->rrr += 1;
	count->total += 1;
}
