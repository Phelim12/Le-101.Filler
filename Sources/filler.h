/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 18:19:55 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 18:19:55 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_pos
{
	int	y;
	int x;
}				t_pos;

typedef struct	s_game
{
	t_pos	way;
	char	**pcs;
	char	**map;
	char	player;
	char	square_x;
	char	square_o;
	int		width_map;
	int		height_map;
	int		width_pcs;
	int		height_pcs;
	char	start_enemy;
}				t_game;



t_pos	ft_print_good_solve(t_game info, t_pos *all, int cur);
int		ft_check_dist(t_game info, t_pos place);
void	ft_modif_pcs(t_game *info);
void	ft_modif_map(t_game *info);
void	ft_refresh_pcs(t_game *info);
void	ft_check_pos_top(t_game *info);
void	ft_check_pos_bot(t_game *info);
void		ft_check_pos(t_game *info);
void	ft_refresh_map(t_game *info, char *line, int turn);
int		ft_refresh_game(t_game *info, int turn);

void		ft_get_player(t_game *info);
void		ft_pass_lines(int nb);
void		ft_good_square(char player, char *p1, char *p2);

int		ft_distance_pos(t_pos a, t_pos b);
int		ft_place_pcs(t_game info, int map_y, int map_x);
t_pos	ft_save_top_pos(t_game info, t_pos place);
t_pos	ft_save_bot_pos(t_game info, t_pos place);
int		ft_play(t_game info);

#endif