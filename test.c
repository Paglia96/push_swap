#include "push_swap.h"


void	push_all_in_b_except_min(t_list **a, t_list **b, t_count *count)
{
	int min;

	min = lesser_number(*a);
	while((*a)->next)
	{
		if ((*a)->nb == min)
			rotate(a, 'a', count);
		else
			push(b, a, 'b', count);
	}
	//ft_lstprint(*a, *b);
}

void	push_back_in_a(t_list **a, t_list **b, t_count *count)
{
	int	size;
	int	greatest_nb_distance;
	int	prev_greatest_nb_distance;
	int prev_moved;

	while(*b)
	{
		if ((*b)->next)
		{
			greatest_nb_distance = target_distance(greatest_number(*b), *b);
			size = ft_lstsize(*b);
			prev_moved = 0;
			if ((*b)->next)
				prev_greatest_nb_distance = target_distance(prev_greatest_number(*b), *b);
			if(greatest_nb_distance >= (size / 2))
			{
				if((*b)->next && prev_greatest_nb_distance < greatest_nb_distance && prev_greatest_nb_distance >= (size / 2))
				{
					while((*b)->nb != prev_greatest_number(*b))
						reverse_rotate(b, 'b', count);
					push(a, b, 'a', count);
					prev_moved = 1;
				}
				while((*b)->nb != greatest_number(*b))
					reverse_rotate(b, 'b', count);
			}
			else			
			{
				if((*b)->next && prev_greatest_nb_distance < greatest_nb_distance && prev_greatest_nb_distance < (size / 2))
				{
					while((*b)->nb != prev_greatest_number(*b))
						rotate(b, 'b', count);
					push(a, b, 'a', count);
					prev_moved = 1;
				}
				while((*b)->nb != greatest_number(*b))
					rotate(b, 'b', count);
			}
		}
		push(a, b, 'a', count);
		if (prev_moved && (*a)->next && (*a)->nb > (*a)->next->nb)
			swap(a, 'a', count);
	}
}

void	simple_min_max_extraction_method(t_list **a, t_list **b, t_count *count)
{
	int	lst_size;

	lst_size = ft_lstsize(*a);
	if (lst_size == 2 && (*a)->nb > (*a)->next->nb)
		swap(a, 'a', count);
	//else if (lst_size == 3)
	//else if (lst_size == 4)
	//else if (lst_size == 5)
	//gestisci casi fino a 5 numeri
	if (is_ordered(*a))
		return ;
	push_all_in_b_except_min(a, b, count);
	push_back_in_a(a, b, count);
	reverse_rotate(a, 'a', count); // il min e' rimasto in fondo
	//ft_lstprint(*a, *b);
}
