/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:45:02 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/29 02:17:06 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(const char	*str, int	i, int	*sign)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static int	check_space(int	c)
{
	if (c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int					sign;
	unsigned long int	num;
	size_t				i;

	i = 0;
	sign = 1;
	while (check_space(str[i]))
		i++;
	i = check_sign(str, i, &sign);
	num = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (sign == -1 && (num > (unsigned long)LONG_MIN / 10 || \
		(unsigned long)(str[i] - '0') > (unsigned long)LONG_MIN - num * 10))
			return (0);
		if (sign == 1 && (num > LONG_MAX / 10 || \
					(unsigned long)(str[i] - '0') > LONG_MAX - num * 10))
			return (-1);
		num = (num * 10) + (unsigned long)(str[i] - '0');
		i++;
	}
	return (num * sign);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("%d\n", ft_atoi("9223372036854775808"));
//     printf("%d\n", ft_atoi("10"));
//     printf("%d\n", ft_atoi("+123"));
//     printf("%d\n", ft_atoi("-12345678"));
//     printf("%d\n", ft_atoi("0005"));
// 	printf("%d\n", ft_atoi("000000000000000000008"));
// 	printf("%d\n", ft_atoi("19223372036854775806"));
// 	printf("%d\n", ft_atoi("18446744073709551616"));
// }
