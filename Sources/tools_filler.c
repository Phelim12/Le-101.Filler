/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_filler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 21:53:27 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 21:53:27 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

t_pos	ft_fill_pos(int y, int x)
{
	t_pos ret;

	ret.y = y;
	ret.x = x;
	return (ret);
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

int		ft_count_pos(char **tab, int player)
{
	int ret;
	int	y;
	int x;

	y = -1;
	ret = 0;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (player == 3 && (tab[y][x] == '2' || tab[y][x] == '3'))
				ret++;
			if (player == 2 && tab[y][x] == '2')
				ret++;
			if (player == 1 && tab[y][x] == '1')
				ret++;
		}
	}
	return (ret);
}