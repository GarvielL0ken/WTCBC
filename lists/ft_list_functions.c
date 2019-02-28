/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:45:42 by jsarkis           #+#    #+#             */
/*   Updated: 2019/02/27 15:28:15 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	if (temp)
	{
		temp->data = data;
		temp->next = NULL;
	}
	return (temp);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp;

	temp = *begin_list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->data = data;
		new->next = *begin_list;
		*begin_list = new;
	}
}

int ft_list_size(t_list *begin_list)
{
    int i;

    i = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*next;
	int		i;

	i = 2;
	if (ac < 2)
		return (NULL);
	else
	{
		list = ft_create_elem(av[1]);
		while (i < ac)
		{
			next = ft_create_elem(av[i]);
			next->next = list;
			list = next;
			i++;
		}
		return (list);
	}
}

t_list	*ft_remove_first(t_list *list)
{
	t_list *next;

	if (list)
	{
		next = list->next;
		free(list);
		return (next);
	}
	else
		return (NULL);
}

void	ft_list_clear(t_list **begin_list)
{
	while (*begin_list)
		*begin_list = ft_remove_first(*begin_list);
	*begin_list = NULL;
}

void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int    i;
    t_list          *temp;

    i = 0;
    temp = begin_list;
    while (i < nbr)
    {
        if (temp->next == NULL)
            return (NULL);
        temp = temp->next;
        i++;
    }
    return (temp);
}

void    ft_list_reverse(t_list **begin_list)
{
    t_list *prev;
    t_list *current;
    t_list *next;

    prev = NULL;
    current = *begin_list;
    next = *begin_list;
    while (current)
    {
        next = next->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin_list = prev;
}
