/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:05:48 by jsarkis           #+#    #+#             */
/*   Updated: 2019/03/01 11:25:41 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root)
	{
		printf("%d : ", *((int *)((*root)->item)));
		if (cmpf(item, (*root)->item) < 0)
		{
			printf("LEFT\n");
			if ((*root)->left)
				btree_insert_data(&(*root)->left, item, cmpf);
			else
				(*root)->left = btree_create_node(item);
		}
		else
		{
			printf("RIGHT\n");
			if ((*root)->right)
				btree_insert_data(&(*root)->right, item, cmpf);
			else
				(*root)->right = btree_create_node(item);
		}
	}
	else
	{
		*root = btree_create_node(item);
		printf("%d\nNEW\n", *((int *)((*root)->item)));
	}
}

int	ft_cmpf(void *i, void *j)
{
	printf("%d : %d :", *((int *)i), *((int *)j));
	if (*((int *)i) < (*(int *)j))
	{
		printf("LESS: ");
		return (-1);
	}
	else if (*((int *)j) < (*(int *)i))
	{
		printf("MORE: ");
		return (1);
	}
	else
	{
		printf("EQUAL: ");
		return (0);
	}
}

void	ft_print_item(void *item)
{
	printf("%d\n", *((int *)item));
}

int main(int argc, char **argv)
{
	int i;
	int n;
	int m;
	t_btree *root;
	t_btree **p;

	i = 1;
	root = NULL;
	p = &root;
	if (argc > 1)
	{
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		btree_insert_data(p, &n, &ft_cmpf);
		btree_insert_data(p, &m, &ft_cmpf);
		printf("AFTER: %d\n", *((int *)(root->item)));
		i++;
		btree_apply_prefix(root, &ft_print_item);
	}
}
