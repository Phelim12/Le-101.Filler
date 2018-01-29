/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_filler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 18:04:05 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/28 18:04:05 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		ft_distance_pos(t_pos a, t_pos b)
{
	int dis_y;
	int	dis_x;

	dis_y = 0;
	dis_x = 0;
	if (a.y < b.y)
		while ((a.y + dis_y) < b.y)
			dis_y++;
	else
		while ((b.y + dis_y) < a.y)
			dis_y++;
	if (a.x < b.x)
		while ((a.x + dis_x) < b.x)
			dis_x++;
	else
		while ((b.x + dis_x) < a.x)
			dis_x++;
	return (dis_x + dis_y);
}

int		ft_place_pcs(t_game info, int map_y, int map_x)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = -1;
	while (++y < info.height_pcs)
	{
		x = -1;
		while (++x < info.width_pcs)
		{
			if (info.map[map_y + y][map_x + x] == '2' && info.pcs[y][x] == '1')
				return (0);
			if (info.map[map_y + y][map_x + x] == '1' && info.pcs[y][x] == '1')
				count++;
		}
	}
	if (count == 1)
		return (1);
	return (0);
}

t_pos	ft_print_good_solve(t_game info, t_pos *all, int cur)
{
	t_pos print;
	int dis1;
	int dis2;

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

int		ft_check_dist(t_game info, t_pos place)
{
	t_pos tmp;
	int dis_y;
	int	dis_x;
	int	dist1;
	int dist2;

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

int		ft_play(t_game info)
{
	t_pos	print;
	t_pos	*all;
	int		cur;
	int		y;
	int		x;

	y = -1;
	cur = 0;
	all = (t_pos *)malloc(sizeof(t_pos) * (info.height_map * info.width_map));
	while (info.map[++y] && ((y + info.height_pcs) <= info.height_map))
	{
		x = -1;
		while (info.map[y][++x] && ((x + info.width_pcs) <= info.width_map))
		{
			if (ft_place_pcs(info, y, x) == 1)
			{	
				all[cur].y = y;
				all[cur++].x = x;
			}
		}
	}
	if (cur == 0)
		return (0);
	print = ft_print_good_solve(info, all, cur);
	ft_printf("%d %d\n", print.y, print.x);
	return (1);
}