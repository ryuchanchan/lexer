/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:04:29 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 15:05:39 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int	c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     printf("%d\n", ft_isdigit('2'));
//     printf("%d\n", ft_isdigit('a'));
// }
