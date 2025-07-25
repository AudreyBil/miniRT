/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_single.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:43:33 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/07/21 01:16:45 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

/*
 * Single-threaded rendering function for systems without pthread support
 */
void	render_scene(t_scene *scene)
{
	t_render_params	params;
	t_thread_data	data;

	if (!scene)
	{
		printf("ERROR - Scene pointer is NULL\n");
		return ;
	}
	data.scene = scene;
	data.start_row = 0;
	data.end_row = scene->height;
	setup_render_params(&params, &data);
	render_rows(&params, &data);
	draw_ui(scene);
}
