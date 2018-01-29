/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_filler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 17:23:05 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/28 17:23:05 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void		ft_get_player(t_game *info)
{
	char *line;

	get_next_line(0, &line);
	if (line[10] == '1')
		info->player = 1;
	if (line[10] == '2')
		info->player = 2;
	free(line);
}

void		ft_pass_lines(int nb)
{
	char	*line;

	while (nb-- > 0)
	{
		get_next_line(0, &line);
		free(line);
	}
}

void		ft_good_square(char player, char *p1, char *p2)
{
	if (player == 1)
	{
		*p1 = 1;
		*p2 = 2;
	}
	if (player == 2)
	{
		*p1 = 2;
		*p2 = 1;
	}
}

void	ft_modif_pcs(t_game *info)
{
	int y;
	int	x;

	y = -1;
	while (info->pcs[++y])
	{
		x = -1;
		while (info->pcs[y][++x])
		{
			if (info->pcs[y][x] == '.')
				info->pcs[y][x] = '0';
			if (info->pcs[y][x] == '*')
				info->pcs[y][x] = '1';
		}
	}
}

void	ft_modif_map(t_game *info)
{
	int y;
	int	x;

	y = -1;
	while (info->map[++y])
	{
		x = -1;
		while (info->map[y][++x])
		{
			if (info->map[y][x] == '.')
				info->map[y][x] = '0';
			if (info->map[y][x] == 'O' || info->map[y][x] == 'o')
				info->map[y][x] = (info->square_o + 48);
			if (info->map[y][x] == 'X' || info->map[y][x] == 'x')
				info->map[y][x] = (info->square_x + 48);
		}
	}
}