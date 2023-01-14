/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:14:14 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 16:17:26 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	unsigned char		*dest_2;
	const unsigned char	*src_2;

	if (dest == src || n == 0)
		return (dest);
	dest_2 = (unsigned char *)dest;
	src_2 = (const unsigned char *)src;
	if (dest < src)
	{
		while (n--)
			*dest_2++ = *src_2++;
	}
	else
	{
		dest_2 = dest_2 + n;
		src_2 = src_2 + n;
		while (n--)
		{
			*(--dest_2) = *(--src_2);
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char *s = malloc(7);
//     int i = -1;
//     while (++i < 7)
//     {
//         s[i] = i + 1;
//     }
//     char *t = s + 3;
//     ft_memmove(s, t, 4);
//     i = -1;
//     printf("----\n");
//     while (++i < 7)
//         printf("%i\n", s[i]);
//     char d[20] = "1234567";
//     char ss[] = "abcdefg";
//     memmove(d, ss, 3);
//     printf("%s\n", ss);
//     ft_memmove(d, ss, 3);
//     printf("%s\n", d);
// }