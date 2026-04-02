/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:02:07 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/31 17:18:02 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void    ft_parsing(int argc, char **argv, t_data *pipex)
{
	if (argc != 5)
		ft_error("The program only takes 4 arguments", pipex, 0);
	pipex->infile = argv[1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	pipex->outfile = argv[4];
}

int	main(int argc, char **argv, char **env)
{
	t_data	pipex;

 	ft_initialize_struct(&pipex);
	ft_parsing(argc, argv, &pipex);
	ft_pathfinder(env, &pipex);
	ft_pipenfork(&pipex, env);
	ft_parent(&pipex);
	ft_end_program(&pipex);
}

/*
// TEST TEST TEST
        int i = 0;

        while (pipex.paths[i])
        {
                printf("%s\n", pipex.paths[i]);
                i++;
        }
*/
