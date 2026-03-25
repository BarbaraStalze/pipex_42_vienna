/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:35:19 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/25 19:06:00 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

typedef struct	s_data
{
	char	*infile;
	int		infile_fd
	char	*cmd1;
	char	*ex_cmd1;
	char	*cmd2;
	char	*ex_cmd2;
	char	*outfile;
	int		outfile_id;
	int		pipefd[2];
	char	**paths;
	int		error;
}	t_data;

void    ft_free_array(char **a);
void	ft_pathfinder(char **env, t_data *pipex);
void	ft_error(char *message, t_data *pipex);
void	ft_end_program(t_data *pipex);
void	ft_parsing(int argc, char **argv, t_data *pipex);
void	ft_open_files(t_data *pipex);
void	ft_pipenfork(t_data *pipex);
void	ft_firstborn(t_data *pipex);
void	ft_secondborn(t_data *pipex);

#endif
