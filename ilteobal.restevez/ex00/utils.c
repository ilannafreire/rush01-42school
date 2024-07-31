/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:25:22 by restevez          #+#    #+#             */
/*   Updated: 2024/07/21 22:34:02 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "skyscraper.h"

// Verifies the hints, checking if there's any
//  min (1) or max (N) duplicates on the same row/column
int	verify_duplicates(int *hints, int *max_exist, int *min_exist)
{
	int	hint_l;
	int	hint_n;

	hint_n = -1;
	hint_l = 0;
	while (hint_l < N * N)
	{
		*min_exist = 0;
		*max_exist = 0;
		hint_n = -1;
		while (++hint_n < N)
		{
			if (!(*min_exist) && hints[hint_l + hint_n] == 1)
				*min_exist = 1;
			else if (*min_exist && hints[hint_l + hint_n] == 1)
				return (1);
			if (!(*max_exist) && hints[hint_l + hint_n] == N)
				*max_exist = 1;
			else if (*max_exist && hints[hint_l + hint_n] == N)
				return (1);
		}
		hint_l += N;
	}
	return (0);
}

// Verifies if the puzzle is unsolvable right away by checking
// 1: If the hints repeat N or 1
// 2: If the hints on the same row/column sum more than N + 1
int	validate_hints(int *hints)
{
	int	i;
	int	min_exist;
	int	max_exist;

	i = 0;
	min_exist = 0;
	max_exist = 0;
	if (verify_duplicates(hints, &max_exist, &min_exist))
		return (1);
	while (i < N)
	{
		if (hints[i] + hints[i + N] > N + 1
			|| hints[i] + hints[i + N] < 3)
			return (1);
		i++;
	}
	i = N + N;
	while (i < (N * 3))
	{
		if (hints[i] + hints[i + N] > N + 1
			|| hints[i] + hints[i + N] < 3)
			return (1);
		i++;
	}
	return (0);
}

void	segreg_top_bot_hints(int *top_hints, int *bottom_hints, int *hints)
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			if ((i * N) == 0)
				top_hints[j] = hints[(i * N) + j];
			if ((i * N) == N)
				bottom_hints[j] = hints[(i * N) + j];
		}
	}
}

void	segreg_left_right_hints(int *left_hints, int *right_hints, int *hints)
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			if ((i * N) == N * 2)
				left_hints[j] = hints[(i * N) + j];
			if ((i * N) == N * 3)
				right_hints[j] = hints[(i * N) + j];
		}
	}
}

void	print_int(int num)
{
	char	buffer[12];
	int		index;
	int		is_negative;

	index = 11;
	buffer[index] = '\0';
	if (num == 0)
		buffer[--index] = '0';
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	while (num > 0)
	{
		buffer[--index] = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative)
		buffer[--index] = '-';
	write(1, &buffer[index], 11 - index);
}
