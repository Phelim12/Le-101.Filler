/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   refresh_game_filler.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 21:54:33 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 21:54:33 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

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

void	ft_refresh_pcs(t_game *info)
{
	int		cur;

	cur = 0;
	info->pcs = (char **)malloc(sizeof(char *) * info->height_pcs + 1);
	while (cur < info->height_pcs)
		get_next_line(0, &info->pcs[cur++]);
	info->pcs[cur] = NULL;
	ft_modif_pcs(info);
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
			if (info->player == 1 && info->map[y][x] == 'x')
				info->way = ft_fill_pos(y, x);
			if (info->player == 2 && info->map[y][x] == '0')
				info->way = ft_fill_pos(y, x);
			if (info->map[y][x] == '.')
				info->map[y][x] = '0';
			if (info->map[y][x] == 'O' || info->map[y][x] == 'o')
				info->map[y][x] = (info->square_o + 48);
			if (info->map[y][x] == 'X' || info->map[y][x] == 'x')
				info->map[y][x] = (info->square_x + 48);
		}
	}
}

void	ft_refresh_map(t_game *info, char *line, int turn)
{
	int		start;
	int		cur;

	cur = -1;
	ft_pass_lines(1);
	ft_good_square(info->player, &info->square_o, &info->square_x);
	info->map = (char **)malloc(sizeof(char *) * info->height_map + 1);
	while (++cur < info->height_map)
	{
		get_next_line(0, &line);
		start = (ft_strlen(line) - info->width_map);
		info->map[cur] = ft_strsub(line, start, info->width_map);
		free(line);
	}
	info->map[cur] = NULL;
	ft_modif_map(info);
	if (turn == 0)
		info->start_enemy = ft_pos_start_enemy(info);
}

int		ft_refresh_game(t_game *info, int turn)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau ", 7) == 0)
		{
			info->width_map = ft_atoi(ft_strrchr(line, 32));
			info->height_map = ft_atoi(ft_strchr(line, 32));
			free(line);
			ft_refresh_map(info, line, turn);
		}
		else if (ft_strncmp(line, "Piece ", 5) == 0)
		{
			info->width_pcs = ft_atoi(ft_strrchr(line, 32));
			info->height_pcs = ft_atoi(ft_strchr(line, 32));
			ft_refresh_pcs(info);
			free(line);
			return (1);
		}
		else
			free(line);
	}
	return (0);
}