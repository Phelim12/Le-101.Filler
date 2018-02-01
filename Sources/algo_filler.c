/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_filler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 17:30:17 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 17:30:17 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"


t_pos		ft_print_on_side(t_game info, t_pos *all, int cur)
{
	int	all_y;
	int all_x;
	int	div;
	int	y;
	int	x;

	y = -1;
	div = 0;
	all_y = 0;
	all_x = 0;
	while (++y < info.height_map)
	{
		x = -1;
		while (++x < info.width_map)
		{
			if (info.map[y][x] == '2' || info.map[y][x] == '1')
			{	
				all_y += y;
				all_x += x;
				div++;
			}
		}
	}
	info.way = ft_fill_pos((all_y / div), (all_x / div));
	return (ft_print_dist(info, all, cur));
}

int		ft_can_place_pcs(t_game info, int map_y, int map_x)
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

t_pos	ft_print_good_solve(t_game info, t_pos *all, int cur, int rush)
{
	t_pos print;
	int ncase1;
	int ncase2;
	int	s_cur;

	s_cur = -1;
	ncase1 = -1;
	while (++s_cur < cur)
	{
		if (ncase1 > (ncase2 = ft_reducto(info, all[s_cur])) || ncase1 == -1)
		{
			ncase1 = ncase2;
			print.y = all[s_cur].y;
			print.x = all[s_cur].x;
		}
	}
	if (rush >= 0)
		return (ft_print_dist(info, all, cur));
	if ((print.y == all[0].y && print.x == all[0].x) && cur > 1 && 
		ft_reducto(info, all[0]) == ft_reducto(info, all[1]))
		return (ft_print_on_side(info, all, cur));
	return (print);
}

int		ft_play(t_game *info, int rush)
{
	t_pos	print;
	t_pos	*all;
	int		cur;
	int		y;
	int		x;

	y = -1;
	cur = 0;
	all = (t_pos *)malloc(sizeof(t_pos) * (info->height_map * info->width_map));
	while (info->map[++y] && ((y + info->height_pcs) <= info->height_map))
	{
		x = -1;
		while (info->map[y][++x] && ((x + info->width_pcs) <= info->width_map))
		{
			if (ft_can_place_pcs(*info, y, x) == 1)
				all[cur++] = ft_fill_pos(y, x);
		}
	}
	if (cur == 0)
	{
		free(all);
		return (0);
	}
	print = ft_print_good_solve(*info, all, cur, rush);
	ft_printf("%d %d\n", print.y, print.x);
	free(all);
	return (1);
}