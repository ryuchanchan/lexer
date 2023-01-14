/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:21:01 by rykawamu          #+#    #+#             */
/*   Updated: 2022/06/05 21:12:25 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char	(f)(unsigned int, char))
{
	char			*ss;
	size_t			i;

	if (!s)
		return (NULL);
	ss = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ss)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ss[i] = f(i, s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

// #include <stdio.h>
// char my_func(unsigned int i, char str)
// {
//     printf("My inner function: index = %d and %c\n", i, str);
//     return str - 32;
// }
// char my_func2(unsigned int i, char c)
// {
//     if ('a' <= c && c <= 'z')
//         printf("%d\n", i);
//         return (c + (-32));
//     return (c);
// }
// int main()
// {
//     char str[10] = "hello.";
//     printf("result: %s\n", str);
//     char *result = ft_strmapi(str, my_func);
//     printf("The result is %s\n", result);
//     char *result2 = ft_strmapi(NULL, my_func);
//     printf("The result is %s\n", result2);
//     char *result3 = ft_strmapi(str, my_func2);
//     printf("The result is %s\n", result3);
//     return 0;
// }
