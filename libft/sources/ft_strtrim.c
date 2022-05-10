/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 01:55:10 by glychest          #+#    #+#             */
/*   Updated: 2019/09/16 17:52:36 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcntfirstchar(char *str, char *charset)
{
	char			*ptr;
	int				idx;
	unsigned int	cnt;
	unsigned int	tmp;

	ptr = str;
	cnt = 0;
	while (*ptr)
	{
		idx = 0;
		tmp = cnt;
		while (charset[idx])
			if (charset[idx++] == *ptr)
				cnt++;
		if (cnt == tmp)
			return (cnt);
		ptr++;
	}
	return (cnt);
}

static int		ft_strcntlastchar(char *str, char *charset)
{
	unsigned int		i;
	int					ind;
	unsigned int		cnt;
	unsigned int		tmp;

	cnt = 0;
	i = (unsigned int)ft_strlen(str) - 1;
	while (str[i])
	{
		ind = 0;
		tmp = cnt;
		while (charset[ind])
			if (charset[ind++] == str[i])
				cnt++;
		if (cnt == tmp)
			return (cnt);
		i--;
	}
	return (cnt);
}

char			*ft_strtrim(char const *s)
{
	char				*res;
	unsigned int		start;
	unsigned int		size;
	unsigned int		count;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen((char*)s);
	count = ft_strcntfirstchar((char*)s, " \n\t");
	start = count;
	if (size > count)
		count += ft_strcntlastchar((char*)s, " \n\t");
	size -= count;
	if (!(res = ft_memalloc((size_t)size + 1)))
		return (NULL);
	res = ft_strncpy(res, (char *)s + start, size);
	return (res);
}
