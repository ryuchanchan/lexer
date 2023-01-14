/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:39:20 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 18:41:53 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == '\0')
		return ((char *)haystack);
	if (len == needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == '\0')
			return ((char *)haystack);
	}
	i = -1;
	while (haystack[++i])
	{
		k = i - 1;
		j = -1;
		if (haystack[i] == needle[0])
			while (haystack[++k] == needle[++j] && needle[j])
				if (j + 1 == needle_len && k < len)
					return ((char *)(haystack + i));
	}
	return (NULL);
}
// #include <string.h>
// #include <stdio.h>
// int main()
// {
//     char    *s1 = "ab";
//     char    *s2 = "";
//     char    *i1 = strnstr(s1, s2, 9);
//     char    *i2 = ft_strnstr(s1, s2, 9);
//     printf("strnstr: %s\nft_strnstr: %s\n", i1, i2);
//     printf("----------------\n");
//     char    *ss1 = "abcdefghijk";
//     char    *ss2 = "efg";
//     char    *ii1 = strnstr(ss1, ss2, 11);
//     char    *ii2 = ft_strnstr(ss1, ss2, 11);
//     printf("strnstr: %s\nft_strnstr: %s\n", ii1, ii2);
//     printf("----------------\n");
//     char    *sss1 = "\0DE123  ab";
//     char    *sss2 = "DE";
//     char    *iii1 = strnstr(sss1, sss2, 5);
//     char    *iii2 = ft_strnstr(sss1, sss2, 5);
//     printf("strnstr: %s\nft_strnstr: %s\n", iii1, iii2);
//     printf("----------------\n");
//     char    *ssss1 = "abcdefghijk";
//     char    *ssss2 = "efg";
//     char    *iiii1 = strnstr(ssss1, ssss2, 2);
//     char    *iiii2 = ft_strnstr(ssss1, ssss2, 2);
//     printf("strnstr: %s\nft_strnstr: %s\n", iiii1, iiii2);
//     char    *sssss1 = "abc";
//     char    *sssss2 = "abc";
//     char    *iiiii1 = strnstr(sssss1, sssss2, 3);
//     char    *iiiii2 = ft_strnstr(sssss1, sssss2, 3);
//     printf("strnstr: %s\nft_strnstr: %s\n", iiiii1, iiiii2);
// }
