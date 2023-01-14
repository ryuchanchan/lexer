/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:19:50 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 15:26:55 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(int	n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*size_management(int n, int digits, char *convert_c)
{
	int				nums;

	nums = n;
	if (n == 0)
		convert_c[digits - 1] = 0 + '0';
	if (n < 0)
	{
		if (n <= INT_MIN)
			n++;
		n *= -1;
		convert_c[0] = '-';
	}
	while (n)
	{
		convert_c[digits - 1] = n % 10 + '0';
		n /= 10;
		digits--;
	}
	if (nums == INT_MIN)
		convert_c[10] = '8';
	return (convert_c);
}

char	*ft_itoa(int	n)
{
	char			*convert_c;
	unsigned int	digits;

	digits = num_size(n);
	convert_c = ft_calloc((digits + 1), sizeof(char));
	if (convert_c)
	{
		size_management(n, digits, convert_c);
		return (convert_c);
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
//     int a = 12345678;
//     int b = -12345678;
//     char *n = ft_itoa(a);
//     char *nn = ft_itoa(b);
//     printf("%s\n", n);
//     printf("%s\n", nn);
// }