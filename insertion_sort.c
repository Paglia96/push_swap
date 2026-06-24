#include "push_swap.h"

void	insertion_sort(t_list **a, t_list **b) // migliorare scegliendo direction di rotazione
{
	char	direction;
	//ft_lstprint(*a, *b);
	direction = 'r';
	direction = determine_rotate_direction(*a, *a);
	while(!is_ordered(*a))
	{
		if (ordered_but_need_rotation(*a))
		{
			rotate_to_order(a);
			//ft_lstprint(*a, *b);
			break;
		}
		if (((*a)->nb) < ((*a)->next->nb) && !ordered_but_need_rotation(*a))
		{
			direction = determine_rotate_direction(*a, *a);
			if (direction == 'r')
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
		
		if (((*a)->nb) > ((*a)->next->nb))
		{
			if (is_greatest_number((*a)->nb, *a))
    		{
        			// È il massimo → ruotalo in a, non pusharlo in b
        		rotate(a, 'a');
    		}
    		else
    		{
				if (!*b)
				{
					push(b, a, 'b');
		//			ft_lstprint(*a, *b);
				}
				while ((*b && !is_greatest_number((*b)->nb, *a) && (*b)->nb > (*a)->nb))
				{
					rotate(a, 'a');
	//				ft_lstprint(*a, *b);
				}
				
				if (*b && is_greatest_number((*b)->nb, *a)) //b numero piu' grande della lista
				{
					while (!is_greatest_number((*a)->nb, *a))
					{
						rotate(a, 'a');
					//	ft_lstprint(*a, *b);
					}
					rotate(a, 'a');
		//			ft_lstprint(*a, *b);
					push(a, b, 'a');
		//			ft_lstprint(*a, *b);
					rotate(a, 'a');
				}
				if (*b && (*b)->nb < (*a)->nb)
				{
					push(a, b, 'a');
		//			ft_lstprint(*a, *b);
				}
				//ft_lstprint(*a, *b);
			}
		}

	}
	ft_lstprint(*a, *b);
}
/*
void	insertion_sort(t_list **a, t_list **b) // migliorare scegliendo direction di rotazione
{
	push(b, a, 'b');
	ft_lstprint(*a, *b);
	int i;
	int y;
	int	i_greater_y;
	i = (*a)->nb;
	y = (*b)->nb;
	while((*a)->next)
	{
		i = (*a)->nb;
		y = (*b)->nb;
		i_greater_y = 0;
		while((*b)->nb != i && (*a)->next)
		{
			if (i > y)
				while (i > (*b)->nb)
				{
					rotate(b, 'b');
					//if ((*b)->nb == y) // not rotated break
					//	break;
					ft_lstprint(*a, *b);
					i_greater_y = 1;
					write(1, "\nqui\n", 5);
				}
			push(b, a, 'b');
			ft_lstprint(*a, *b);
			if (!i_greater_y)
				y = (*b)->nb;
			while(i_greater_y && (*b)->nb != y)
			{
				rotate(b, 'b');
				ft_lstprint(*a, *b);
			//	write(1, "\nqui\n"", 5");
			}
		}
	}
}
*/
