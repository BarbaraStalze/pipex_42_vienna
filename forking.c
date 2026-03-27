/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:58:38 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/27 19:35:00 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.c"

void	ft_parent(t_data *pipex)
{
	pid_t	pid_check1;
	pid_t	pid_check2;
	int		stat1;
	int		stat2;

	close(pipex->pipe_fd[0]);
	pipex->pipe_fd[0] = -1;
	close(pipex->pipe_fd[1]);
	pipex->pipe_fd[1] = -1;
	pid_check1 = waitpid(pipex->pid[0], &stat1, 0);
	pid_check2 = waitpid(pipex->pid[1], &stat2, 0);
	if (WIFEXITED(stat1) && WIFEXITED(stat2))
		ft_end_program(pipex);
	else
		perror("One of the children couldn't finish their job", pipex);
}

void	ft_pipenfork(t_data *pipex, char **env)
{
	int	pipe_status;

	pipe_status = pipe(pipex->pipe_fd);
	if (pipe_status == -1)
		ft_error("Pipe failed", pipex);
	pipex->pid[0] = fork();
	if (pipex->pid[0] == 0)
		ft_firstborn(pipex, env);
	pipex->pid[1] = fork();
	if (pipex->pid[1] == 0)
		ft_secondborn(pipex, env);
	if (pipex->pid[0] == -1 || pipex->pid[1] == -1)
		ft_error("Fork failed", pipex);
}
