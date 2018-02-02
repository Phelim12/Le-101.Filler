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

void	ft_reducto_diag1(t_game info, char **tab, int y, int x)
{
	int dia;

	dia = 0;
	while ((x + dia) < info.width_map && (y + dia) < info.height_map &&
	tab[(y + dia)][(x + dia)] != '1')
	{
		if (tab[(y + dia)][(x + dia)] == '0')
			tab[(y + dia)][(x + dia)] = '3';
		dia++;
	}
	dia = 0;
	while ((x - dia) >= 0 && (y - dia) >= 0 &&
	tab[(y - dia)][(x - dia)] != '1')
	{
		if (tab[(y - dia)][(x - dia)] == '0')
			tab[(y - dia)][(x - dia)] = '3';
		dia++;
	}
}

void	ft_reducto_diag2(t_game info, char **tab, int y, int x)
{
	int dia1;
	int dia2;

	dia1 = 0;
	dia2 = 0;
	while ((x + dia1) < info.width_map && (y - dia2) >= 0 &&
	tab[(y - dia2)][(x + dia1)] != '1')
	{
		if (tab[(y - dia2)][(x + dia1)] == '0')
			tab[(y - dia2)][(x + dia1)] = '3';
		dia1++;
		dia2++;
	}
	dia1 = 0;
	dia2 = 0;
	while ((x - dia1) >= 0 && (y + dia2) < info.height_map &&
	tab[(y + dia2)][(x - dia1)] != '1')
	{
		if (tab[(y + dia2)][(x - dia1)] == '0')
			tab[(y + dia2)][(x - dia1)] = '3';
		dia1++;
		dia2++;
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
				ft_reducto_diag1(info, tab, y, x);
				ft_reducto_diag2(info, tab, y, x);
			}
	}
	ret = ft_count_pos(info, tab, 3);
	ft_free_tab(&tab);
	return (ret);
}
