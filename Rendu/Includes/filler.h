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

# include "../Libft/Includes/libft.h"

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃           This structure is a coordinate (ordinate and abscissa)           ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_pos
{
	int	y;
	int x;
}				t_pos;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃    This structure groups all params (info) on the game(board, pcs, way,    ┃
**┃	             size of pcs and map, and the start pos of enemy)              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_game
{
	t_pos	way;
	t_pos	print;
	char	**pcs;
	char	**map;
	char	player;
	char	square_x;
	char	square_o;
	char	start_enemy;
	int		width_map;
	int		width_pcs;
	int		height_map;
	int		height_pcs;
}				t_game;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               main_filler.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_start_reducto(t_game info);
int				ft_check_width_pcs(t_game info);
int				ft_check_height_pcs(t_game info);
int				ft_close_enemy(t_game info, int s_y, int s_x, int player);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                           algo_controle_filler.c                           ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_reducto(t_game info, t_pos pos);
void			ft_reducto_diag1(t_game info, char **tab, int y, int x);
void			ft_reducto_diag2(t_game info, char **tab, int y, int x);
void			ft_reducto_ordinate(t_game info, char **tab, int y, int x);
void			ft_reducto_abscissa(t_game info, char **tab, int y, int x);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                algo_filler.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_play(t_game *info, int rush);
t_pos			ft_print_end(t_game info, t_pos *all, int cur);
int				ft_can_place_pcs(t_game info, int map_y, int map_x);
void			ft_print_good_solve(t_game *info, t_pos *all, int cur, int s);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             algo_way_filler.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_go_beta_point(t_game *info);
void			ft_go_alpha_point(t_game *info);
int				ft_distance_pos(t_pos a, t_pos b);
int				ft_check_dist(t_game info, t_pos place);
t_pos			ft_print_dist(t_game info, t_pos *all, int cur);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              params_filler.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_get_player(t_game *info);
int				ft_pos_start_enemy(t_game *info);
void			ft_good_square(char player, char *p1, char *p2);
char			**ft_new_map(t_game info, t_pos pos, int y, int x);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            refresh_game_filler.c                           ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_modif_pcs(t_game *info);
void			ft_modif_map(t_game *info);
void			ft_refresh_pcs(t_game *info);
void			ft_refresh_map(t_game *info, int turn);
int				ft_refresh_game(t_game *info, int turn);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               tools_filler.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_pass_lines(int nb);
void			ft_free_tab(char ***tab);
t_pos			ft_fill_pos(int y, int x);
void			ft_free_game(t_game *info);
int				ft_count_pos(t_game info, char **tab, int player);

#endif
