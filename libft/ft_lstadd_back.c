/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:28:56 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/29 02:41:39 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*back_lst;

	if (lst)
	{
		back_lst = *lst;
		if (!(*lst))
			*lst = new;
		else
		{
			while (back_lst->next)
				back_lst = back_lst->next;
			back_lst->next = new;
		}
	}
}
