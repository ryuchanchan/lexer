/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:10:09 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 16:13:42 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char			*dst_2;
	const unsigned char		*src_2;
	size_t					i;

	dst_2 = (unsigned char *)dst;
	src_2 = (const unsigned char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		dst_2[i] = src_2[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char *dst = NULL;
//     char *src = NULL;    
//     char d[] = "1234567";
//     char s[] = "abcd\0efg";
//     ft_memcpy(d, s, 3);
//     printf("%s\n", d);
//     // memcpy(d, s, 3);
//     // printf("%s\n", d);
//     ft_memcpy(dst, src, 3);
//     printf("%s\n", dst);
// }
