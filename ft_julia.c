/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:11:19 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:22:40 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		mouse_click(int button, int x, int y, t_fract *fract)
{
	if (button == 1 && y >= 0 && x >= 0)
	{
		fract->mandel.block += 1;
		ft_julia(*fract);
	}
	return (1);
}

static int		m_funct(int x, int y, t_fract *fract)
{
	if (fract->mandel.block % 2 == 0 && (x >= 0 && x < fract->swin.size_x)
	&& (y >= 0 && y < fract->swin.size_y))
	{
		fract->mandel.mx = (double)x / 150 - 2;
		fract->mandel.my = (double)y / 150 - 2;
		ft_julia(*fract);
	}
	return (0);
}

static int		julia(t_mandel m)
{
	int n;

	n = 0;
	while (n < m.maxiter)
	{
		m.z_reb = m.z_re * m.z_re;
		m.z_imb = m.z_im * m.z_im;
		if (m.z_reb + m.z_imb > 4)
			break ;
		m.z_im = 2 * m.z_re * m.z_im + m.c_im;
		m.z_re = m.z_reb - m.z_imb + m.c_re;
		n++;
	}
	return (n);
}

static void		fract_draw(t_windata swin, t_fract f)
{
	int n;
	int x;
	int y;

	y = 0;
	while (y < swin.size_y)
	{
		x = 0;
		f.mandel.z_im = f.mandel.maxim - y * f.mandel.im_factor;
		while (x < swin.size_x)
		{
			f.mandel.z_re = f.mandel.minre + x * f.mandel.re_factor;
			f.mandel.c_re = f.mandel.mx;
			f.mandel.c_im = f.mandel.my;
			if ((n = julia(f.mandel)) == f.mandel.maxiter)
				put_pixel_to_img(x, y, 0, &swin);
			else
				put_pixel_to_img(x, y, swin.colors[n % 61], &swin);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f.swin.mlx, f.swin.win, f.swin.img, 0, 0);
}

void			ft_julia(t_fract fract)
{
	fract_draw(fract.swin, fract);
	mlx_mouse_hook(fract.swin.win, mouse_click, &fract);
	mlx_hook(fract.swin.win, 6, (1L << 6), m_funct, &fract);
	mlx_hook(fract.swin.win, 2, (1L << 0), ft_key_funct, &fract);
	mlx_loop(fract.swin.mlx);
}
