/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:21:56 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/10 11:38:11 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_free_array(char **a)
{
	int	j;

	j = 0;
	while (a[j])
	{
		free(a[j]);
		j++;
	}
	free(a);
}

void	ft_initialize_struct(t_data *pipex)
{
	pipex->infile = NULL;
	pipex->file_fd = -1;
	pipex->file_fd_open = 0;
	pipex->cmd1 = NULL;
	pipex->cmd_path1 = NULL;
	pipex->cmd2 = NULL;
	pipex->cmd_path2 = NULL;
	pipex->outfile = NULL;
	pipex->pipe_fd[0] = 0;
	pipex->pipe_fd[1] = 0;
	pipex->pipe_fd0_open = 0;
	pipex->pipe_fd1_open = 0;
	pipex->pid[0] = 0;
	pipex->pid[1] = 0;
	pipex->paths = NULL;
	pipex->error = 0;
	pipex->stat = -1;
	pipex->exit_stat = 0;
	pipex->found_file = 0;
}
