/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:28:09 by rykawamu          #+#    #+#             */
/*   Updated: 2022/05/28 18:28:52 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int	c)
{
	if ('a' <= c && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
//     printf( "%c\n", toupper('a') );
//     printf( "%c\n", toupper('A') );
//     printf( "%c\n", toupper('!') );
//     printf( "%c\n", toupper(' ') );
//     printf("-----\n");
//     printf( "%c\n", ft_toupper('a') );
//     printf( "%c\n", ft_toupper('A') );
//     printf( "%c\n", ft_toupper('!') );
//     printf( "%c\n", ft_toupper(' ') );
// }
