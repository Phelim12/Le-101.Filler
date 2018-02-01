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

void	ft_free_game(t_game *info)
{
	ft_free_tab(&info->map);
	ft_free_tab(&info->pcs);
}

int		main(int argc, char const *argv[])
{
	t_game	info;
	int		turn;
	int		error;

	turn = 0;
	error = ft_get_player(&info);
	while (error)
	{
		ft_refresh_game(&info, turn);
		if ((turn % 3) == 0)
			ft_go_beta_point(&info);
		if ((turn % 3) == 1)
			ft_go_alpha_point(&info);
		if (ft_play(&info, ft_start_reducto(info)) == 0)
			break ;
		ft_free_game(&info);
		turn++;
	}
	if (error == -1)
		ft_printf("Bad player info\n");
	ft_free_game(&info);
	ft_printf("0 0\n");
	return (0);
}
