/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:25:23 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/26 15:59:28 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static char	*ft_is_command_executable(t_data *pipex, char *command)
{
	int		i;
	char	*executable;

	while (pipex->path[i])
	{
		executable = ft_strjoin(pipex->path[i], command);
		if (access(executable, X_OK) == 0)
			command_path = executable;
		free(executable);
		i++;
	}
	if (!command_path)
		ft_error("Command not found", pipex);
	return (command_path);
}

void	ft_firstborn(t_data *pipex, char **env)
{
	int		check;
	char	**command_array;

	pipex->infile_fd = open(pipex->infile, O_RDONLY);
	if (pipex->infile_fd == -1)
		ft_error("Open infile (first argument) failed", pipex);
	pipex->ex_cmd1 = ft_is_command_executable(pipex, pipex->cmd1);
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
	command_array = split(pipex->cmd1, ' ');
	execve(pipex->ex_cmd1, command_array, env);
	ft_error("execve failed in firstborn", pipex);
}

void	ft_secondborn(t_data *pipex, char **env)
{
	int		check;
	char	**command_array;

	pipex->outfile_fd = open(pipex->outfile, O_CREAT | O_WRONLY, 0755);
	if (pipex->outfile_fd == -1)
		ft_error("Open outfile (last argument) failed", pipex);
	pipex->ex_cmd2 = ft_is_command_executable(pipex, pipex->cmd2);
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
	command_array = split(pipex->cmd2, ' ');
	execve(pipex->ex_cmd2, command_array, env);
	ft_error("execve failed in secondborn", pipex);
}
