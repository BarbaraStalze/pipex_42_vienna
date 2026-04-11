/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:25:23 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/11 15:21:06 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_firstborn(t_data *pipex, char **env)
{
	int		check;
	char	**command_array;

	command_array = ft_split(pipex->cmd1, ' ');
	if (!command_array)
		ft_error("Split in firstborn has failed", pipex, 1);
	ft_is_command_executable(pipex, command_array);
	check = dup2(pipex->infile_fd, 0);
	if (check == -1)
	{
		ft_free_child(pipex, command_array);
		ft_error("dup2 failed in firstborn", pipex, 1);
	}
	check = dup2(pipex->pipe_fd[1], 1);
	if (check == -1)
	{
		ft_free_child(pipex, command_array);
		ft_error("dup2 failed in firstborn", pipex, 1);
	}
	ft_close_unused_fds(pipex);
	execve(pipex->cmd_path, command_array, env);
	ft_free_child(pipex, command_array);
	ft_error("execve failed in firstborn", pipex, 1);
}
