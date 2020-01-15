/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:50:34 by oshyiata          #+#    #+#             */
/*   Updated: 2019/04/09 13:31:24 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			mandelbrot_init(t_fractol *fract)
{
	fract->f = mandelbrot;
	fract->zoom = 0.3;
	fract->move_x = -0.5;
	fract->move_y = 0;
	fract->r = 9;
	fract->g = 15;
	fract->b = 8.5;
	threads(fract);
}

void			mandelbrot_3(t_var var, void *thred)
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

void			mandelbrot_4(t_var *var)
{
	while (var->i < var->max_iter)
	{
		var->old_re = var->new_re;
		var->old_im = var->new_im;
		var->new_re = var->old_re * var->old_re - var->old_im *
		var->old_im + var->pr;
		var->new_im = 2 * var->old_re * var->old_im + var->pi;
		if ((var->new_re * var->new_re + var->new_im * var->new_im) > 4)
			break ;
		var->i++;
	}
}

void			mandelbrot_2(t_var var, void *thred)
{
	t_threads	*threads;

	threads = (t_threads *)thred;
	while (var.x < WIDTH)
	{
		var.pr = (var.x - WIDTH / 2) / (threads->fractol->zoom * WIDTH) +
		threads->fractol->move_x;
		var.pi = (var.y - HEIGHT / 2) / (threads->fractol->zoom * HEIGHT) +
		threads->fractol->move_y;
		var.max_iter = 300;
		var.new_re = 0;
		var.new_im = 0;
		var.old_re = 0;
		var.old_im = 0;
		var.i = 0;
		mandelbrot_4(&var);
		mandelbrot_3(var, thred);
		var.x++;
	}
}

void			*mandelbrot(void *thred)
{
	t_threads	*threads;
	t_var		var;

	threads = (t_threads *)thred;
	var.y = threads->y_start;
	while (var.y < threads->y_end)
	{
		var.x = 0;
		mandelbrot_2(var, thred);
		var.y++;
	}
	return (0);
}
