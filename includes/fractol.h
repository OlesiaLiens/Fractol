/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:51:53 by oshyiata          #+#    #+#             */
/*   Updated: 2019/04/07 11:51:54 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# define NUM_THREADS 4
# define HEIGHT 700
# define WIDTH 700

typedef struct	s_var
{
	int			part;
	int			iter;
	pthread_t	trd[NUM_THREADS];
	int			c;
	int			d;
	int			e;
	void		*img;
	double		pr;
	double		pi;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	int			max_iter;
	int			y;
	int			x;
	int			i;
	double		t;
	int			r;
	int			g;
	int			b;
	double		tmp;
	double		c_re;
	double		c_im;
}				t_var;

typedef struct	s_fractol
{
	double		x;
	double		y;
	void		*mlx;
	void		*win;
	int			*addr;
	double		zoom;
	double		move_x;
	double		move_y;
	double		r;
	double		g;
	double		b;
	void		*(*f)(void *);
	int			status;
}				t_fractol;

typedef struct	s_threads
{
	int			y_start;
	int			y_end;
	t_fractol	*fractol;
}				t_threads;

void			mandelbrot_init(t_fractol *fract);
void			newton_init(t_fractol *fract);
void			julia_init(t_fractol *fract);
void			*mandelbrot(void *thred);
void			threads(t_fractol *fract);
int				get_int_from_color(int red, int green, int blue);
int				mousem(int b, int x, int y, t_fractol *a);
int				set_key(int key, t_fractol *fract);
void			*julia(void *thred);
int				mouse_julia(int x, int y, t_fractol *fractol);
void			*newton(void *thred);
void			put_text(t_fractol *fract);

#endif
