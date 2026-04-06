/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:25:23 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/06 13:31:44 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	ft_check_access_firstborn(t_data *pipex)
{
	int	check;

	check = access(pipex->infile, F_OK);
	if (check == -1)
		ft_error("Infile does not exist", pipex, 0);
	check = access(pipex->infile, R_OK);
	if (check == -1)
		ft_error("Infile does not have permission to read", pipex, 0);
}

static void	ft_close_unused_fds(t_data *pipex)
{
	close(pipex->file_fd);
	pipex->file_fd = -1;
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
	close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
}

void	ft_firstborn(t_data *pipex, char **env)
{
	int		check;
	char	**command_array;

	pipex->child_nbr = 1;
	ft_check_access_firstborn(pipex);
	ft_open_file(pipex);
	command_array = ft_split(pipex->cmd1, ' ');
	if (!command_array)
		ft_error("Split in firstborn has failed", pipex, 1);
	pipex->cmd_path1 = ft_is_command_executable(pipex, command_array,
			command_array[0], &command_array[0]);
	check = dup2(pipex->file_fd, 0);
	if (check == -1)
		ft_error("dup2 failed in firstborn", pipex, 1);
	check = dup2(pipex->pipe_fd[1], 1);
	if (check == -1)
		ft_error("dup2 failed in firstborn", pipex, 1);
	ft_close_unused_fds(pipex);
	execve(pipex->cmd_path1, command_array, env);
	free(pipex->cmd_path1);
	ft_free_array(command_array);
	ft_error("execve failed in firstborn", pipex, 1);
}
