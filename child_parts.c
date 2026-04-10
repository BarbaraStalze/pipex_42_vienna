/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:43:08 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/10 12:21:08 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
/*
void	ft_remove_path_from_command(char *command, char **pure_command)
{
	int		len;
	int		i;
	char	**command_path;

	printf("%s\n", command);
	command_path = ft_split(command, '/');
	printf("%s\n", command);
	i = 0;
	while (command_path[i])
	{
		printf("%s\n", command_path[i]);
		i++;
	}
	len = ft_strlen(command_path[i - 1]);
	*pure_command = ft_strdup(command_path[i - 1]);
	free(command_path);
}*/

static char	*ft_is_command_executable_2(t_data *pipex, char **command_array,
	char *command)
{
	int		i;
	char	*executable;

	i = 0;
	while (pipex->paths[i])
	{
		executable = ft_strjoin(pipex->paths[i], command);
		if (access(executable, F_OK) == 0)
		{
			if (access(executable, X_OK) == 0)
				return (executable);
			else
			{
				ft_free_array(command_array);
				pipex->exit_stat = 126;
				free(executable);
				ft_error("Command file has no execute permission", pipex, 0);
			}
		}
		free(executable);
		i++;
	}
	return (NULL);
}

char	*ft_is_command_executable(t_data *pipex, char **command_array,
	char *command)
{
	char	*executable;

	if (access(command, F_OK) == 0 && ft_strchr(command, '/'))
	{
		pipex->found_file = 1; 
		if (access(command, X_OK) == 0)
			return (command);
	}
	else
	{
		executable = ft_is_command_executable_2(pipex, command_array, command);
		if (executable)
			return (executable);
	}
	ft_free_array(command_array);
	if (pipex->found_file)
	{
		pipex->exit_stat = 127;
		ft_error("Command file has no execute permission", pipex, 0);
	}
	pipex->exit_stat = 126;
	ft_error("Command file not found", pipex, 0);
	return (0);
}

void	ft_open_file(t_data *pipex)
{
	if (pipex->child_nbr == 1)
		pipex->file_fd = open(pipex->infile, O_RDONLY);
	else
		pipex->file_fd = open(pipex->outfile, O_CREAT | O_WRONLY
				| O_TRUNC, 0644);
	if (pipex->file_fd == -1 && pipex->child_nbr == 1)
		ft_error("Open infile (first argument) failed", pipex, 1);
	else if (pipex->file_fd == -1 && pipex->child_nbr == 2)
		ft_error("Open outfile (last argument) failed", pipex, 1);
	pipex->file_fd_open = 1;
}

void	ft_close_unused_fds(t_data *pipex)
{
	close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd0_open = 0;
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
	pipex->pipe_fd1_open = 0;
	close(pipex->file_fd);
	pipex->file_fd = -1;
	pipex->file_fd_open = 0;
}
