/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:57:14 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/29 02:42:14 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
