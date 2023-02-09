/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:48:57 by sloghmar          #+#    #+#             */
/*   Updated: 2023/02/09 09:49:13 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

int	ft_is_sap(char c, char *sap)
{
	int	i;

	i = 0;
	while (sap[i])
	{
		if (c == sap[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *sap)
{
	int	i;
	int	w_count;
	int	state;

	i = 0;
	state = 0;
	w_count = 0;
	while (str[i])
	{
		if (ft_is_sap(str[i], sap))
		{
			if (!state)
				w_count++;
			state = 1;
			i++;
		}
		else
		{
			state = 0;
			i++;
		}
	}
	return (w_count);
}

char	*ft_strdup_worde(char *str, int *index, char *sap)
{
	char	*worde;
	int		len;
	int		i;

	i = *index;
	len = 0;
	while (str[i] && !ft_is_sap(str[i++], sap))
		len++;
	worde = (char *) malloc(len + 1);
	if (!worde)
		return (NULL);
	i = 0;
	while (str[*index])
	{
		if (!ft_is_sap(str[*index], sap))
		{
			worde[i++] = str[*index];
			(*index)++;
		}
		else
			break ;
	}
	worde[len] = '\0';
	return (worde);
}

char	**ft_split_str(char *str, char *sap)
{
	char	**array;
	int		wordes;
	int		i;
	int		index;

	i = 0;
	index = 0;
	wordes = ft_count_words(str, sap);
	array = (char **) malloc((wordes + 1) * 8);
	if (!array)
		return (NULL);
	while (index < wordes)
	{
		while (ft_is_sap(str[i], sap) && str[i])
			if (!str[i++])
				break ;
		array[index] = ft_strdup_worde(str, &i, sap);
		if (!array[index])
			return (ft_malloc_error(array));
		index++;
	}
	array[wordes] = 0;
	return (array);
}
