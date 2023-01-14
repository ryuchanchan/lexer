/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:29:53 by rykawamu          #+#    #+#             */
/*   Updated: 2022/06/05 21:13:11 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*trim;
	size_t	front_finder;
	size_t	back_finder;

	if (s1)
	{
		if (*s1 == '\0' || !set)
			return (ft_strdup(s1));
		front_finder = 0;
		while (s1[front_finder] && ft_strchr(set, s1[front_finder]) != NULL)
			front_finder++;
		back_finder = ft_strlen(s1);
		while (ft_strchr(set, s1[back_finder]) != NULL && \
				back_finder > front_finder)
			back_finder--;
		trim = ft_substr(s1 + front_finder, 0, back_finder - front_finder + 1);
		return (trim);
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
//     // char *result;
//     // result = ft_strtrim("a", NULL);
//     // printf("%s\n", result);

//     char *result2;
//     char *ss = ",,,,abcd,,,";
//     result2 = ft_strtrim(ss, ",");
//     printf("%s\n", result2);

//     // char *result3;
//     // result3 = ft_strtrim(NULL, ",");
//     // printf("%s\n", result3);

//     // char *result4;
//     // result4 = ft_strtrim(NULL, ",");
//     // printf("%s\n", result4);
// }
