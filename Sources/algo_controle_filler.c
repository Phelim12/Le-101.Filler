/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_controle_filler.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 22:00:06 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 22:00:06 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

char	**ft_new_map(t_game info, t_pos pos, int y, int x)
{
	char **ret;

	ret = (char **)malloc(sizeof(char *) * (info.height_map + 1));
	while (info.map[++y])
		ret[y] = ft_strdup(info.map[y]);
	ret[y] = NULL;
	y = pos.y;
	while (y < (pos.y + info.height_pcs))
	{
		x = pos.x;
		while (x < (pos.x + info.width_pcs))
		{
			ret[y][x] = info.pcs[y - pos.y][x - pos.x];
			x++;
		}
		y++;
	}
	return (ret);
}

void	ft_fill_new_tab(t_game info, char **tab, int y, int x)
{
	int s_x;
	int	s_y;

	s_y = y;
	s_x = x;
	while (x < info.width_map && tab[y][x] != '1')
	{
		tab[y][x] = (tab[y][x] == '2') ? '2' : '3';
		x++;
	}
	x = s_x;
	while (x >= 0 && tab[y][x] != '1')
	{
		tab[y][x] = (tab[y][x] == '2') ? '2' : '3';
		x--;
	}
	x = s_x;
	while (y < info.height_map && tab[y][x] != '1')
	{
		tab[y][x] = (tab[y][x] == '2') ? '2' : '3';
		y++;
	}
	y = s_y;
	while (y >= 0 && tab[y][x] != '1')
	{
		tab[y][x] = (tab[y][x] == '2') ? '2' : '3';
		y--;
	}
}

int		ft_check_ncase(t_game info, t_pos pos)
{
	char	**tab;
	int		y;
	int		x;

	y = -1;
	tab = ft_new_map(info, pos, -1, 0);
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
			if (tab[y][x] == '2')
				ft_fill_new_tab(info, tab, y, x);
	}
	return (ft_count_pos(tab, 3));
}
