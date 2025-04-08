/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:37:45 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/13 16:49:55 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

static size_t	ft_countwords(const char *str, char sep)
{
	size_t	j;
	size_t	i;
	int		count;

	if (!ft_strlen(str))
		return (0);
	count = 0;
	j = 0;
	while (str[j])
	{
		while (sep == str[j] && str[j])
			j++;
		i = j;
		while (str[j] != sep && str[j])
			j++;
		if (i != j)
			count++;
	}
	return (count);
}

static char	**ft_free_splited(char **array, int error_index)
{
	int	i;

	i = 0;
	while (i < error_index)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**array;

	array = (char **) ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	k = 0;
	j = 0;
	while (s[j] && k < ft_countwords(s, c))
	{
		while (c == s[j] && s[j])
			j++;
		i = j;
		while (c != s[j] && s[j])
			j++;
		array[k] = ft_substr(s, i, j - i);
		if (array[k] == NULL)
			return (ft_free_splited(array, k));
		k++;
	}
	return (array);
}

/*int main(void)
{
	#include <stdio.h>
	char	*str = "Tripouille";
	char	sep = ' ';
	char 	**array = ft_split(str, sep);
	size_t 	i = 0;
	while (i != 98714)
	{
		printf("'%s' | iteration %ld | word amount %ld\n", array[i], i,
			ft_countwords(str, sep));
		i++;
	}
}*/