/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:18:44 by restevez          #+#    #+#             */
/*   Updated: 2024/07/21 22:28:31 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "skyscraper.h"

void	print_int(int num);

// Print the board with the solution
int	print_board(int **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			print_int(board[i][j]);
			if (j < N - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < N)
	{
		free(board[i]);
		i++;
	}
	free(board);
	return (0);
}
