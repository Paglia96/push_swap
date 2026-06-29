#include "push_swap.h"

int	is_ordered(t_list *lst)
{
	if (!lst->next)
		return (TRUE);
	while(lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

int	is_reverse_ordered(t_list *lst)
{
	if (!lst->next)
		return (TRUE);
	while(lst->next)
	{
		if (lst->nb < lst->next->nb)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

void	tail_of_list(t_list **last)
{
	while ((*last)->next)
		(*last) = (*last)->next;
}

int	is_greatest_number(int nb, t_list *lst)
{
	while (lst)
	{
		if (lst->nb > nb)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

int lesser_number(t_list *lst)
{
	int	min;
	
	min = lst->nb;
	lst = lst->next;
	while (lst)
	{
		if (lst->nb < min)
			min = lst->nb;
		lst = lst->next;
	}
	return min;
}

int	greatest_number(t_list *lst)
{
	int	max;
	
	max = lst->nb;
	lst = lst->next;
	while (lst)
	{
		if (lst->nb > max)
			max = lst->nb;
		lst = lst->next;
	}
	return max;
}

int	prev_greatest_number(t_list *lst)
{
	int	prev;
	int	greatest;

	prev = lst->nb;
	if (ft_lstsize(lst) == 2)
	{
		if (lst->next->nb < prev)
			return (lst->next->nb);
	}
	greatest = greatest_number(lst);
	lst = lst->next;
	while (lst)
	{
		if (lst->nb != greatest)
		{
			if (lst->nb > prev)
				prev = lst->nb;
		}
		lst = lst->next;
	}
	return prev;
}

int	target_distance(int nb, t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->nb == nb)
			return(i);
		lst = lst->next;
		i++;
	}
	return (i);
}

int	target_idx_distance(int target, t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->idx == target)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

int	ordered_but_need_rotation(t_list *lst)
{
	int	min;
	int nb;
	t_list *start;

	min = lesser_number(lst);
	start = lst;
	while (lst->nb != min)
	{
		lst = lst->next;
	}
	while(lst)
	{
		nb = lst->nb;
		if (lst->next && nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	if (start->nb == min)
		return (0); // gia' ordinata in ordine crescente, non serve rotazione
	while(start && start->next->nb != min)
	{
		if (nb > start->nb)
			return (0);
		nb = start->nb;
		start = start->next;
	}
	if (nb > start->nb) // coda e testa
		return (0);
	return (1);
}

void	rotate_to_order(t_list **a, t_count *count)
{
	int distance;
	int len;

	distance = target_distance(lesser_number(*a),*a);
	len = ft_lstsize(*a);
	if (distance > (len / 2))
	{
		while(!is_ordered(*a))
			reverse_rotate(a, 'a', count);
	}
	else
		while(!is_ordered(*a))
			rotate(a, 'a', count);
}

char	determine_rotate_direction(t_list *lst, t_list *start)
{
	int	len_right;
	int	len_left;
	int	first;
	int	i;

	first = 0;
	i = 0;
	while (lst->next)
	{
		if (lst->nb > lst->next->nb)
		{
			if (!first)
			{
				len_right = i;
				first = 1;
			}
			len_left = i;
		}
		i++;
		lst = lst->next;
	}
	if (lst->nb > start->nb) // coda e testa
			len_left = i;
	len_left = ft_lstsize(start) - len_left;
	if (len_left < len_right)
		return ('l');
	return ('r');
}
