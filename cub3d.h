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
# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "./get_next_line/get_next_line.h"
//# include "./libft/libft.h"

# define WIN_WMAX 2560
# define WIN_HMAX 1440
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define TL_SZ 64
# define NUM_ROWS 11
# define NUM_COLS 15
# define WALL_STRIP_WIDTH 1
# define MINIMAP_SCALE_FACTOR 0.2

unsigned long int	g_tilecolor;
char				*g_str;
void				*dataimg[4];

typedef	struct	s_player
{
	double		x_p;
	double		y_p;
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
	int			walkdirection_side;
	double		ro_angle;
	double		movespeed;
	double		rotationspeed;
	double		fov_angle;
	char			**map;
	int			win_w;
	int			win_h;
	int			img_w;
	int			img_h;
}				t_data;

typedef	struct	s_ray
{
	double		angle;
	double		xintercept;
	double		yintercept;
	double		xstep;
	double		ystep;
	double		hz_hit_x;
	double		hz_hit_y;
	double		vr_hi_x;
	double		vrt_hit_y;
	int			num_rays;
	bool		israyfacingdown;
	bool		israyfacingup;
	bool		israyfacingright;
	bool		israyfacingleft;
	bool		fnd_hz_hit;
	bool		fnd_vrt_hit;
	bool		washitvert;
	double		hz_hit_dis;
	double		vrt_hit_dis;
}				t_ray;

typedef struct	s_ray1
{
	double		w_hitx;
	double		w_hity;
	double		dis_t;
	double		anglet;
	double		fndvertwtx;
	bool		rayfup;
	bool		rayfright;
}				t_ray1;

typedef struct	s_render3d
{
	int			wall_top;
	int			wa_bmt;
	double		cowal_dis;
	double		w_strip_h;
	double		dis_proj_plan;
}				t_render3d;

//typedef	struct	s_rendr

typedef struct	s_texture
{
	char		*filenameup;
	char		*filenamedown;
	char		*filenameright;
	char		*filenameleft;
	char		*filesprite;
	int			width;
	int			height;
	int			rf;
	int			gf;
	int			bf;
	int			rc;
	int			gc;
	int			bc;
	int			*addr[4];
	int			offsetx;
	int			offsety;
	int			bits_per_pixeltx;
	int			line_lengthtx;
	int			endiantx;

}				t_texture;

typedef	struct	s_parsing
{
	int			fd;
	char		*ln;
	char		*str;
	size_t		len;
	int			inc;
}				t_parsing;

t_ray			g_r;
t_ray1			g_r1[WIN_WMAX / WALL_STRIP_WIDTH];
t_player		g_pl;
t_render3d		g_rd;
t_texture		g_tex;
t_parsing		g_p;
t_data			g_dt;

int				keypressed(int keycode);
int				keyrelease(int keycode);
int				hasaallat(double x, double y);
void			rayspush(double x2, double y2);
void			map(void);
void			drawing_cub_walls(double tilex, double tiley);
int				update(void);
void			draw_new_map(void);
void			line(void);
void			castallg_rs(void);
double			normalizeangle(double angle);
int				haswallat(double x, double y);
void			raycasthorz(void);
void			raycastvert(void);
void			raycasttotal(void);
double			dis_bet_points(double x1, double y1, double x2,double y2);
void			render3dprojectedwalls(void);
double			dmod(double x, double y);
void			raycasthorzhelp(double nexthorztouchx, double nexthorztouchy);
void			raycastverthelp(double nextverttouchx, double nextverttouchy);
void			drawing_walls3d(double x, double y, double tile_z1);
void			render3dprojectedwalls(void);
void			buffertexture(void);
void			ft_readfile(int argc, char *av[]);
int				put_check(int i, int b);
void			ft_print_errors1(char *str, int index);
void			ft_print_errors(int	index);
void			ft_print_errors2(int index);
void			ft_print_errors3(int index);
int				resolution(int b);
size_t			nu_information(char **line);
void			no_so_we_ea_s(int dx1, int dx2);
void			ft_floor(char **line);
void			ft_ceilling(char **line);
void			check_map(void);
void			ft_allocate(int	x, int y);
void			check_first_end_line(void);
void			ft_putmap(int x, int y);
int    			check_map1(int check);
int				ft_read_map(void);
void			ft_valid_map(int x, int y);
void			ft_check_spaces(int i, int j, int x, int y);
int				put_check_help1(int i, int b);
int				put_check_help2(int i, int b);
int				put_check_help3(int i, int b);
int				find_player(int j, int i);
void			change_spaces(void);
int				quit_win();
int				create_trgb(int r, int g, int b);
int				ft_math_utils(int i, int a);
void			ft_floor_ceilling(int i);

#endif