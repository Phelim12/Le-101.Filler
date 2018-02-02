/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_way_filler.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 16:13:56 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 16:13:56 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_go_alpha_point(t_game *info)
{
	if (info->start_enemy == 0)
	{
		info->way.y = 0;
		info->way.x = (info->width_map - 1);
	}
	if (info->start_enemy == 1)
	{
		info->way.y = 0;
		info->way.x = 0;
	}
	if (info->start_enemy == 2)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = (info->width_map - 1);
	}
	if (info->start_enemy == 3)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = 0;
	}
}

void	ft_go_beta_point(t_game *info)
{
	if (info->start_enemy == 0)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = 0;
	}
	if (info->start_enemy == 1)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = (info->width_map - 1);
	}
	if (info->start_enemy == 2)
	{
		info->way.y = 0;
		info->way.x = 0;
	}
	if (info->start_enemy == 3)
	{
		info->way.y = 0;
		info->way.x = (info->width_map - 1);
	}
}

int		ft_distance_pos(t_pos a, t_pos b)
{
	int ret;

	ret = 0;
	if (a.y < b.y)
		ret += b.y - a.y;
	else
		ret += a.y - b.y;
	if (a.x < b.x)
		ret += b.x - a.x;
	else
		ret += a.x - b.x;
	return (ret);
}

int		ft_check_dist(t_game info, t_pos place)
{
	t_pos	tmp;
	int		dis_y;
	int		dis_x;
	int		dist1;
	int		dist2;

	dis_y = -1;
	dist1 = (info.width_map + info.height_map);
	while (info.pcs[++dis_y])
	{
		dis_x = -1;
		while (info.pcs[dis_y][++dis_x])
			if (info.pcs[dis_y][dis_x] == '1')
			{
				tmp.y = (place.y + dis_y);
				tmp.x = (place.x + dis_x);
				dist2 = ft_distance_pos(info.way, tmp);
				if (dist2 < dist1)
					dist1 = dist2;
			}
	}
	return (dist1);
}

t_pos	ft_print_dist(t_game info, t_pos *all, int cur)
{
	t_pos	print;
	int		dis1;
	int		dis2;

	print.y = all[0].y;
	print.x = all[0].x;
	dis1 = (info.width_map + info.height_map);
	while (cur-- > 0)
	{
		dis2 = ft_check_dist(info, all[cur]);
		if (dis2 <= dis1)
		{
			dis1 = dis2;
			print.y = all[cur].y;
			print.x = all[cur].x;
		}
	}
	return (print);
}
