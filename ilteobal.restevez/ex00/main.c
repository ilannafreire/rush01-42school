/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:54:13 by restevez          #+#    #+#             */
/*   Updated: 2024/07/21 22:28:52 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "skyscraper.h"

int	solve(int *hints);

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		hints[N * N];
	int		c;

	if (!argc)
		return (1);
	if (!(argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 0;
	j = 0;
	while (argv[1][j] && i < N * N)
	{
		c = argv[1][j] - 48;
		hints[i++] = c;
		j += 2;
	}
	solve(hints);
	return (0);
}
