/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimik <adimik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:38:31 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/07 10:11:00 by adimik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xx(long n)
{
	char	*symbols;
	int		i;

	symbols = "0123456789ABCDEF";
	i = 0;
	if (n < 0)
	{
		i += ft_print_c('-');
		n = -n;
	}
	if (n < 16)
		i += ft_print_c(symbols[n]);
	else
	{
		i += ft_print_xx(n / 16);
		i += ft_print_xx(n % 16);
	}
	return (i);
}
