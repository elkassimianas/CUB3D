#include "../cub3d.h"

int		ft_check_elements1(int	a, int	b)
{		
	int		i;

	while (a != 0)
	{
		i = 0;
		ft_free(&g_p.ln);
		a = get_next_line(g_p.fd, &g_p.ln);
		while (g_p.ln[i] == ' ')
           	i++;
		while (g_p.ln[0] == '\0' && a != 0)
		{
			ft_free(&g_p.ln);
			a = get_next_line(g_p.fd, &g_p.ln);
		}
		if ((g_p.ln[i] == '1' || g_p.ln[i] == ' ') && b >= 8)
			break ;
		i = put_check(i, b);
		if (i == 0 && b == 8)
		 	return (-1);
		else if (i != 0)
			b = i;
		else if (i == 0)
			ft_print_errors(2);
	}
	return (1);
}

int		ft_increment_line(int a)
{	
	while (g_p.ln[0] == '\0')
	{
        if (a == 0)
			ft_print_errors(24);
		ft_free(&g_p.ln);
		a = get_next_line(g_p.fd, &g_p.ln);
	}
	return (a);
}

void		ft_check_elements(void)
{
	int		i;
	int		a;
	int		b;
	
	i = 0;
	b = 0;
	if (g_p.fd != -1 && i != -1)
	{
		a = get_next_line(g_p.fd, &g_p.ln);
		if (a == 0 && g_p.ln[0] == '\0')
			ft_print_errors(24);
		a = ft_increment_line(a);
		i = 0;
		while (g_p.ln[i] == ' ')
            i++;
		b = put_check(i, b);
		i = ft_check_elements1(a, b);
	}
	else
		ft_print_errors(7);
	if (b >= 8 && a == 0)
	{
		if ((g_p.ln[i] == '1' || g_p.ln[i] == ' ') && b >= 8)
			ft_print_errors(29);
		ft_print_errors(31);
	}
}

void	ft_readfile(int argc, char *av[])
{
	int		a;
	int		i;

	a = 1;
	argc > 3 || argc == 1 ? ft_print_errors(5) : argc;
	if (argc == 3 && strncmp(av[2], "--save", 7))
		ft_print_errors(5);
	if (ft_strrchr(av[1], '.') && !ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 5))
		g_p.fd = open(av[1], O_RDONLY);
	else
	 	ft_print_errors(6);
	if (!(g_str = (char *)malloc(9 * sizeof(char))))
    	exit(EXIT_FAILURE);
	i = -1;
 	while (++i < 8)
    	g_str[i] = '0';
  	g_str[i] = '\0';
	ft_check_elements();
	ft_free(&g_str);
	check_map();
}