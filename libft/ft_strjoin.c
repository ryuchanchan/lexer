/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:12:28 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 18:13:56 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*data;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	data = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!data)
		return (NULL);
	ft_strlcpy(data, s1, s1len + 1);
	ft_strlcpy(&data[s1len], s2, s2len + 1);
	data[s1len + s2len] = '\0';
	return (data);
}

/*#include <stdio.h>
int main()
{
    char *s = ft_strjoin("42", "tokyo");
    printf("%s\n", s);
    char *ss = ft_strjoin(NULL, NULL);
    printf("%s\n", ss);
}*/
