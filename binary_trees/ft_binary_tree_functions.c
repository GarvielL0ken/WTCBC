/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_tree_fucntions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:15:42 by jsarkis           #+#    #+#             */
/*   Updated: 2019/03/01 11:33:32 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
    t_btree *new;

    new = malloc(sizeof(t_btree));
    if (new)
    {
        new->left = NULL;
        new->right = NULL;
        new->item = item;
    }
    return (new);
}

void    btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    if (root)
    {
            applyf(root->item);
        if (root->left)
            btree_apply_prefix(root->left, applyf);
        if (root->right)
            btree_apply_prefix(root->right, applyf);
    }
}

void    btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
    if (root)
    {
        if (root->left)
            btree_apply_infix(root->left, applyf);
        applyf(root->item);
        if (root->right)
            btree_apply_infix(root->right, applyf);
    }
}

void    btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (root)
    {
        if (root->left)
            btree_apply_suffix(root->left, applyf);
        if (root->right)
            btree_apply_suffix(root->right, applyf);
        applyf(root);
    }
}

void    btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
    if (*root)
    {
        if (cmpf(item, (*root)->item) < 0)
        {
            if ((*root)->left)
                btree_insert_data(&(*root)->left, item, cmpf);
            else
                (*root)->left = btree_create_node(item);
        }
        else
        {
            if ((*root)->right)
                btree_insert_data(&(*root)->right, item, cmpf);
            else
                (*root)->right = btree_create_node(item);
        }
    }
    else
    {
        *root = btree_create_node(item);
    }
}
