/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:48:39 by bastalze          #+#    #+#             */
/*   Updated: 2026/03/31 17:27:55 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	ft_copy_strings(char **copy_paths, t_data *pipex)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (pipex->paths[i])
	{
		len = ft_strlen(pipex->paths[i]);
		if (pipex->paths[i][len - 1] != '/')
			len++;
		copy_paths[i] = malloc((len + 1) * sizeof(char));
		if (!copy_paths[i])
			ft_error("Malloc in pathfinder failed", pipex);
		j = 0;
		while (pipex->paths[i][j])
		{
			copy_paths[i][j] = pipex->paths[i][j];
			j++;
		}
		copy_paths[i][j] = 0;
		if (pipex->paths[i][len - 2] != '/')
		{
			copy_paths[i][j] = '/';
			copy_paths[i][j + 1] = 0;
		}
		i++;
	}
}

static void	ft_extend_paths(t_data *pipex, char *pathline, int collon_attached)
{
	char	**copy_paths;
	int		i;

	i = 0;
	while (pipex->paths[i])
		i++;
	if (ft_strnstr(pathline, "::", 100) != 0 || ft_strnstr(pathline, "/./", 100) != 0
		|| collon_attached == 1)
		i++;
	copy_paths = malloc((i + 1) * sizeof(char *));
	if (!copy_paths)
		ft_error("Malloc in pathfinder failed", pipex);
	ft_copy_strings(copy_paths, pipex);
	copy_paths[i] = NULL;
	if (ft_strnstr(pathline, "::", 100) != 0 || ft_strnstr(pathline, "/./", 100) != 0
		|| collon_attached == 1)
	{
		copy_paths[i] = malloc(2 * sizeof(char));
		copy_paths[i][0] = '/';
		copy_paths[i][1] = 0;
		copy_paths[i + 1] = NULL;
	}
	ft_free_array(pipex->paths);
	pipex->paths = copy_paths;
}

static void	ft_checking_paths(char *pathline, t_data *pipex)
{
	int	collon_attached;
	int	len;

	collon_attached = 0;
	len = ft_strlen(pathline);
	if (pathline[0] == ':' || pathline[len - 1] == ':')
		collon_attached = 1;
	ft_extend_paths(pipex, pathline, collon_attached);
}

void	ft_pathfinder(char **env, t_data *pipex)
{
	int path_exists;
	int	i;

	path_exists = 0;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_exists = 1;
			pipex->paths = ft_split(env[i] + 5, ':');
			ft_checking_paths(env[i], pipex);
		}
		i++;
	}
	if (path_exists == 0)
	{
		errno = EINVAL;
		ft_error("No path found in env", pipex);
	}
}
