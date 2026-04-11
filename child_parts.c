/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:43:08 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/11 15:31:10 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_close_unused_fds(t_data *pipex)
{
	close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd0_open = 0;
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
	pipex->pipe_fd1_open = 0;
	close(pipex->infile_fd);
	pipex->infile_fd = -1;
	pipex->infile_fd_open = 0;
	close(pipex->outfile_fd);
	pipex->outfile_fd = -1;
	pipex->outfile_fd_open = 0;
}

static void	ft_command_file_exists(t_data *pipex, char **command_array,
		char *path_name)
{
	if (access(path_name, X_OK) == 0)
	{
		pipex->cmd_path = path_name;
		pipex->cmd_path_mallocated = 1;
		return ;
	}
	else
	{
		free(path_name);
		ft_free_child(pipex, command_array);
		pipex->exit_stat = 126;
		ft_error("Command file has no execute permission", pipex, 0);
	}
}

static void	ft_concactenate(t_data *pipex, char **command_array)
{
	int		i;
	char	*path_name;

	i = 0;
	while (pipex->paths[i])
	{
		path_name = ft_strjoin(pipex->paths[i], command_array[0]);
		if (access(path_name, F_OK) == 0)
		{
			ft_command_file_exists(pipex, command_array, path_name);
			return ;
		}
		free(path_name);
		i++;
	}
	ft_free_child(pipex, command_array);
	pipex->exit_stat = 127;
	ft_error("Command file not found", pipex, 0);
}

static void	ft_direct_path(t_data *pipex, char **command_array)
{
	if (access(command_array[0], F_OK) == 0)
	{
		if (access(command_array[0], X_OK) == 0)
		{
			pipex->cmd_path = command_array[0];
			return ;
		}
		else
		{
			ft_free_child(pipex, command_array);
			pipex->exit_stat = 126;
			ft_error("Command file has no execute permission", pipex, 0);
		}
	}
	else
	{
		ft_free_child(pipex, command_array);
		pipex->exit_stat = 127;
		ft_error("Command file not found", pipex, 0);
	}
}

void	ft_is_command_executable(t_data *pipex, char **command_array)
{
	if (!ft_strchr(command_array[0], '/'))
		ft_concactenate(pipex, command_array);
	else
		ft_direct_path(pipex, command_array);
}
