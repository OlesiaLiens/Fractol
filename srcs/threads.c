/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:22:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/08 10:22:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			threads_free(t_threads **p, t_var var, t_fractol *fract)
{
	while (++var.iter < NUM_THREADS)
		free(p[var.iter]);
	free(p);
	put_text(fract);
}

int				get_int_from_color(int red, int green, int blue)
{
	red = (red << 16) & 0x00FF0000;
	green = (green << 8) & 0x0000FF00;
	blue = blue & 0x000000FF;
	return (0x000000 | red | green | blue);
}

void			threads(t_fractol *fract)
{
	t_var		var;
	t_threads	**p;

	var.iter = -1;
	p = (t_threads**)malloc(sizeof(t_threads*) * NUM_THREADS);
	var.part = WIDTH / NUM_THREADS;
	var.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->addr = (int*)mlx_get_data_addr(var.img, &var.c, &var.d, &var.e);
	while (++var.iter < NUM_THREADS)
	{
		p[var.iter] = (t_threads*)malloc(sizeof(t_threads));
		p[var.iter]->fractol = fract;
		p[var.iter]->y_start = var.iter * var.part;
		p[var.iter]->y_end = p[var.iter]->y_start + var.part;
		if (var.iter == (NUM_THREADS - 1))
			p[var.iter]->y_end = WIDTH;
		pthread_create(&var.trd[var.iter], NULL, fract->f, (void *)p[var.iter]);
	}
	var.iter = -1;
	while (++var.iter < NUM_THREADS)
		pthread_join(var.trd[var.iter], NULL);
	mlx_put_image_to_window(fract->mlx, fract->win, var.img, 0, 0);
	mlx_destroy_image(fract->mlx, var.img);
	var.iter = -1;
	threads_free(p, var, fract);
}
