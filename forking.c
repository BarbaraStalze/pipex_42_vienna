/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:58:38 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/25 18:01:34 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.c"

void	ft_pipenfork(t_data *pipex)
{
	int	pipe_status;
	int	pid_child_1;
	int	pid_child_2;

	pipe_status = pipe(pipex->pipefd);
	if (pipe_status == -1)
		ft_error("Pipe failed", pipex);
	pid_child_1 = fork();
	if (pid_child_1 == 0)
		ft_firstborn(pipex);
	pid_child_2 = fork();
	if (pid_child_2 == 0)
		ft_secondborn(pipex);
	if (pid_child_1 == -1 || pid_child_2 == -1)
		ft_error("Stillbirth", pipex);
}

void	ft_open_files(t_data *pipex)
{
	pipex->infile_id = open(pipex->infile, O_EXEC);
	if (pipex->infile_id == -1)
		ft_error("Open infile (first argument) failed", pipex);
	pipex->outfile_id = open(pipex->outfile, O_CREAT | O_WRONLY, 0755);
	if (pipex->outfile_id == -1)
		ft_error("Open outfile (last argument) failed", pipex);
}
