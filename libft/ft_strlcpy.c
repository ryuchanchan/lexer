/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:19:00 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 18:20:19 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (i < dstsize)
		*(dst + i) = '\0';
	while (*(src + i) != '\0')
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     const char *src = "0123456789";
//     char dst[11];
//     strlcpy(dst,src,sizeof(dst));
//     printf("%s\n", dst);
//     const char *src1 = "01234\0a5";
//     char dst1[10];
//     ft_strlcpy(dst1,src1,sizeof(dst1));
//     printf("%s\n", dst1);

//     const char *src2 = "";
//     char dst2[10];
//     ft_strlcpy(dst2,src2,sizeof(dst2));
//     printf("%s\n", dst2);

//     const char *src3 = NULL;
//     char dst3[5];
//     strlcpy(dst3,src3,sizeof(dst3));
//     printf("%s\n", dst3);

//     // const char *src5 = "01234\0a5";
//     // char dst5[5];

//     //printf("%zu\n", ft_strlcpy(dst5, src5, sizeof(dst5));
//}
