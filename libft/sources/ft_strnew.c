/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:33:25 by glychest          #+#    #+#             */
/*   Updated: 2019/09/17 15:15:55 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	if (size + 1 < size)
		size -= 1;
	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	return (str);
}
