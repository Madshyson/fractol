/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meduse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 21:42:49 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:23:11 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		meduse(t_mandel m)
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
		m.z_re = fabs(m.z_reb - m.z_imb) + m.c_re;
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
		f.mandel.c_im = f.mandel.maxim - y * f.mandel.im_factor;
		while (x < swin.size_x)
		{
			f.mandel.c_re = f.mandel.minre + x * f.mandel.re_factor;
			f.mandel.z_re = f.mandel.c_re;
			f.mandel.z_im = f.mandel.c_im;
			if ((n = meduse(f.mandel)) == f.mandel.maxiter)
				put_pixel_to_img(x, y, 0, &swin);
			else
				put_pixel_to_img(x, y, swin.colors[n % 61], &swin);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f.swin.mlx, f.swin.win, f.swin.img, 0, 0);
}

void			ft_meduse(t_fract fract)
{
	fract_draw(fract.swin, fract);
	mlx_hook(fract.swin.win, 2, (1L << 0), ft_key_funct, &fract);
	mlx_loop(fract.swin.mlx);
}
