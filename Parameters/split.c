/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:14:01 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/01 14:06:22 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		nb_str;
	char	**tab;

	i = 0;
	j = 0;
	nb_str = ft_count_words(s, c);
	tab = malloc (sizeof(char *) * (nb_str + 2));
	if (tab == NULL)
		return (NULL);
	while (j < nb_str)
	{
		while (s[i] && s[i] == c)
			i++;
		tab[j] = ft_tab_lign(s + i, c);
		if (tab[j] == NULL)
			return (ft_free_tab(tab, j), NULL);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] && str[i] == c)
			i++;
		else if (str[i] && str[i] != c)
		{
			i++;
			if (!str[i] || str[i] == c)
				nb++;
		}
	}
	return (nb);
}

char	*ft_tab_lign(const char *s, char c)
{
	char		*dest;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}
