/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:10:32 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/13 17:19:30 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*tempnode;
	void	*tempcontent;

	lst2 = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		tempcontent = f(lst->content);
		tempnode = ft_lstnew(tempcontent);
		if (!tempnode)
		{
			ft_lstclear(&lst2, del);
			del(tempcontent);
			return (NULL);
		}
		ft_lstadd_back(&lst2, tempnode);
		lst = lst->next;
	}
	return (lst2);
}
