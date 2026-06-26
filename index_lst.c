#include "push_swap.h"

static int	lesser_nb_needing_index(t_list *lst)
{
	int	min;

	min = 2147483647;
	while(lst)
	{
		if (lst->idx == ND && lst->nb < min)
			min = lst->nb;
		lst = lst->next;
	}
	return (min);
}

void	index_list(t_list *lst)
{
	int	i;
	int	min;
	int size;
	t_list	*start;

	i = 0;
	size = ft_lstsize(lst);
	start = lst;
	while(i < size)
	{
		lst = start;
		while (lst)
		{
			min = lesser_nb_needing_index(start);
			if (lst->nb == min)
			{
				lst->idx = i;
				i++;
			}
			lst = lst->next;
		}
	}
}
