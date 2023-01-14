/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:33:48 by rykawamu          #+#    #+#             */
/*   Updated: 2022/06/05 21:11:49 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check(const char	*s, char	sep)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

static char	*ft_strndup(char const	*s1, size_t	n)
{
	size_t	i;
	char	*data;

	data = (char *)malloc(sizeof(char) * (n + 1));
	if (!data)
		return (0);
	i = 0;
	while (i < n)
	{
		data[i] = s1[i];
		i++;
	}
	data[i] = '\0';
	return (data);
}

static char	**arrays(char	**ss, size_t	sc, const char	*s, const char	c)
{
	size_t	i;
	size_t	j;
	size_t	lens;

	i = 0;
	j = -1;
	while (++j < sc)
	{
		while (s[i] == c)
			i++;
		lens = check(s + i, c);
		ss[j] = ft_strndup(s + i, lens);
		if (ss[j] == NULL)
		{
			while (j--)
				free(ss[j]);
			free(ss);
			return (NULL);
		}
		i += lens;
	}
	ss[j] = NULL;
	return (ss);
}

static size_t	count_element_size(char const	*s, char	c)
{
	size_t	i;
	size_t	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
		{
			count += 1;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const	*s, char	c)
{
	char	**splits;
	size_t	element_size;
	char	**tmp;

	if (!s)
		return (NULL);
	element_size = count_element_size(s, c);
	splits = (char **)malloc(sizeof(char *) * (element_size + 1));
	if (!splits)
		return (0);
	tmp = arrays(splits, element_size, (char *)s, c);
	if (tmp == NULL)
		return (NULL);
	return (splits);
}

// #include <stdio.h>
// int main(void)
// {
// 	char **spi;
// 	int i = 0;
// 	spi = ft_split(",,-42,a,b,c,d,-,,,", ',');//,
// 	while (spi[i])
// 	{
// 		printf("%s\n", spi[i]);
// 		i++;
// 	}
// 	return (0);
// }
