/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:54:36 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:30:02 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

typedef struct		s_windata
{
	void	*mlx;
	void	*win;
	void	*img;
	int		size_x;
	int		size_y;
	int		colors[61];
}					t_windata;

typedef	struct		s_mandel
{
	int		nofract;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	re_factor;
	double	im_factor;
	int		maxiter;
	double	c_im;
	double	c_re;
	double	z_re;
	double	z_im;
	double	z_reb;
	double	z_imb;
	double	mx;
	double	my;
	int		block;
	double	zoom;
}					t_mandel;

typedef struct		s_fract
{
	t_windata	swin;
	t_mandel	mandel;
}					t_fract;

int					main(int ac, char **av);
void				ft_mandelbrot(t_fract fract);
void				ft_burningships(t_fract fract);
void				ft_julia(t_fract fract);
void				fill_palette(int tab[31]);
int					ft_key_funct(int keycode, t_fract *fract);
void				ft_menu(t_windata swin, int nofract);
t_mandel			initmandel(t_windata swin);
double				val_abs(double nbr);
double				get_max_inter(double amin, double amax,
					double bmin, double bmax);
void				put_pixel_to_img(int x, int y,
					unsigned long color, t_windata *swin);
void				ft_meduse(t_fract fract);

#endif
