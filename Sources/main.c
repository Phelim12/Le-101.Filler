/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 15:39:26 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 15:39:26 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	ft_go_center_point(t_game *info)
{
	info->way.y = (info->height_map / 2);
	info->way.x = (info->width_map / 2);
	
}

void	ft_go_alpha_point(t_game *info)
{
	if (info->start_enemy == 0)
	{
		info->way.y = 0; 
		info->way.x = (info->width_map - 1);
	}
	if (info->start_enemy == 1)
	{
		info->way.y = 0; 
		info->way.x = 0;
	}
	if (info->start_enemy == 2)
	{
		info->way.y = 0;  
		info->way.x = 0;
	}
	if (info->start_enemy == 3)
	{
		info->way.y = 0; 
		info->way.x = (info->width_map - 1);
	}
}

void	ft_go_beta_point(t_game *info)
{
	if (info->start_enemy == 0)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = 0;
	}
	if (info->start_enemy == 1)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = (info->width_map - 1);
	}
	if (info->start_enemy == 2)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = (info->width_map - 1);
	}
	if (info->start_enemy == 3)
	{
		info->way.y = (info->height_map - 1);
		info->way.x = 0;
	}
}

int		main(int argc, char const *argv[])
{
	int		modif_rush;
	t_game	info;
	int		turn;
	int		rush;

	turn = 0;
	modif_rush = 0;
	ft_get_player(&info);
	info.before = ft_fill_pos(0, 0.);
	while (1)
	{
		ft_refresh_game(&info, turn);
		if ((turn % 2) == 0)
			ft_go_beta_point(&info);
		if ((turn % 2) == 1)
			ft_go_alpha_point(&info);
		rush = (info.width_map / 5);
		if (ft_play(&info, (rush - modif_rush++)) == 0)
		{
			ft_printf("0 0\n");
			break ;
		}
		turn++;
	}
	return (0);
}
