/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:58:45 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/29 02:41:11 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*param;

	param = (t_list *)malloc(sizeof(t_list));
	if (param == NULL)
		return (NULL);
	param ->content = content;
	param ->next = NULL;
	return (param);
}
