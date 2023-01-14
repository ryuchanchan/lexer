/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:13:29 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 15:16:14 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*data;

	if (count)
		if (size > SIZE_MAX / count)
			return (NULL);
	data = malloc(count * size);
	if (!data)
		return (NULL);
	ft_bzero(data, count * size);
	return (data);
}

// #include <stdio.h>
// int main()
// {
//     int *mem,*p;
//     int i;

//     mem = (int *)ft_calloc(500,sizeof(int));
//     p = mem;
//     for (i=0; i<500; i++) {
//         *p = i;
//         printf("%d ",*p);
//         p++;
//     }
//     free(mem);
// }
