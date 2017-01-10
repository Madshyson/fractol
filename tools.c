/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:42:15 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:19:15 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		get_max_inter(double amin, double amax, double bmin, double bmax)
{
	if ((amin - amax) > (bmin - bmax))
		return (val_abs(amin - amax));
	return (val_abs(bmin - bmax));
}

double		val_abs(double nbr)
{
	if (nbr < 0.0)
		return (-1 * nbr);
	return (nbr);
}
