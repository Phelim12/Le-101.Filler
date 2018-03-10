/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_filler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 16:09:56 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 16:09:56 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

t_pos	ft_print_end(t_game info, t_pos *all, int cur)
{
	int static alternate = 0;
	
	if (alternate == 2)
		alternate = 0;
	if (alternate == 0)
		info.way = ft_fill_pos((info.height_map / 4), 0);
	else
		info.way = ft_fill_pos((info.height_map / 4), (info.width_map - 1));
	alternate++;
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

void	ft_print_good_solve(t_game *info, t_pos *all, int cur, int s)
{
	int		ncase1;
	int		ncase2;
	int		s_cur;

	s_cur = -1;
	ncase1 = -1;
	while (++s_cur < cur)
	{
		if (ncase1 > (ncase2 = ft_reducto(*info, all[s_cur])) || ncase1 == -1)
		{
			ncase1 = ncase2;
			info->print = ft_fill_pos(all[s_cur].y, all[s_cur].x);
		}
	}
	if (s >= 0)
		info->print = ft_print_dist(*info, all, cur);
	if ((info->print.y == all[0].y && info->print.x == all[0].x) && cur > 1 &&
		ft_reducto(*info, all[0]) == ft_reducto(*info, all[1]))
		info->print = ft_print_end(*info, all, cur);
}

int		ft_play(t_game *info, int rush)
{
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
			if (ft_can_place_pcs(*info, y, x) == 1)
				all[cur++] = ft_fill_pos(y, x);
	}
	if (cur == 0)
	{
		free(all);
		return (0);
	}
	ft_print_good_solve(info, all, cur, rush);
	ft_printf("%d %d\n", info->print.y, info->print.x);
	free(all);
	return (1);
}
