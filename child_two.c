/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:46:11 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/11 18:22:25 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	ft_open_outfile(t_data *pipex, char **command_array)
{
	if (!access(pipex->outfile, F_OK) && access(pipex->outfile, W_OK) == -1)
	{
		ft_free_child(pipex, command_array);
		ft_error("Outfile does not have permission to write", pipex, 0);
	}
	pipex->outfile_fd = open(pipex->outfile, O_CREAT | O_WRONLY
			| O_TRUNC, 0644);
	if (pipex->outfile_fd == -1)
	{
		ft_free_child(pipex, command_array);
		ft_error("Open outfile failed", pipex, 1);
	}
	pipex->outfile_fd_open = 1;
}

void	ft_secondborn(t_data *pipex, char **env)
{
	int		check;
	char	**command_array;

	command_array = ft_split(pipex->cmd2, ' ');
	if (!command_array)
		ft_error("Split in secondborn has failed", pipex, 1);
	ft_open_outfile(pipex, command_array);
	ft_is_command_executable(pipex, command_array);
	check = dup2(pipex->pipe_fd[0], 0);
	if (check == -1)
	{
		ft_free_child(pipex, command_array);
		ft_error("dup2 failed in secondborn", pipex, 1);
	}
	check = dup2(pipex->outfile_fd, 1);
	if (check == -1)
	{
		ft_free_child(pipex, command_array);
		ft_error("dup2 failed in secondborn", pipex, 1);
	}
	ft_close_unused_fds(pipex);
	execve(pipex->cmd_path, command_array, env);
	ft_free_child(pipex, command_array);
	pipex->exit_stat = 0;
	ft_end_program(pipex);
}
