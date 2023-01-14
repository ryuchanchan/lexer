/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:42:22 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 18:48:40 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lencheck(char const	*s, unsigned int	start, size_t	len)
{
	if ((ft_strlen(s) - start) < len)
		return ((ft_strlen(s) - start));
	else
		return (len);
}

char	*ft_substr(char const	*s, unsigned int	start, size_t	len)
{
	char	*sub;

	if (s)
	{
		if (ft_strlen(s) < start)
			return (ft_strdup(""));
		sub = ft_calloc((lencheck(s, start, len) + 1), sizeof(char));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, s + start, len + 1);
		return (sub);
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char *str = ft_substr("Hey!,42tokyo!", 7, 5);
//     printf("%s\n", str);
//     char *str2 = ft_substr("Hey!,42tokyo!", 13, 5);
//     printf("%s\n", str2);
//     char *str3 = ft_substr(NULL, 7, 5);
//     printf("%s\n", str3);
//     //test2
//     char *str4 = ft_substr("tripouille", 0, 42000);
//     printf("%s\n", str4);
// 	char *str5 = ft_substr("tripouille", 4, 0);
//     printf("%s\n", str5);
// }