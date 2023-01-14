/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:18:59 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 16:20:00 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*buf, int	ch, size_t	n)
{
	size_t	i;

	i = 0;
	while (n-- > 0)
	{
		((unsigned char *)buf)[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char buf[] = "ABCDEFGH";
//     // ft_memset(buf + 3, '\0', 3);
//     ft_memset(buf, '6', 3);
//     printf("buf..%s\n", buf);
//     ft_memset(buf + 3, '7', 3);
//     printf("buf..%s\n", buf);    
// }
