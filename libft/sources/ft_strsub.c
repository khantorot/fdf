/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 01:41:48 by glychest          #+#    #+#             */
/*   Updated: 2019/09/12 01:58:00 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (!s || !(res = ft_memalloc(len + 1)))
		return (NULL);
	res = ft_strncpy(res, (char*)s + start, len);
	return (res);
}
