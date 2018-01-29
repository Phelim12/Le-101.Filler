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

int		ft_corner_alpha(t_game *info)
{
	int x;

	x = 0;
	while (x < 9 && x < info->width_map && x < info->height_map)
	{
		if (info->map[0][x] == '1')
			return (1);
		if (info->map[x][0] == '1')
			return (1);
		x++;
	}
	x = 0;
	while (x < 9 && x < info->width_map && x < info->height_map)
	{
		if (info->map[0][info->width_map - (x + 1)] == '1')
			return (1);
		if (info->map[x][info->width_map - 1] == '1')
			return (1);
		x++;
	}
	return (0);
}

int		ft_corner_beta(t_game *info)
{
	int x;

	x = 0;
	while (x < 7 && x < info->width_map && x < info->height_map)
	{
		if (info->map[info->height_map - 1][x] == '1')
			return (1);
		if (info->map[info->height_map - (x + 1)][0] == '1')
			return (1);
		x++;
	}
	x = 0;
	while (x < 7 && x < info->width_map && x < info->height_map)
	{
		if (info->map[info->height_map - 1][info->width_map - (x + 1)] == '1')
			return (1);
		if (info->map[info->height_map - (x + 1)][info->width_map - 1] == '1')
			return (1);
		x++;
	}
	return (0);
}

int		ft_check_col(t_game *info)
{
	int y;

	y = -1;
	while (info->map[++y])
	{
		if (info->map[y][0] == '1')
			return (1);
		if (info->map[y][info->width_map - 1] == '1')
			return (1);
	}
	return (0);
}

void	ft_go_alpha_point(t_game *info)
{
	if (info->start_enemy == 0 || info->start_enemy == 3)
	{
		info->way.y = 0; 
		info->way.x = (info->width_map - 1);
	}
	if (info->start_enemy == 1 || info->start_enemy == 2)
	{
		info->way.y = 0; 
		info->way.x = 0;
	}
}

void	ft_go_charli_point(t_game *info)
{
	info->way.y = (info->height_map / 2); 
	info->way.x = (info->width_map / 2);
}

void	ft_go_beta_point(t_game *info)
{
	if (info->start_enemy == 0 || info->start_enemy == 3)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = 0;
	}
	if (info->start_enemy == 1 || info->start_enemy == 2)
	{
		info->way.y = (info->height_map - 1); 
		info->way.x = (info->width_map - 1);
	}
}

void	ft_go_delta_point(t_game *info)
{
	if (info->start_enemy == 0)
	{
		info->way.y = 0;
		info->way.x = 0;
	}
	if (info->start_enemy == 1)
	{
		info->way.y = 0;
		info->way.x = (info->width_map - 1);
	}
	if (info->start_enemy == 2)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = 0;
	}
	if (info->start_enemy == 3)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = (info->width_map - 1);
	}
}

int		ft_dist_enemy(t_game info)
{
	t_pos tmp;
	int	dist1;
	int dist2;
	int	y;
	int x;

	y = -1;
	dist1 = (info.width_map + info.height_map);
	while (info.map[++y])
	{
		x = -1;
		while (info.map[y][++x])
			if (info.map[y][x] == '2')
			{
				tmp.y = y;
				tmp.x = x;
				dist2 = ft_distance_pos(info.way, tmp);
				if (dist2 < dist1)
					dist1 = dist2;
			}
	}
	return (dist1);
}

void	ft_check_way(t_game *info)
{
	static int	charli = 0;
	static int	delta = 0;
	int			dist_alpha;
	int			dist_beta;

	ft_go_beta_point(info);	
	dist_beta = ft_dist_enemy(*info);
	ft_go_alpha_point(info);
	dist_alpha = ft_dist_enemy(*info);
	if (dist_alpha < dist_beta && (ft_corner_alpha(info) == 1))
		ft_go_beta_point(info);
	else if (dist_alpha < dist_beta && (ft_corner_alpha(info) == 0))
		ft_go_alpha_point(info);
	else if (dist_alpha >= dist_beta && (ft_corner_beta(info) == 1))
		ft_go_alpha_point(info);
	else if (dist_alpha >= dist_beta && (ft_corner_beta(info) == 0))
		ft_go_beta_point(info);
	if (ft_corner_alpha(info) && ft_corner_beta(info) && 
		++charli < ((info->width_map * info->height_map) / 75))
		ft_go_charli_point(info);
	if (charli > ((info->width_map * info->height_map) / 75) && 
		++delta < ((info->width_map * info->height_map) / 20))
		ft_go_delta_point(info);
	if (delta > ((info->width_map * info->height_map) / 20))
		ft_go_charli_point(info);
}

int		main(int argc, char const *argv[])
{
	t_game	info;
	int		turn;
	
	turn = 0;
	ft_get_player(&info);
	while (1)
	{
		ft_refresh_game(&info, turn);
		ft_check_way(&info);
		//ft_printf("square %d\n", info.start_enemy);
		if (ft_play(info) == 0)
		{
			ft_printf("0 0\n");
			break ;
		}
		turn++;
	}
	return (0);
}

/*

//			Map03

p1 :	abanlin 	w w w w w
		carli 		w w w w w
		grati		w w w w w
		hcao 		w w w w w
		superjannot w w w w w
		lcharvol	w l l w w w w l w l
		qhonore		w l l l w l l l l w

p2 :	abanlin 	w w w w w
		carli 		w w w w w
		grati		w w w w w
		hcao 		w w w w w
		lcharvol	w w l w w l l w w w 
		qhonore		l l l l l l l l l l

//			Map01













*/

