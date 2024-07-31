/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:39:03 by restevez          #+#    #+#             */
/*   Updated: 2024/07/21 22:28:36 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	count_visible(int *line);

int	verify_top_hints(int top_hints[], int temp_line[], int **board)
{
	int	col;
	int	row;

	row = -1;
	col = -1;
	while (++col < N)
	{
		row = -1;
		while (++row < N)
			temp_line[row] = board[row][col];
		if (count_visible(temp_line) != top_hints[col])
			return (0);
	}
	return (1);
}

int	verify_bottom_hints(int bottom_hints[], int temp_line[], int **board)
{
	int	col;
	int	row;

	row = -1;
	col = -1;
	while (++col < N)
	{
		row = -1;
		while (++row < N)
			temp_line[row] = board[N - 1 - row][col];
		if (count_visible(temp_line) != bottom_hints[col])
			return (0);
	}
	return (1);
}

int	verify_left_hints(int left_hints[], int temp_line[], int **board)
{
	int	col;
	int	row;

	col = -1;
	row = -1;
	while (++row < N)
	{
		col = -1;
		while (++col < N)
			temp_line[col] = board[row][col];
		if (count_visible(temp_line) != left_hints[row])
			return (0);
	}
	return (1);
}

int	verify_right_hints(int right_hints[], int temp_line[], int **board)
{
	int	col;
	int	row;

	col = -1;
	row = -1;
	while (++row < N)
	{
		col = -1;
		while (++col < N)
			temp_line[col] = board[row][N - 1 - col];
		if (count_visible(temp_line) != right_hints[row])
			return (0);
	}
	return (1);
}
