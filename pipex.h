/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:35:19 by bastalze          #+#    #+#             */
/*   Updated: 2026/04/06 13:08:30 by bastalze         ###   ########.fr       */
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
# include <sys/wait.h>

typedef struct s_data
{
	char	*infile;
	int		file_fd;
	int		file_fd_open;	
	char	*cmd1;
	char	*cmd_path1;
	char	*cmd2;
	char	*cmd_path2;
	char	*outfile;
	int		pipe_fd[2];
	int		pipe_fd0_open;
	int		pipe_fd1_open;
	pid_t	pid[2];
	char	**paths;
	int		error;
	int		child_nbr;
	int		stat;
	int		exit_stat;
}	t_data;

void	ft_free_array(char **a);
void	ft_pathfinder(char **env, t_data *pipex);
void	ft_error(char *message, t_data *pipex, int error_type);
void	ft_end_program(t_data *pipex);
void	ft_pipenfork(t_data *pipex, char **env);
void	ft_firstborn(t_data *pipex, char **env);
void	ft_secondborn(t_data *pipex, char **env);
void	ft_parent(t_data *pipex);
void	ft_initialize_struct(t_data *pipex);
void	ft_open_file(t_data *pipex);
char	*ft_is_command_executable(t_data *pipex, char **command_array,
			char *command, char **pure_command);
void	ft_remove_path_from_command(char *command, char **pure_command);

#endif
