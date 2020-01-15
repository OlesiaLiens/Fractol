/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:52:35 by oshyiata          #+#    #+#             */
/*   Updated: 2019/04/08 09:52:37 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			newton_init(t_fractol *fract)
{
	fract->f = newton;
	fract->zoom = 0.3;
	fract->move_x = 0;
	fract->move_y = 0;
	fract->r = 17.5;
	fract->g = 32;
	fract->b = 6.5;
	threads(fract);
}

void			newton_2(t_var *var, void *thred)
{
	t_threads	*threads;

	threads = (t_threads *)thred;
	var->t = (double)var->i / (double)var->max_iter;
	var->r = (int)(threads->fractol->r * (1 - var->t)
	* var->t * var->t * var->t * 255);
	var->g = (int)(threads->fractol->g * (1 - var->t)
	* (1 - var->t) * var->t * var->t * 255);
	var->b = (int)(threads->fractol->b * (1 - var->t)
	* (1 - var->t) * (1 - var->t) * var->t * 255);
	threads->fractol->addr[var->x + (var->y * HEIGHT)] =
	var->i < var->max_iter ?
	get_int_from_color(var->r, var->g, var->b) : 0;
}

void			newton_1(t_var *var)
{
	while (var->tmp > 0.000001 && ++var->i < var->max_iter)
	{
		var->old_re = var->new_re;
		var->old_im = var->new_im;
		var->tmp = (var->new_re * var->new_re + var->new_im * var->new_im)
		* (var->new_re * var->new_re + var->new_im * var->new_im);
		var->new_re = (2 * var->new_re * var->tmp + var->new_re
		* var->new_re - var->new_im * var->new_im)
		/ (3.0 * var->tmp);
		var->new_im = (2 * var->new_im * (var->tmp - var->old_re))
		/ (3.0 * var->tmp);
		var->tmp = (var->new_re - var->old_re)
		* (var->new_re - var->old_re) + (var->new_im - var->old_im)
		* (var->new_im - var->old_im);
	}
}

void			*newton(void *thred)
{
	t_threads	*threads;
	t_var		var;

	threads = (t_threads *)thred;
	var.max_iter = 300;
	var.y = 0;
	var.y = threads->y_start;
	while (var.y < threads->y_end)
	{
		var.x = 0;
		while (var.x < WIDTH)
		{
			var.new_re = (var.x - WIDTH / 2) /
				(threads->fractol->zoom * WIDTH) + threads->fractol->move_x;
			var.new_im = (var.y - HEIGHT / 2) /
				(threads->fractol->zoom * HEIGHT) + threads->fractol->move_y;
			var.i = 0;
			var.tmp = 1.0;
			newton_1(&var);
			newton_2(&var, thred);
			var.x++;
		}
		var.y++;
	}
	return (0);
}
