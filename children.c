/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:25:23 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/31 18:28:53 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	ft_remove_path_from_command(char *command, char **pure_command)
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

static char	*ft_is_command_executable(t_data *pipex, char *command, char **pure_command)
{
	int		i;
	char	*executable;

	if (access(command, X_OK) == 0)
	{
		ft_remove_path_from_command(command, pure_command);
		return (command);
	}
	i = 0;
	else
	{
		while (pipex->paths[i])
		{
			executable = ft_strjoin(pipex->paths[i], command);
			if (access(executable, X_OK) == 0)
				return (executable);
			free(executable);
			i++;
		}
	}
	ft_error("Command file not found or not executable", pipex);
	return (0);
}

void	ft_firstborn(t_data *pipex, char **env)
{
	int		check;
	char	**command_array;

	check = access(pipex->infile, F_OK);
	if (check == -1)
		ft_error("Infile does not exist", pipex);
	check = access(pipex->infile, R_OK);
	if (check == -1)
		ft_error("Infile does not have permission to read", pipex);
	pipex->infile_fd = open(pipex->infile, O_RDONLY);
	if (pipex->infile_fd == -1)
		ft_error("Open infile (first argument) failed", pipex);
	pipex->infile_fd_open = 1;
	command_array = ft_split(pipex->cmd1, ' ');
	if (!command_array)
		ft_error("Split in firstborn has failed", pipex);
	pipex->cmd_path1 = ft_is_command_executable(pipex, command_array[0], &command_array[0]);
	check = dup2(pipex->infile_fd, 0);
	if (check == -1)
		ft_error("dup2 failed in firstborn", pipex);
	close(pipex->infile_fd);
	pipex->infile_fd = -1;
	check = dup2(pipex->pipe_fd[1], 1);
	if (check == -1)
		ft_error("dup2 failed in firstborn", pipex);
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
	close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
	execve(pipex->cmd_path1, command_array, env);
	free(command_array);
	ft_error("execve failed in firstborn", pipex);
}

void	ft_secondborn(t_data *pipex, char **env)
{
	int		check;
	char	**command_array;

	check = access(pipex->outfile, F_OK);
	if (check == 0)
	{
		check = access(pipex->infile, W_OK);
		if (check == -1)
			ft_error("Outfile does not have permission to write", pipex);
	}
	pipex->outfile_fd = open(pipex->outfile, O_CREAT | O_WRONLY, 0755);
	if (pipex->outfile_fd == -1)
		ft_error("Open outfile (last argument) failed", pipex);
	pipex->outfile_fd_open = 1;
	command_array = ft_split(pipex->cmd2, ' ');
	if (!command_array)
		ft_error("Split in secondborn has failed", pipex);
	pipex->cmd_path2 = ft_is_command_executable(pipex, command_array[0], &command_array[0]);
	check = dup2(pipex->pipe_fd[0], 0);
	if (check == -1)
		ft_error("dup2 failed in secondborn", pipex);
	close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
	check = dup2(pipex->outfile_fd, 1);
	if (check == -1)
		ft_error("dup2 failed in secondborn", pipex);
	close(pipex->outfile_fd);
	pipex->outfile_fd = -1;
	execve(pipex->cmd_path2, command_array, env);
	free(command_array);
	ft_error("execve failed in secondborn", pipex);
}
