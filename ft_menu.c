/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:55:14 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:52:54 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_tutoriel(t_windata swin)
{
	mlx_string_put(swin.mlx, swin.win, 25, 60, swin.colors[30],
	"____________  ___  _____ _____ _ _____ _");
	mlx_string_put(swin.mlx, swin.win, 25, 75, swin.colors[30],
	"|  ___| ___ \\/ _ \\/  __ |_   _( |  _  | |");
	mlx_string_put(swin.mlx, swin.win, 25, 90, swin.colors[30],
	"| |_  | |_/ / /_\\ | /  \\/ | | |/| | | | |");
	mlx_string_put(swin.mlx, swin.win, 25, 105, swin.colors[30],
	"|  _| |    /|  _  | |     | |   | | | | |");
	mlx_string_put(swin.mlx, swin.win, 25, 120, swin.colors[30],
	"| |   | |\\ \\| | | | \\__/\\ | |   \\ \\_/ | |____");
	mlx_string_put(swin.mlx, swin.win, 25, 137, swin.colors[30],
	"\\_|   \\_| \\_\\_| |_/\\____/ \\_/    \\___/\\_____/");
	mlx_string_put(swin.mlx, swin.win, 20, 250, swin.colors[30],
	"---PRESS ENTER BUTTON TO DISPLAY FRACTAL---");
	mlx_string_put(swin.mlx, swin.win, 20, 300, swin.colors[30],
	"--use - & + to zoom--");
	mlx_string_put(swin.mlx, swin.win, 20, 350, swin.colors[30],
	"--use pageup and pagedown to change definition--");
	mlx_string_put(swin.mlx, swin.win, 20, 400, swin.colors[30],
	"--use arrow keys to move around--");
}

void			ft_menu(t_windata swin, int nofract)
{
	nofract = 1;
	draw_tutoriel(swin);
}
