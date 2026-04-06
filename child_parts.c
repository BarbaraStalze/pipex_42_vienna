/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:43:08 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/06 13:42:55 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_remove_path_from_command(char *command, char **pure_command)
{
	int		len;
	int		i;
	char	**command_path;

	command_path = ft_split(command, '/');
	i = 0;
	while (command_path[i])
		i++;
	free(*pure_command);
	len = ft_strlen(command_path[i - 1]);
	*pure_command = malloc(len * sizeof(char));
	ft_strlcpy(*pure_command, command_path[i - 1], len);
	free(command_path);
}

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
				ft_error("Command file no execute permission", pipex, 0);
			}
		}
		free(executable);
		i++;
	}
	return (NULL);
}

char	*ft_is_command_executable(t_data *pipex, char **command_array,
	char *command, char **pure_command)
{
	char	*executable;

	if (access(command, X_OK) == 0)
	{
		ft_remove_path_from_command(command, pure_command);
		return (command);
	}
	else
	{
		executable = ft_is_command_executable_2(pipex, command_array, command);
		if (executable)
			return (executable);
	}
	ft_free_array(command_array);
	pipex->exit_stat = 127;
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
