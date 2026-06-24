#include "push_swap.h"


void	push_all_in_b_except_min(t_list **a, t_list **b)
{
	int min;

	min = lesser_number(*a);
	while((*a)->next)
	{
		if ((*a)->nb == min)
			rotate(a, 'a');
		push(b, a, 'b');
	}
	//ft_lstprint(*a, *b);
}

void	push_back_in_a(t_list **a, t_list **b)
{
	while(*b)
	{
		if ((*b)->next)
		{
			if(target_distance(greatest_number(*b), *b) >= (ft_lstsize(*b) / 2))
			{
				while((*b)->nb != greatest_number(*b))
					rotate(b, 'b');
			}
			else			
			{
				while((*b)->nb != greatest_number(*b))
					reverse_rotate(b, 'b');
			}
		}
		push(a, b, 'a');
	}
}

void	insertion_sort(t_list **a, t_list **b)
{
	//int lst_size;

	//lst_size = ft_lstsize(*a);
	push_all_in_b_except_min(a, b);
	push_back_in_a(a, b);
	//ft_lstprint(*a, *b);
	reverse_rotate(a, 'a');
	//ft_lstprint(*a, *b);
	/*
	if (ordered_but_need_rotation(*a))
		{
			rotate_to_order(a);
		}
	*/
}
