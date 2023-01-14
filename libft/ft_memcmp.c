/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:54 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 16:09:32 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t				i;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
//     char a[] = "ABDEFG";
//     char b[] = "ADCDEFG";

//     printf("%d\n", ft_memcmp(a, b, 7));
//     printf("%d\n", memcmp(a, b, 7));

//     printf("-----------\n");

//     printf("%d\n", ft_memcmp(a, b, 0));
//     printf("%d\n", memcmp(a, b, 0));
//     printf("-----------\n");

//     char aa[] = "ABCDEFG";
//     char bb[] = "ABCDEFG";
//     printf("%d\n", memcmp(aa, bb, 7));
//     printf("%d\n", ft_memcmp(aa, bb, 7));

//     printf("-----------\n");
//     char aaa[] = "A\0CDFFG";
//     char bbb[] = "A\0CDEFG";
//     printf("%d\n", ft_memcmp(aaa, bbb, 257));
//     printf("%d\n", memcmp(aaa, bbb, 257));
// }
