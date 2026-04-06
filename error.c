/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:28:47 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/06 13:06:45 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_error_message(char *message, t_data *pipex, int error_type)
{
	int		len;
	char	*error_message;

	printf("ERoor message bro\n");
	error_message = ft_strjoin("Error\n", message);
	if (!error_message)
	{
		perror ("Error\nMalloc failed");
		ft_end_program(pipex);
	}
	if (error_type == 0)
	{
		len = ft_strlen(error_message);
		write(2, error_message, len);
	}
	else
		perror(error_message);
	free(error_message);
}

void	ft_end_program(t_data *pipex)
{
	if (pipex->paths)
		ft_free_array(pipex->paths);
	if (pipex->pipe_fd0_open)
		close(pipex->pipe_fd[0]);
	if (pipex->pipe_fd1_open)
		close(pipex->pipe_fd[1]);
	if (pipex->file_fd_open)
		close(pipex->file_fd);
	if (pipex->exit_stat)
		exit(pipex->exit_stat);
	if (WIFEXITED(pipex->stat))
	{
		printf("Hello with exit\n");
		printf("%d\n", WEXITSTATUS(pipex->stat));
		exit(WEXITSTATUS(pipex->stat));
	}
	if (pipex->error == 1)
		exit(1);
	exit(0);
}

void	ft_error(char *message, t_data *pipex, int error_type)
{
	pipex->error = 1;
	printf("In Error bro\n");
	ft_error_message(message, pipex, error_type);
	ft_end_program(pipex);
}
