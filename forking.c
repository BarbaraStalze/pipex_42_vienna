/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:58:38 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/31 15:19:15 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_parent(t_data *pipex)
{
	pid_t	pid_check1;
	pid_t	pid_check2;

	close(pipex->pipe_fd[0]);
	pipex->pipe_fd0_open = 0;
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd1_open = 1;
	pid_check1 = waitpid(pipex->pid[0], &pipex->stat1, 0);
	pid_check2 = waitpid(pipex->pid[1], &pipex->stat2, 0);
	if (WIFEXITED(pipex->stat1) && WIFEXITED(pipex->stat2))
		ft_end_program(pipex);
	else
		ft_error("One of the children couldn't finish their job", pipex);
}

void	ft_pipenfork(t_data *pipex, char **env)
{
	int	pipe_status;

	pipe_status = pipe(pipex->pipe_fd);
	if (pipe_status == -1)
		ft_error("Pipe failed", pipex);
	pipex->pipe_fd0_open = 1;
	pipex->pipe_fd1_open = 1;
	pipex->pid[0] = fork();
	if (pipex->pid[0] == 0)
		ft_firstborn(pipex, env);
	pipex->pid[1] = fork();
	if (pipex->pid[1] == 0)
		ft_secondborn(pipex, env);
	if (pipex->pid[0] == -1 || pipex->pid[1] == -1)
		ft_error("Fork failed", pipex);
}
