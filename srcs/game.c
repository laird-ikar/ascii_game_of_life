/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:36:43 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/15 16:40:49 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(void)
{
	int		plane_int[PLANE_HEIGHT][PLANE_WIDTH];

	init_plane(plane_int);
	while (1)
	{
		print_plane(plane_int);
		next_plane(plane_int);
		sleep(1);
	}
	return (0);
}

void	init_plane(int plane_int[PLANE_HEIGHT][PLANE_WIDTH])
{
	int	i;
	int	j;

	i = -1;
	while (++i < PLANE_HEIGHT)
	{
		j = -1;
		while (++j < PLANE_WIDTH)
			plane_int[i][j] = ft_rand() % 2;
	}
}

void	print_plane(int plane_int[PLANE_HEIGHT][PLANE_WIDTH])
{
	int		i;
	int		j;
	int		str_pos;
	char	plane_str[PLANE_HEIGHT * (PLANE_WIDTH + 2)];

	i = -1;
	str_pos = 0;
	while (++i < PLANE_HEIGHT)
		plane_str[str_pos++] = '\n';
	i = -1;
	while (++i < PLANE_HEIGHT)
	{
		j = -1;
		while (++j < PLANE_WIDTH)
		{
			if (plane_int[i][j])
				plane_str[str_pos++] = '#';
			else
				plane_str[str_pos++] = '.';
		}
		plane_str[str_pos++] = '\n';
	}
	plane_str[str_pos] = '\0';
	ft_putstr(plane_str);
}

void	next_plane(int plane_int[PLANE_HEIGHT][PLANE_WIDTH])
{
	int	i;
	int	j;
	int	plane_tmp[PLANE_HEIGHT][PLANE_WIDTH];

	i = -1;
	while (++i < PLANE_HEIGHT)
	{
		j = -1;
		while (++j < PLANE_WIDTH)
			plane_tmp[i][j] = cell_future(plane_int, i, j);
	}
	i = -1;
	while (++i < PLANE_HEIGHT)
	{
		j = -1;
		while (++j < PLANE_WIDTH)
			plane_int[i][j] = plane_tmp[i][j];
	}
}

int	cell_future(int plane_int[PLANE_HEIGHT][PLANE_WIDTH], int i, int j)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = -1;
	while (x <= 1)
	{
		y = -1;
		while (y <= 1)
		{
			if (i + x >= 0 && i + x < PLANE_HEIGHT
				&& j + y >= 0 && j + y < PLANE_WIDTH
				&& (y != 0 || x != 0))
				count += plane_int[i + x][j + y];
			y++;
		}
		x++;
	}
	return (count == 3
		|| (count == 2 && plane_int[i][j]));
}
