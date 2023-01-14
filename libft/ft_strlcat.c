/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:14:32 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 18:16:34 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	n;

	len_src = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (dstsize + len_src);
	len_dst = ft_strlen(dst);
	if (len_dst >= dstsize)
		return (dstsize + len_src);
	n = (dstsize - 1) - len_dst;
	if (len_src < n)
		n = len_src;
	ft_memcpy(&dst[len_dst], src, n);
	dst[len_dst + n] = '\0';
	return (len_dst + len_src);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
//     char c[50];
//     c[0] = '\0';
//     // char b[50] = "aaaaa"; //world
//     char a[50] = "aaaaa";
//     // a = &c[0];
//     size_t i;
//     i = ft_strlcat(a, "hello", 11);
//     printf("%s\n", a);
//     printf("%zu\n", i);
//     i = strlcat(NULL, "hello", 0);   //この確認(dst == NULL && dstsize == 0)
//     printf("%s\n", a);
//     printf("%zu\n", i);    
//     // i = strlcat(NULL, "hello", 1);
//     // printf("%s\n", a);
//     // printf("%zu\n", i);
//     // i = strlcat(a, b, 16);
//     // printf("%s\n", a);
//     // printf("%zu\n", i);

//     i = ft_strlcat(a, "hello", 5);
//     printf("%s\n", a);
//     printf("%zu\n", i);
//     // i = ft_strlcat(NULL, "hello", 1);
//     // printf("%s\n", a);
//     // printf("%zu\n", i);
//     i = ft_strlcat(NULL, "hello", 0);
//     printf("%s\n", a);
//     printf("%zu\n", i);
// }
