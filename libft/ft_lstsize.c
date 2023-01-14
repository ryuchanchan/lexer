/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:01:54 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/29 02:37:54 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	t_list	*lst_count;
	int		i;

	lst_count = lst;
	i = 0;
	while (lst_count != 0)
	{
		lst_count = lst_count ->next;
		i++;
	}
	return (i);
}
