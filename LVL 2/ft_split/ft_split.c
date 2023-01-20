/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:32:05 by juduval           #+#    #+#             */
/*   Updated: 2023/01/11 15:40:23 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c)
{
	if ((c == 32) || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_words(char *str)
{
	int 	i;
	int	count;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_sep(str[i]))
			i++;
		else
		{
			count++;
			while (!is_sep(str[i]))
				i++;
		}
	}
	return (count);
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*ns;

	i = 0;
	while ((!is_sep(str[i])) && str[i])
		i++;
	ns = malloc( i + 1 * sizeof(char));
	if (!ns)
		return (NULL);
	i = 0;
	while (str[i] && (!is_sep(str[i])))
	{
		ns[i] = str[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);

}

char	**ft_free(char	**s, int	j)
{
	while (s[j])
	{
		free(s[j]);
		j--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char *str)
{
	int	i;
	int	j;
	char	**nt;

	i = 0;
	j = 0;
	nt = malloc((count_words(str) + 1) * sizeof(char *));
	if (!nt)
		return (0);
	if (count_words(str) == 0)
		return (nt);
	while (str[i])
	{
		if (is_sep(str[i]))
			i++;
		else
		{
			nt[j] = ft_strdup(str + i);
			if (!nt[j])
				return (ft_free(nt, j));
			i = i + ft_strlen(nt[j++]);
		}
	}
	return (nt);
}

#include <stdio.h>
int	main(void)
{
	char	**split;
	char	s[] = " la chatte a mireille split il marche pas !  ";
	int	i;

	i = 0;
	split = ft_split(s);
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}
