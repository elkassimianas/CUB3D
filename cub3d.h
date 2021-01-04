/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:35:31 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/05 11:54:45 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

# define WIN_WMAX 5120
# define WIN_HMAX 2880
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define TILE_SIZE 64
# define NUM_ROWS 11
# define NUM_COLS 15
# define WALL_STRIP_WIDTH 1
# define MINIMAP_SCALE_FACTOR 0.2
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define BUFFER_SIZE 32

unsigned long int	g_tilecolor;

typedef	struct	s_player
{
	double		xplayer;
	double		yplayer;
	double		tilex;
	double		tiley;
}				t_player;

typedef struct	s_data
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			size_player;
	int			radius;
	int			turndirection;
	int			walkdirection;
	double		rotationangle;
	double		movespeed;
	double		rotationspeed;
	double		fov_angle;
}				t_data;

typedef	struct	s_ray
{
	double		angle;
	double		g_rayon;
	double		xintercept;
	double		yintercept;
	double		xstep;
	double		ystep;
	double		horzwalhitx;
	double		horzwalhity;
	double		vertwalhitx;
	double		vertwalhity;
	double		distance;
	int			num_rays;
	bool		israyfacingdown;
	bool		israyfacingup;
	bool		israyfacingright;
	bool		israyfacingleft;
	bool		foundhorzwallhit;
	bool		foundvertwallhit;
	bool		washitvert;
	double		horzhitdistance;
	double		verthitdistance;
	int			win_w;
	int			win_h;
}				t_ray;

typedef struct	s_ray1
{
	double		walhitx;
	double		walhity;
	double		distancestab;
	double		angletab;
	double		fndvertwtx;
	bool		rayfup;
	bool		rayfright;
}				t_ray1;

typedef struct	s_render3d
{
	int			walltoppixel;
	int			wa_btm_pxl;
	double		cowalldistance;
	double		wallstripheight;
	double		distanceprojectionplane;
}				t_render3d;

//typedef	struct	s_rendr

typedef struct	s_texture
{
	char		*filenameup;
	char		*filenamedown;
	char		*filenameright;
	char		*filenameleft;
	int			width;
	int			height;
	int			*addr[4];
	int			offsetx;
	int			offsety;
	int			bits_per_pixeltx;
	int			line_lengthtx;
	int			endiantx;
}				t_texture;

typedef	struct	s_check
{
	int			fd;
	char		*line;
}				t_check;

t_ray			g_ray;
t_ray1			g_ray1[WIN_WMAX / WALL_STRIP_WIDTH];
t_player		g_player;
t_render3d		g_render3d;
t_texture		g_texture;
t_check			g_check;

int				keypressed(int keycode, t_data *data);
int				keyrelease(int keycode, t_data *data);
int				hasaallat(double x, double y);
void			rayspush(t_data	*data, double x2, double y2);
void			map(t_data	*data);
void			drawing_cub_walls(t_data	*data);
int				update(t_data	*data);
void			draw_new_map(t_data *data);
void			line(t_data *data);
void			castallg_rays(t_data	*data);
double			normalizeangle(double angle);
int				haswallat(double x, double y);
void			raycasthorz();
void			raycastvert();
void			raycasttotal();
double			distancebetweenpoints(double x1, double y1, double x2,
				double y2);
void			render3dprojectedwalls(t_data *data);
double			dmod(double x, double y);
void			raycasthorzhelp(double nexthorztouchx, double nexthorztouchy);
void			raycastverthelp(double nextverttouchx, double nextverttouchy);
void			drawing_walls3d(t_data *data, double x,
				double y, double tile_z1);
void			render3dprojectedwalls(t_data *data);
void			buffertexture(t_data *data);
void			ft_readfile();
int				put_check();
void			ft_print_errors(char *str);
void			resolution();
size_t			nu_information(char **line);

#endif