/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 19:17:10 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:38:14 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				ft_strlen(char *s)
{
	int			len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char			*ft_strdup(char *str)
{
	int			i;
	char		*new;

	i = 0;
	new = NULL;
	if (str == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char		*bkp;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	bkp = ft_memalloc(ft_strlen((s1) + ft_strlen(s2)) * sizeof(char));
	if (bkp != NULL)
	{
		len = ft_strlen(s1);
		while (i < len)
		{
			bkp[i] = s1[i];
			i++;
		}
		len = ft_strlen(s2);
		while (j < len)
			bkp[i++] = s1[j++];
		bkp[i] = '\0';
		return (bkp);
	}
	return (NULL);
}

void			*ft_memalloc(int size)
{
	void		*str;
	char		*bkp;
	int			i;

	i = 0;
	bkp = NULL;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	bkp = str;
	while (i <= size)
		bkp[i++] = '\0';
	return (str);
}
