/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:00:28 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/10/27 15:00:35 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static void	ft_wr_word(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	ft_wr_split(char **big_split, const char *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != '\0' && str[i + j] != c)
				j++;
			big_split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (big_split[word] == NULL)
				return (ft_free_split(big_split));
			ft_wr_word(big_split[word], &str[i], c);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**big_split;
	int		nb_words;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(s, c);
	big_split = malloc(sizeof(char *) * (nb_words + 1));
	if (big_split == NULL)
		return (NULL);
	big_split[nb_words] = 0;
	ft_wr_split(big_split, s, c);
	return (big_split);
}
