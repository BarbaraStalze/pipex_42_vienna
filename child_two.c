/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:46:11 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/10 12:20:28 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	ft_check_access_secondborn(t_data *pipex)
{
	int	check;

	check = access(pipex->outfile, F_OK);
	if (check == 0)
	{
		check = access(pipex->outfile, W_OK);
		if (check == -1)
			ft_error("Outfile does not have permission to write", pipex, 0);
	}
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
	pipex->cmd_path2 = ft_is_command_executable(pipex, command_array,
			command_array[0]);
	check = dup2(pipex->pipe_fd[0], 0);
	if (check == -1)
		ft_error("dup2 failed in secondborn", pipex, 1);
	check = dup2(pipex->file_fd, 1);
	if (check == -1)
		ft_error("dup2 failed in secondborn", pipex, 1);
	ft_close_unused_fds(pipex);
	execve(pipex->cmd_path2, command_array, env);
	free(pipex->cmd_path2);
	ft_free_array(command_array);
	ft_error("execve failed in secondborn", pipex, 1);
}
