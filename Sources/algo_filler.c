/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_filler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 22:05:28 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 22:05:28 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

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
	int check;
	int ncase1;
	int ncase2;
	int	s_cur;


	s_cur = cur;
	ncase1 = -1;
	while (cur-- > 0)
	{
		if (ncase1 > (ncase2 = ft_check_ncase(info, all[cur])) || ncase1 == -1)
		{
			ncase1 = ncase2;
			print.y = all[cur].y;
			print.x = all[cur].x;
		}
	}
	if (print.y == all[s_cur - 1].y && print.x == all[s_cur - 1].x)
		ft_go_opposed_corner(&info);
	if (rush >= 0 || (print.y == all[s_cur - 1].y && print.x == all[s_cur - 1].x))
		return (ft_print_dist(info, all, s_cur));
	return (print);
}

int		ft_play(t_game info, int rush)
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
			if (ft_can_place_pcs(info, y, x) == 1)
				all[cur++] = ft_fill_pos(y, x);
		}
	}
	if (cur == 0)
		return (0);
	print = ft_print_good_solve(info, all, cur, rush);
	ft_printf("%d %d\n", print.y, print.x);
	return (1);
}