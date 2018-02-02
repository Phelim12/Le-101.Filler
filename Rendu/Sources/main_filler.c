/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 15:39:26 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 15:39:26 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		ft_start_reducto(t_game info)
{
	int y;
	int x;

	y = -1;
	while (++y < info.height_map)
	{
		x = -1;
		while (++x < info.width_map)
		{
			if ((info.map[y][x] == '1' && ft_close_enemy(info, y, x, 1)) ||
				(info.map[y][x] == '2' && ft_close_enemy(info, y, x, 2)))
				return (-10);
		}
	}
	return (2);
}

int		ft_close_enemy(t_game info, int s_y, int s_x, int player)
{
	int y;
	int x;

	y = 0;
	while ((y + s_y) < info.height_map && (y < 3))
	{
		x = 0;
		while ((x + s_x) < info.width_map && (x < 3))
		{
			if ((player == 1 && info.map[y + s_y][x + s_x] == '2') ||
				(player == 2 && info.map[y + s_y][x + s_x] == '1'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_check_height_pcs(t_game info)
{
	int	ret1;
	int	ret2;
	int y;

	y = -1;
	ret1 = -1;
	ret2 = -1;
	while (++y < info.height_pcs)
	{
		if (ft_strchr(info.pcs[y], '1') && ret1 != -1)
			ret2 = (y + 1);
		if (ft_strchr(info.pcs[y], '1') && ret1 == -1)
			ret1 = y;
	}
	if (ret2 == -1)
		return (ret1);
	return (ret2 - ret1);
}

int		ft_check_width_pcs(t_game info)
{
	int	ret1;
	int	ret2;
	int	y;
	int	x;

	x = -1;
	ret1 = -1;
	ret2 = -1;
	while (++x < info.width_pcs)
	{
		y = -1;
		while (++y < info.height_pcs)
			if (info.pcs[y][x] == '1')
				break ;
		if (y < info.height_pcs && info.pcs[y][x] == '1' && ret1 != -1)
			ret2 = (x + 1);
		if (y < info.height_pcs && info.pcs[y][x] == '1' && ret1 == -1)
			ret1 = x;
	}
	if (ret2 == -1)
		return (ret1);
	return (ret2 - ret1);
}

int		main(void)
{
	t_game	info;
	int		turn;

	turn = 0;
	if (ft_get_player(&info) == -1)
	{
		ft_printf("Bad player info\n");
		return (0);
	}
	while (1)
	{
		ft_refresh_game(&info, turn);
		if (ft_check_height_pcs(info) > ft_check_width_pcs(info))
			ft_go_alpha_point(&info);
		else
			ft_go_beta_point(&info);
		if (ft_play(&info, ft_start_reducto(info)) == 0)
			break ;
		ft_free_game(&info);
		turn++;
	}
	ft_free_game(&info);
	ft_printf("0 0\n");
	return (0);
}
