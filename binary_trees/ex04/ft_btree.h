/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:54:42 by jsarkis           #+#    #+#             */
/*   Updated: 2019/02/28 20:36:13 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

t_btree *btree_create_node(void *item);

void    btree_apply_prefix(t_btree *root, void (*applyf)(void *));

void    btree_apply_infix(t_btree *root, void (*applyf)(void *));

void    btree_apply_suffix(t_btree *root, void (*applyf)(void *));
#endif
