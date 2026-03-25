/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:02:07 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/25 18:01:24 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	t_data	pipex;

	ft_parsing(argc, argv, &pipex);
	ft_pathfinder(env, &pipex);
	ft_open_files(&pipex);
	ft_pipenfork(pipex);
	
// TEST TEST TEST
	int i = 0;

	while (pipex.paths[i])
	{
		printf("%s\n", pipex.paths[i]);
		i++;
	}
	ft_end_program(&pipex);
}
