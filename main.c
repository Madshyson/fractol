/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:57:00 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:33:10 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int					key_funct(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(1);
	else if (fract->mandel.nofract == 1 && keycode == 36)
		ft_mandelbrot(*fract);
	else if (fract->mandel.nofract == 2 && keycode == 36)
		ft_julia(*fract);
	else if (fract->mandel.nofract == 3 && keycode == 36)
		ft_burningships(*fract);
	else if (fract->mandel.nofract == 4 && keycode == 36)
		ft_meduse(*fract);
	return (1);
}

static t_windata			init_mlx(void)
{
	t_windata swin;

	swin.size_x = 500;
	swin.size_y = 500;
	fill_palette(swin.colors);
	swin.mlx = mlx_init(0);
	swin.win = mlx_new_window(swin.mlx, swin.size_x, swin.size_y, "fract'ol");
	swin.img = mlx_new_image(swin.mlx, swin.size_x, swin.size_y);
	return (swin);
}

static t_fract				*init_fract_handler(int nf)
{
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	if (!fract)
		return (NULL);
	fract->swin = init_mlx();
	fract->mandel = initmandel(fract->swin);
	fract->mandel.nofract = nf;
	return (fract);
}

static int					checkflag(char *str)
{
	if (ft_strcmp("-mandelbrot", str) == 0)
		return (1);
	else if (ft_strcmp("-julia", str) == 0)
		return (2);
	else if (ft_strcmp("-burningship", str) == 0)
		return (3);
	else if (ft_strcmp("-meduse", str) == 0)
		return (4);
	return (0);
}

int							main(int ac, char **av)
{
	t_fract *fract;

	if (ac == 2 && checkflag(av[1]) != 0)
	{
		fract = init_fract_handler(checkflag(av[1]));
		ft_menu(fract->swin, checkflag(av[1]));
		mlx_key_hook(fract->swin.win, key_funct, fract);
	}
	else
	{
		ft_putendl("put one of the following flags :");
		ft_putendl("-mandelbrot -burningship -julia -meduse");
		return (0);
	}
	mlx_loop(fract->swin.mlx);
}
