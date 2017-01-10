/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 17:14:22 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:52:22 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fract			*mv_func(int keycode, t_fract *fract)
{
	if (keycode == 123)
	{
		fract->mandel.minre -= fract->mandel.zoom / 8;
		fract->mandel.maxre -= fract->mandel.zoom / 8;
	}
	else if (keycode == 124)
	{
		fract->mandel.minre += fract->mandel.zoom / 8;
		fract->mandel.maxre += fract->mandel.zoom / 8;
	}
	else if (keycode == 125)
	{
		fract->mandel.minim -= fract->mandel.zoom / 8;
		fract->mandel.maxim -= fract->mandel.zoom / 8;
	}
	else if (keycode == 126)
	{
		fract->mandel.minim += fract->mandel.zoom / 8;
		fract->mandel.maxim += fract->mandel.zoom / 8;
	}
	return (fract);
}

static void				zm_func_pl(t_fract *fract)
{
	fract->mandel.zoom = get_max_inter(fract->mandel.minre,
	fract->mandel.maxre, fract->mandel.minim, fract->mandel.maxim) / 1.25;
	fract->mandel.maxiter += 1;
	fract->mandel.minre = fract->mandel.minre + (fract->mandel.zoom / 4);
	fract->mandel.maxre = fract->mandel.maxre - (fract->mandel.zoom / 4);
	fract->mandel.minim = fract->mandel.minim + (fract->mandel.zoom / 4);
	fract->mandel.maxim = fract->mandel.maxim - (fract->mandel.zoom / 4);
	fract->mandel.re_factor = (fract->mandel.maxre - fract->mandel.minre)
	/ (fract->swin.size_x - 1);
	fract->mandel.im_factor = (fract->mandel.maxim - fract->mandel.minim)
	/ (fract->swin.size_y - 1);
}

static void				zm_func_ms(t_fract *fract)
{
	fract->mandel.zoom = get_max_inter(fract->mandel.minre,
	fract->mandel.maxre, fract->mandel.minim, fract->mandel.maxim) / 1.25;
	if (fract->mandel.maxiter > 4)
		fract->mandel.maxiter -= 1;
	fract->mandel.minre = fract->mandel.minre - (fract->mandel.zoom / 4);
	fract->mandel.maxre = fract->mandel.maxre + (fract->mandel.zoom / 4);
	fract->mandel.minim = fract->mandel.minim - (fract->mandel.zoom / 4);
	fract->mandel.maxim = fract->mandel.maxim + (fract->mandel.zoom / 4);
	fract->mandel.re_factor = (fract->mandel.maxre - fract->mandel.minre)
	/ (fract->swin.size_x - 1);
	fract->mandel.im_factor = (fract->mandel.maxim - fract->mandel.minim)
	/ (fract->swin.size_y - 1);
}

static void				launch_fract(int no, t_fract *fract)
{
	if (no == 1)
		ft_mandelbrot(*fract);
	else if (no == 2)
		ft_julia(*fract);
	else if (no == 3)
		ft_burningships(*fract);
	else if (no == 4)
		ft_meduse(*fract);
}

int						ft_key_funct(int keycode, t_fract *fract)
{
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		fract = mv_func(keycode, fract);
	else if (keycode == 78)
		zm_func_ms(fract);
	else if (keycode == 69)
		zm_func_pl(fract);
	else if (keycode == 116)
		fract->mandel.maxiter += 5;
	else if (keycode == 121 && fract->mandel.maxiter > 5)
		fract->mandel.maxiter -= 5;
	launch_fract(fract->mandel.nofract, fract);
	return (1);
}
