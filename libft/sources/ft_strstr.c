/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:02:56 by glychest          #+#    #+#             */
/*   Updated: 2019/09/12 18:04:51 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *s1;
	const char *s2;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		s1 = haystack;
		s2 = needle;
		while (*s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
