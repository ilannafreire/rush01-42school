/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:40:44 by restevez          #+#    #+#             */
/*   Updated: 2024/07/21 22:33:08 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "skyscraper.h"

int		validate_hints(int *hints);
int		verify_top_hints(int top_hints[], int temp_line[], int **board);
int		verify_bottom_hints(int bottom_hints[], int temp_line[], int **board);
int		verify_left_hints(int left_hints[], int temp_line[], int **board);
int		verify_right_hints(int right_hints[], int temp_line[], int **board);
int		print_board(int **board);
int		recursive(int row, int col, int *hints, int **board);
void	segreg_top_bot_hints(int *top_hints, int *bottom_hints, int *hints);
void	segreg_left_right_hints(int *left_hints, int *right_hints, int *hints);

int	solve(int *hints)
{
	int	**board;
	int	i;

	board = (int **)malloc(N * sizeof(int *));
	i = -1;
	while (++i < N)
		board[i] = (int *)malloc(N * sizeof(int));
	if (board == NULL)
	{
		write(1, "Memory allocation failed\n", 25);
		return (1);
	}
	if (validate_hints(hints))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!(recursive(0, 0, hints, board)))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_board(board);
	return (0);
}

// Verifies if a number can be placed in a specific position
int	is_valid(int row, int col, int num, int **board)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (board[row][i] == num || board[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

// Counts visible skyscrappers at given line
int	count_visible(int *line)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < N)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

// Verifies if all hints are satisfied. It goes:
// Checks top hints, bottom hints, left and at last, right hints
// (Same as specified in the subject)
int	are_hints_satisfied(int *hints, int **board)
{
	int	temp_line[N];
	int	top_hints[N];
	int	bottom_hints[N];
	int	left_hints[N];
	int	right_hints[N];

	segreg_top_bot_hints(top_hints, bottom_hints, hints);
	segreg_left_right_hints(left_hints, right_hints, hints);
	if (!verify_top_hints(top_hints, temp_line, board))
		return (0);
	if (!verify_bottom_hints(bottom_hints, temp_line, board))
		return (0);
	if (!verify_left_hints(left_hints, temp_line, board))
		return (0);
	if (!verify_right_hints(right_hints, temp_line, board))
		return (0);
	return (1);
}

// Recursive function to solve the problem
// Using backtracking to clear inputs that don't solve the puzzle
int	recursive(int row, int col, int *hints, int **board)
{
	int	next_row;
	int	next_col;
	int	num;

	next_row = row;
	next_col = col + 1;
	num = 0;
	if (col == N - 1)
		next_row = row + 1;
	if (col == N - 1)
		next_col = 0;
	if (row == N)
		return (are_hints_satisfied(hints, board));
	while (++num <= N)
	{
		if (is_valid(row, col, num, board))
		{
			board[row][col] = num;
			if (recursive(next_row, next_col, hints, board))
				return (1);
			board[row][col] = 0;
		}
	}
	return (0);
}
