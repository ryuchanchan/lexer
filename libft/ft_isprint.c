/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:10:04 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 15:10:56 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_isprint(int	c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     printf("%d\n", ft_isprint('~'));
//     printf("%d\n", ft_isprint(' '));
//     printf("%d\n", ft_isprint(32));
//     printf("%d\n", ft_isprint(126));
//     printf("%d\n", ft_isprint(31));
//     printf("%d\n", ft_isprint(127));
// }
