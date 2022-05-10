/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:46:33 by glychest          #+#    #+#             */
/*   Updated: 2019/09/11 22:40:22 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *poiter;
	char symbol;

	poiter = (char *)s + ft_strlen(s);
	symbol = (char)c;
	while (poiter >= s)
	{
		if (*poiter == symbol)
			return (poiter);
		poiter--;
	}
	return (NULL);
}
