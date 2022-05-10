/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:03:52 by glychest          #+#    #+#             */
/*   Updated: 2019/09/13 22:09:25 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int pos;
	unsigned int i;

	if (!*needle)
		return ((char*)haystack);
	pos = 0;
	while (haystack[pos] != '\0' && (size_t)pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char*)&haystack[pos]);
		}
		pos++;
	}
	return (0);
}
