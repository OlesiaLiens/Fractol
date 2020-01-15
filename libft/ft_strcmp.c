/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:52:03 by oshyiata          #+#    #+#             */
/*   Updated: 2018/11/16 14:19:18 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int						ft_strcmp(const char *s1, const char *s2)
{
	unsigned	int		i;
	unsigned	char	*s1_1;
	unsigned	char	*s2_2;

	i = 0;
	s1_1 = (unsigned char *)s1;
	s2_2 = (unsigned char *)s2;
	while (s1_1[i] == s2_2[i] && s1_1[i] != '\0' && s2_2[i] != '\0')
		i++;
	return (s1_1[i] - s2_2[i]);
}
