/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:51:23 by oshyiata          #+#    #+#             */
/*   Updated: 2019/04/09 13:46:46 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_usage(void)
{
	ft_putendl("Usage: ./fractol [number]\n1 - for mandelbrot\n"
				"2 - for julia\n3 - for newton");
	exit(0);
}

int		exit_x(void)
{
	exit(1);
}

void	check_main(int argc, char *argv[], t_fractol *fract)
{
	if (argc == 2)
	{
		fract->mlx = mlx_init();
		fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Fractol");
		if (argv[1][0] == '1' && argv[1][1] == '\0')
			mandelbrot_init(fract);
		else if (argv[1][0] == '2' && argv[1][1] == '\0')
		{
			julia_init(fract);
			mlx_hook(fract->win, 6, 0, mouse_julia, fract);
		}
		else if (argv[1][0] == '3' && argv[1][1] == '\0')
			newton_init(fract);
		else
			ft_usage();
		put_text(fract);
		mlx_hook(fract->win, 2, 0, set_key, fract);
		mlx_hook(fract->win, 17, 0, exit_x, fract);
		mlx_mouse_hook(fract->win, mousem, fract);
		mlx_loop(fract->mlx);
	}
	else
		ft_usage();
}

int		main(int argc, char *argv[])
{
	t_fractol *fract;

	if (!(fract = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	check_main(argc, argv, fract);
	return (0);
}
