/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:17:58 by wjo               #+#    #+#             */
/*   Updated: 2021/10/27 21:42:08 by wjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	change1(char *argv1, char *argv2)
{
	int	i;

	i = 0;
	while (argv1[i] && argv2[i] && argv1[i] == argv2[i])
	{
		i++;
	}
	return (argv1[i] - argv2[i]);
}

void	print12(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argc > i)
	{
		while (*argv[i])
		{
			write (1, argv[i], 1);
			argv[i]++;
		}
		i++;
		write (1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	char	*change;
	int		i;
	int		k;
	int		c;

	i = 1;
	k = 1;
	while (argc - 1 > i)
	{
		k = 1 + i;
		while (argc > k)
		{
			c = change1(argv[i], argv[k]);
			if (c > 0)
			{
				change = argv[i];
				argv[i] = argv[k];
				argv[k] = change;
			}
			k++;
		}
		i++;
	}
	print12(argc, argv);
	return (0);
}
