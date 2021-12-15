/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:40:17 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/15 16:37:50 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define PLANE_HEIGHT 15
# define PLANE_WIDTH 20

# include <unistd.h>

# include "libft.h"

void	init_plane(int plane[PLANE_HEIGHT][PLANE_WIDTH]);
void	next_plane(int plane[PLANE_HEIGHT][PLANE_WIDTH]);
void	print_plane(int plane_int[PLANE_HEIGHT][PLANE_WIDTH]);
int		cell_future(int plane_int[PLANE_HEIGHT][PLANE_WIDTH], int i, int j);

#endif
