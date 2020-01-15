/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:20:43 by oshyiata          #+#    #+#             */
/*   Updated: 2019/04/09 13:35:55 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				reset_zoom(t_fractol *fract)
{
	fract->zoom = 0.3;
	fract->move_x = -0.5;
	fract->move_y = 0;
	return (0);
}

int				set_color(int key, t_fractol *fract)
{
	if (key == 18 || key == 19)
		fract->r += key == 18 ? 0.5 : -0.5;
	else if (key == 20 || key == 21)
		fract->g += key == 20 ? 0.5 : -0.5;
	else
		(fract->b += key == 23 ? 0.5 : -0.5);
	if (key == 83 || key == 84)
	{
		fract->r = key == 83 ? 21 : 104.5;
		fract->g = key == 83 ? 69.0 : 8.0;
		fract->b = key == 83 ? 0 : 9.0;
		fract->y = key == 83 ? 162 : -21;
		fract->x = key == 83 ? 226 : -19;
	}
	if (key == 85)
	{
		fract->r = 124;
		fract->g = 7.5;
		fract->b = 9.0;
		fract->y = -277;
		fract->x = 63;
	}
	return (0);
}

int				set_key(int key, t_fractol *fract)
{
	if (key == 123 || key == 124)
	{
		fract->move_x += key == 123 ? 0.3 / fract->zoom : -0.3 / fract->zoom;
	}
	else if (key == 125 || key == 126)
	{
		fract->move_y += key == 125 ? 0.3 / fract->zoom : -0.3 / fract->zoom;
	}
	else if (key == 78 || key == 69)
	{
		fract->zoom *= key == 78 ? 0.9 : 1.1;
	}
	else if ((key >= 18 && key <= 23) || key == 83 || key == 84 || key == 85)
		set_color(key, fract);
	else if (key == 49)
		fract->status = !fract->status;
	else if (key == 36)
		reset_zoom(fract);
	else if (key == 53)
		exit(0);
	threads(fract);
	return (0);
}

int				mousem(int b, int x, int y, t_fractol *a)
{
	if ((b == 4 || b == 5) &&
	x >= 0 && x <= WIDTH &&
	y >= 0 && y <= HEIGHT)
	{
		x = x - (WIDTH / 2);
		y = y - (HEIGHT / 2);
		a->zoom *= b == 5 ? 0.9 : 1.1;
		if (b == 4)
		{
			a->move_x = a->move_x + (((double)x / (WIDTH * 10)) / a->zoom);
			a->move_y = a->move_y + (((double)y / (HEIGHT * 10)) / a->zoom);
		}
		else
		{
			a->move_x = a->move_x - (((double)x / (WIDTH * 10)) / a->zoom);
			a->move_y = a->move_y - (((double)y / (HEIGHT * 10)) / a->zoom);
		}
		threads(a);
	}
	return (0);
}

int				mouse_julia(int x, int y, t_fractol *fractol)
{
	if (fractol->status)
	{
		fractol->x = x - (WIDTH / 2);
		fractol->y = y - (HEIGHT / 2);
		threads(fractol);
	}
	return (0);
}
