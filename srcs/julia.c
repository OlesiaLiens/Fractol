/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:09:32 by oshyiata          #+#    #+#             */
/*   Updated: 2019/04/07 15:09:33 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			julia_init(t_fractol *fract)
{
	fract->status = 0;
	fract->f = julia;
	fract->zoom = 0.3;
	fract->move_x = 0;
	fract->move_y = 0;
	fract->r = 9;
	fract->g = 15;
	fract->b = 8.5;
	fract->x = 0;
	fract->y = 0;
	threads(fract);
}

void			julia_3(t_var var, void *thred)
{
	t_threads	*threads;

	threads = (t_threads *)thred;
	var.t = (double)var.i / (double)var.max_iter;
	var.r = (int)(threads->fractol->r * (1 - var.t) * var.t *
	var.t * var.t * 255);
	var.g = (int)(threads->fractol->g * (1 - var.t) * (1 - var.t) *
	var.t * var.t * 255);
	var.b = (int)(threads->fractol->b * (1 - var.t) * (1 - var.t) *
	(1 - var.t) *
	var.t * 255);
	threads->fractol->addr[var.x + (var.y * HEIGHT)] =
	var.i < var.max_iter ?
	get_int_from_color(var.r, var.g, var.b) : 0;
}

void			julia_2(t_var var, void *thred)
{
	t_threads	*threads;

	threads = (t_threads *)thred;
	while (var.x < WIDTH)
	{
		var.new_re = (var.x - WIDTH / 2) / (threads->fractol->zoom * WIDTH)
		+ threads->fractol->move_x;
		var.new_im = (var.y - HEIGHT / 2) /
		(threads->fractol->zoom * HEIGHT) +
		threads->fractol->move_y;
		var.i = 0;
		while (var.i < var.max_iter)
		{
			var.old_re = var.new_re;
			var.old_im = var.new_im;
			var.new_re = var.old_re * var.old_re - var.old_im
			* var.old_im + var.c_re;
			var.new_im = 2 * var.old_re * var.old_im + var.c_im;
			if ((var.new_re * var.new_re + var.new_im * var.new_im) > 4)
				break ;
			var.i++;
		}
		julia_3(var, thred);
		var.x++;
	}
}

void			julia_1(t_var var, void *thred)
{
	t_threads	*threads;

	threads = (t_threads *)thred;
	while (var.y < threads->y_end)
	{
		var.x = 0;
		julia_2(var, thred);
		var.y++;
	}
}

void			*julia(void *thred)
{
	t_threads	*threads;
	t_var		var;

	threads = (t_threads *)thred;
	var.max_iter = 300;
	var.c_re = -0.7 + threads->fractol->x / 344;
	var.c_im = 0.27015 + threads->fractol->y / 344;
	var.y = 0;
	var.y = threads->y_start;
	julia_1(var, thred);
	return (0);
}
