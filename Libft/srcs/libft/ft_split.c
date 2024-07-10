/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:21:12 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/29 13:58:32 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	ft_free_split(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
				return (ft_free_split(big_split, word));
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

/*int	main(void)
{
	char *str = "le one piece existe";
	char c = ' ';
	char **res = ft_split(str, c);
	int	i;

	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return 0;
}*/
