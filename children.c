/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:25:23 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/25 19:06:21 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	ft_is_command(t_data *pipex, char *command, char **save_to)
{
	int		i;
	char	*executable;

	while (pipex->path[i])
	{
		executable = ft_strjoin(pipex->path[i], command);
		if (access(executable, X_OK) == 0)
			*save_to = executable;
		free(executable);
		i++;
	}
// Has to be confirmed, if yes, added to ft_close_program:
	if (!*save_to)
		ft_error("Command not found", pipex);
}

void	ft_firstborn(t_data *pipex)
{
	ft_is_command(pipex, pipex->cmd1, &pipex->ex_cmd1);
}

void	ft_secondborn(t_data *pipex)
{
	ft_is_command(pipex, pipex->cmd2, &pipex->ex_cmd2);
}
