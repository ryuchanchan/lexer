/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:14:11 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/29 02:38:46 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstiter(t_list	*lst, void	(*f)(void *))
{
	t_list	*lst2;

	if (lst)
	{
		lst2 = lst;
		while (lst2)
		{
			f(lst2->content);
			lst2 = lst2->next;
		}
	}
}
