/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 01:45:19 by glychest          #+#    #+#             */
/*   Updated: 2020/01/06 09:10:44 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (s1 != NULL && s2 != NULL)
		if ((sum = (char*)malloc(sizeof(char) *
						(ft_strlen(s1) + ft_strlen(s2) + 1))) != NULL)
		{
			while (s1[i])
			{
				sum[i] = s1[i];
				i++;
			}
			while (s2[start])
			{
				sum[i] = s2[start];
				i++;
				start++;
			}
			sum[i] = '\0';
			return (sum);
		}
	return (NULL);
}
