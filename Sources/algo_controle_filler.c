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

int		ft_start_reducto(t_game info)
{
	int y;
	int x;

	y = 0;
	while (++y < (info.height_map - 2))
	{
		x = 0;
		while (++x < (info.width_map - 2))
		{
			if (info.map[y][x] == '2' && 
			(info.map[y][x - 1] == '1' || info.map[y][x + 1] == '1' || 
			info.map[y - 1][x] == '1' || info.map[y + 1][x] == '1' || 
			info.map[y + 1][x + 1] == '1' || info.map[y - 1][x - 1] == '1' ||
			info.map[y + 1][x - 1] == '1' || info.map[y - 1][x + 1] == '1'))
				return (-10);
		}
	}
	return (2);
}

void	ft_reducto_ordinate(t_game info, char **tab, int y, int x)
{
	int s_y;

	s_y = y;
	while (y < info.height_map && tab[y][x] != '1')
	{
		if (tab[y][x] == '0')
			tab[y][x] = '3';  
		y++;
	}
	y = s_y;
	while (y >= 0 && tab[y][x] != '1')
	{
		if (tab[y][x] == '0')
			tab[y][x] = '3';  
		y--;
	}
}

void	ft_reducto_abscissa(t_game info, char **tab, int y, int x)
{
	int s_x;

	s_x = x;
	while (x < info.width_map && tab[y][x] != '1')
	{
		if (tab[y][x] == '0')
			tab[y][x] = '3';  
		x++;
	}
	x = s_x;
	while (x >= 0 && tab[y][x] != '1')
	{
		if (tab[y][x] == '0')
			tab[y][x] = '3';  
		x--;
	}
	
}

int		ft_reducto(t_game info, t_pos pos)
{
	char	**tab;
	int		ret;
	int		y;
	int		x;

	y = -1;
	tab = ft_new_map(info, pos, -1, 0);
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
			if (tab[y][x] == '2')
			{
				ft_reducto_ordinate(info, tab, y, x);
				ft_reducto_abscissa(info, tab, y, x);
			}
	}
	ret = ft_count_pos(info, tab, 3);
	ft_free_tab(&tab);
	return (ret);
}
