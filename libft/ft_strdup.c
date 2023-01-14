/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:08:53 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 18:09:50 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s1)
{
	char	*data;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	data = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!data)
		return (NULL);
	ft_memcpy(data, s1, s1_len);
	data[s1_len] = '\0';
	return (data);
}

// #include <stdio.h>
// #include <string.h>
// #define STR "string"

// int main()
// {
//     char *s;

//     s = ft_strdup(STR);
//     printf("s= %s\n", s);
//     free(s);
// }
