/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 20:21:12 by mlavanan          #+#    #+#             */
/*   Updated: 2016/04/20 22:27:32 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			fill_pallette1(int tab[61])
{
	tab[0] = 0x000000;
	tab[1] = 0x110000;
	tab[2] = 0x220000;
	tab[3] = 0x330000;
	tab[4] = 0x440000;
	tab[5] = 0x550000;
	tab[6] = 0x660000;
	tab[7] = 0x770000;
	tab[8] = 0x880000;
	tab[9] = 0x990000;
	tab[10] = 0xaa0000;
	tab[11] = 0xbb0000;
	tab[12] = 0xcc0000;
	tab[13] = 0xdd0000;
	tab[14] = 0xee0000;
}

static void			fill_pallette2(int tab[61])
{
	tab[15] = 0xff0000;
	tab[16] = 0xff1111;
	tab[17] = 0xff2222;
	tab[18] = 0xff3333;
	tab[19] = 0xff4444;
	tab[20] = 0xff5555;
	tab[21] = 0xff6666;
	tab[22] = 0xff7777;
	tab[23] = 0xff8888;
	tab[24] = 0xff9999;
	tab[25] = 0xffaaaa;
	tab[26] = 0xffbbbb;
	tab[27] = 0xffcccc;
	tab[28] = 0xffdddd;
	tab[29] = 0xffeeee;
	tab[30] = 0xffffff;
}

static void			fill_pallette3(int tab[61])
{
	tab[31] = 0xffeeee;
	tab[32] = 0xffdddd;
	tab[33] = 0xffcccc;
	tab[34] = 0xffbbbb;
	tab[35] = 0xffaaaa;
	tab[36] = 0xff9999;
	tab[37] = 0xff8888;
	tab[38] = 0xff7777;
	tab[39] = 0xff6666;
	tab[40] = 0xff5555;
	tab[41] = 0xff4444;
	tab[42] = 0xff3333;
	tab[43] = 0xff2222;
	tab[44] = 0xff1111;
	tab[45] = 0xff0000;
}

static void			fill_pallette4(int tab[61])
{
	tab[60] = 0x000000;
	tab[59] = 0x110000;
	tab[58] = 0x220000;
	tab[57] = 0x330000;
	tab[56] = 0x440000;
	tab[55] = 0x550000;
	tab[54] = 0x660000;
	tab[53] = 0x770000;
	tab[52] = 0x880000;
	tab[51] = 0x990000;
	tab[50] = 0xaa0000;
	tab[49] = 0xbb0000;
	tab[48] = 0xcc0000;
	tab[47] = 0xdd0000;
	tab[46] = 0xee0000;
}

void				fill_palette(int tab[61])
{
	fill_pallette1(tab);
	fill_pallette2(tab);
	fill_pallette3(tab);
	fill_pallette4(tab);
}
