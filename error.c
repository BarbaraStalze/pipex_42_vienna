/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:28:47 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/25 18:00:03 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_error(char *message, t_data *pipex)
{
	char	*error_message;

	pipex->error = 1;
	error_message = ft_strjoin("Error\n", message);
	if (!error_message)
	{
		perror ("Error\nMalloc failed");
		ft_end_program(pipex);
	}
	else
	{
		perror (error_message);
		free (error_message);
	}
	ft_end_program(pipex);
}

void	ft_end_program(t_data *pipex)
{
	if (pipex->paths)
		ft_free_array(pipex->paths);
	if (pipex->pipeid)
	{
		close(pipex->pipeid[0]);
		close(pipex->pipeid[1]);
		pipex->pipeid = NULL;
	}
	if (pipex->infile_id > -1)
		close(pipex->infile_id);
	if (pipex->outfile_id > -1)
		close(pipex->outfile_id);
	if (pipex->error == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
