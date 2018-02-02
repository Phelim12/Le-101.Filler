/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   params_filler.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 21:53:07 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 21:53:07 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		ft_get_player(t_game *info)
{
	char *line;

	get_next_line(0, &line);
	if (line[10] == '1')
		info->player = 1;
	else if (line[10] == '2')
		info->player = 2;
	else
	{
		free(line);
		return (-1);
	}
	free(line);
	return (1);
}

void	ft_good_square(char player, char *p1, char *p2)
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

int		ft_pos_start_enemy(t_game *info)
{
	int block;
	int	ret;
	int y;
	int x;

	y = -1;
	ret = 0;
	block = 0;
	while (info->map[++y])
	{
		x = -1;
		while (info->map[y][++x])
		{
			if (info->map[y][x] == '2' && block == 0)
			{
				if (y > (info->height_map / 2))
					ret += 2;
				if (x > (info->width_map / 2))
					ret += 1;
				block = 1;
			}
		}
	}
	return (ret);
}
