/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:51:11 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/29 02:36:47 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list	*lst, void	(*del)(void	*))
{
	if (lst == 0 || del == 0)
		return ;
	del(lst->content);
	free(lst);
}
