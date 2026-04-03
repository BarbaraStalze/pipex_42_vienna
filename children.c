/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:25:23 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/03 18:35:16 by bastalze         ###   ########.fr       */
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

static char	*ft_is_command_executable(t_data *pipex, char **command_array, char *command, char **pure_command)
{
	int		i;
	char	*executable;

	if (access(command, X_OK) == 0)
	{
		ft_remove_path_from_command(command, pure_command);
		return (command);
	}
	else
	{
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
		pipex->file_fd = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->file_fd == -1 && pipex->child_nbr == 1)
		ft_error("Open infile (first argument) failed", pipex, 1);
	else if (pipex->file_fd == -1 && pipex->child_nbr == 2)
		ft_error("Open outfile (last argument) failed", pipex, 1);
	pipex->file_fd_open = 1;
}

void	ft_check_access_firstborn(t_data *pipex)
{
	int	check;

	check = access(pipex->infile, F_OK);
	if (check == -1)
		ft_error("Infile does not exist", pipex, 0);
	check = access(pipex->infile, R_OK);
	if (check == -1)
		ft_error("Infile does not have permission to read", pipex, 0);
}

void	ft_check_access_secondborn(t_data *pipex)
{
	int	check;

	printf("%s\n", pipex->outfile);
	check = access(pipex->outfile, F_OK);
	printf("%d\n", check);
	if (check == 0)
	{
		check = access(pipex->outfile, W_OK);
		printf("%d\n", check);
		if (check == -1)
		{
			printf("yes check %d\n", check);
			ft_error("Outfile does not have permission to write", pipex, 0);
		}
	}
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
	pipex->cmd_path1 = ft_is_command_executable(pipex, command_array, command_array[0], &command_array[0]);
	check = dup2(pipex->file_fd, 0);
	if (check == -1)
		ft_error("dup2 failed in firstborn", pipex, 1);
	close(pipex->file_fd);
	pipex->file_fd = -1;
	check = dup2(pipex->pipe_fd[1], 1);
	if (check == -1)
		ft_error("dup2 failed in firstborn", pipex, 1);
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
	close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
	execve(pipex->cmd_path1, command_array, env);
	free(pipex->cmd_path1);
	ft_free_array(command_array);
	ft_error("execve failed in firstborn", pipex, 1);
}

void	ft_secondborn(t_data *pipex, char **env)
{
	int		check;
	char	**command_array;

	pipex->child_nbr = 2;
	ft_check_access_secondborn(pipex);
	ft_open_file(pipex);
	command_array = ft_split(pipex->cmd2, ' ');
	if (!command_array)
		ft_error("Split in secondborn has failed", pipex, 1);
	pipex->cmd_path2 = ft_is_command_executable(pipex, command_array, command_array[0], &command_array[0]);
	check = dup2(pipex->pipe_fd[0], 0);
	if (check == -1)
		ft_error("dup2 failed in secondborn", pipex, 1);
	close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
	check = dup2(pipex->file_fd, 1);
	if (check == -1)
		ft_error("dup2 failed in secondborn", pipex, 1);
	close(pipex->file_fd);
	pipex->file_fd = -1;
	execve(pipex->cmd_path2, command_array, env);
	free(pipex->cmd_path2);
	ft_free_array(command_array);
	ft_error("execve failed in secondborn", pipex, 1);
}
