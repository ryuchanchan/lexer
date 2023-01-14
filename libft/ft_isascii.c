/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:06:16 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 15:06:51 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int	c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
//     printf("%d\n", ft_isascii(1));
//     printf("%d\n", ft_isascii('a'));
//     printf("%d\n", ft_isascii(' '));
// }
