/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:20:38 by oshyiata          #+#    #+#             */
/*   Updated: 2019/04/09 11:20:39 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_text(t_fractol *fract)
{
	mlx_string_put(fract->mlx, fract->win, 30,
					60, 0xb4eff7, "HOW TO USE");
	mlx_string_put(fract->mlx, fract->win,
					30, 80, 0x39a4b2, "Quit = ESC");
	mlx_string_put(fract->mlx, fract->win,
					30, 100, 0x39a4b2, "Move = ^ v < >");
	mlx_string_put(fract->mlx, fract->win,
					30, 120, 0x39a4b2, "Zoom = + - and mouse");
	mlx_string_put(fract->mlx, fract->win,
					30, 140, 0x39a4b2, "Change Color = 1 - 6");
	mlx_string_put(fract->mlx, fract->win,
					30, 160, 0x39a4b2, "Change Style = 1 - 3");
	mlx_string_put(fract->mlx, fract->win,
					30, 180, 0x39a4b2, "Reset cord = enter");
	mlx_string_put(fract->mlx, fract->win,
					30, 200, 0x39a4b2, "Move Julia = space");
}
