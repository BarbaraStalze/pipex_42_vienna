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

static void	ft_construct_new_string(char **copy_paths, t_data *pipex, int i, int slash)
{
	int	j;
	
	j = 0;
	while (pipex->paths[i][j])
	{
		copy_paths[i][j] = pipex->paths[i][j];
		j++;
	}
	copy_paths[i][j] = 0;
	if (slash)
	{
		copy_paths[i][j] = '/';
		copy_paths[i][j + 1] = 0;
	}
	
}

static void	ft_slash_or_no_slash(char **copy_paths, t_data *pipex)
{
	int	i;
	int	len;
	int	slash;

	i = 0;
	while (pipex->paths[i])
	{
		slash = 0;
		len = ft_strlen(pipex->paths[i]);
		if (pipex->paths[i][len - 1] != '/')
		{
			len++;
			slash = 1;
		}
		copy_paths[i] = malloc((len + 1) * sizeof(char));
		if (!copy_paths[i])
			ft_error("Malloc in pathfinder failed", pipex, 1);
		ft_construct_new_string(copy_paths, pipex, i, slash);
		i++;
	}
}

static void	ft_checking_paths(char *pathline, t_data *pipex)
{
	int		i;
	char	**copy_paths;

	i = 0;
	while (pipex->paths[i])
		i++;
	if (ft_strnstr(pathline, "::", 100) != 0 || ft_strnstr(pathline, "/./", 100) != 0
		|| pathline[0] == ':' || pathline[ft_strlen(pathline) - 1] == ':')
		i++;
	copy_paths = malloc((i + 1) * sizeof(char *));
	if (!copy_paths)
		ft_error("Malloc in pathfinder failed", pipex, 1);
	ft_slash_or_no_slash(copy_paths, pipex);
	copy_paths[i] = NULL;
	if (ft_strnstr(pathline, "::", 100) != 0 || ft_strnstr(pathline, "/./", 100) != 0
		|| pathline[0] == ':' || pathline[ft_strlen(pathline) - 1] == ':')
	{
		copy_paths[i] = malloc(2 * sizeof(char));
		copy_paths[i][0] = '/';
		copy_paths[i][1] = 0;
		copy_paths[i + 1] = NULL;
	}
	ft_free_array(pipex->paths);
	pipex->paths = copy_paths;
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
		ft_error("No path found in env", pipex, 0);
}
