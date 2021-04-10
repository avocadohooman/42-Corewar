/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nwords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:34:56 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/24 17:37:48 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nwords(char const *s, char delim)
{
	int		count;
	int		i;

	if (!s)
		return (0);
	count = 0;
	if (*s != delim)
		count++;
	i = 0;
	while (s[i])
	{
		if (s[i] == delim && s[i + 1] != delim && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
