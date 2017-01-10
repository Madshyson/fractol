/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:17:49 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:21:45 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mandel		initmandel(t_windata swin)
{
	t_mandel ret;

	ret.minre = -3;
	ret.maxre = 3;
	ret.minim = -3;
	ret.maxim = 3;
	ret.re_factor = (val_abs(ret.maxre) +
	val_abs(ret.minre)) / (swin.size_x - 1);
	ret.im_factor = (val_abs(ret.maxim) +
	val_abs(ret.minim)) / (swin.size_y - 1);
	ret.maxiter = 60;
	ret.zoom = 0.5;
	ret.mx = 250;
	ret.my = 250;
	ret.block = 0;
	return (ret);
}
