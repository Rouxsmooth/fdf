/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:28:18 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/04 00:23:34 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	ft_del(void	*ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return ;
}

void	delchar(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return ;
}

void	del_2d_array(void **array, int len)
{
	void	**temp;
	int		i;

	if (!array)
		return ;
	i = 0;
	temp = array;
	while (i < len)
	{
		ft_del(*array);
		array++;
		i++;
	}
	return (ft_del(temp));
}

void	del_3d_array(void ***array, int len, int *insidelens)
{
	int		i;
	void	***temp;

	i = 0;
	if (!array)
		return ;
	temp = array;
	while (i < len)
	{
		del_2d_array(*array, insidelens[i]);
		array++;
		i++;
	}
	ft_del(temp);
	return ;
}
