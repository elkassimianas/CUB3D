/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:35:31 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/13 17:23:32 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "./get_next_line/get_next_line.h"
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
# define WALL_STRIP_WIDTH 1

unsigned long int	g_tilecolor;
char				*g_str;
void				*g_dataimg[5];

typedef	struct		s_player
{
	double			x_p;
	double			y_p;
}					t_player;

typedef struct		s_data
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*win;
	int				size_player;
	int				radius;
	int				turndirection;
	int				walkdirection;
	int				walkdirection_side;
	double			ro_angle;
	double			movespeed;
	double			rotationspeed;
	double			fov_angle;
	char			**map;
	int				win_w;
	int				win_h;
	int				img_w;
	int				img_h;
}					t_data;

typedef	struct		s_ray
{
	double			angle;
	double			xintercept;
	double			yintercept;
	double			xstep;
	double			ystep;
	double			hzhitx;
	double			hzhity;
	double			vr_hi_x;
	double			vrhity;
	int				num_rays;
	bool			israyfacingdown;
	bool			israyfacingup;
	bool			israyfacingright;
	bool			israyfacingleft;
	bool			fnd_hz_hit;
	bool			fnd_vrt_hit;
	bool			washitvert;
	double			hzhitdis;
	double			vrhitd;
}					t_ray;

typedef struct		s_ray1
{
	double			w_hitx;
	double			w_hity;
	double			dis_t;
	double			anglet;
	double			fndvertwtx;
	bool			rayfup;
	bool			rayfright;
}					t_ray1;

typedef struct		s_render3d
{
	int				wall_top;
	int				wa_bmt;
	double			cowal_dis;
	double			w_strip_h;
	double			dis_proj_plan;
}					t_render3d;

typedef struct		s_texture
{
	char			*fileup;
	char			*filedown;
	char			*fileright;
	char			*fileleft;
	char			*filesprite;
	int				w;
	int				h;
	int				rf;
	int				gf;
	int				bf;
	int				rc;
	int				gc;
	int				bc;
	int				*addr[5];
	int				offsetx;
	int				offsety;
	int				bits_per_pixeltx;
	int				line_lengthtx;
	int				endiantx;

}					t_texture;

typedef	struct		s_parsing
{
	int				fd;
	char			*ln;
	char			*str;
	size_t			len;
	int				inc;
	int				count_spri;
}					t_parsing;

typedef struct		s_sprite
{
	int				x;
	int				y;
	double			dis;
	double			ang;
}					t_sprite;

typedef struct		s_bmp
{
	int				bpp;
	int				fd;
	unsigned int	image_size;
	int				dh_size;
	int				pd_off_bits;
	unsigned int	filesize;
	int				bi_planes;
	unsigned int	pos;
	char			header[54];
}					t_bmp;

t_ray				g_r;
t_ray1				g_r1[WIN_WMAX / WALL_STRIP_WIDTH];
t_player			g_pl;
t_render3d			g_rd;
t_texture			g_tex;
t_parsing			g_p;
t_data				g_dt;
t_sprite			*g_sprite;

int					keypressed(int keycode);
int					keyrelease(int keycode);
int					hasaallat(double x, double y);
void				drawing_cub_walls(double tilex, double tiley);
int					update(void);
void				draw_new_map(void);
void				castallg_rs(int i);
double				normalizeangle(double angle);
int					haswallat(double x, double y);
void				raycasthorz(void);
void				raycastvert(void);
void				raycasttotal(void);
double				disbet_p(double x1, double y1, double x2, double y2);
void				render3dprojectedwalls(void);
void				raycasthorzhelp(double nexthzhitx, double nexthorztouchy);
void				raycastverthelp(double nextvrthitx, double nextverttouchy);
void				drawing_walls3d(double x, double y, double tile_z1);
void				render3dprojectedwalls(void);
void				buffertexture(void);
void				ft_readfile(int argc, char *av[]);
int					put_check(int i, int b);
void				ft_print_errors1(char *str, int index);
void				ft_print_errors(int	index);
void				ft_print_errors2(int index);
void				ft_print_errors3(int index);
int					resolution(int b);
size_t				nu_information(char **line);
void				no_so_we_ea_s(int dx1, int dx2);
void				ft_floor(char **line);
void				ft_ceilling(char **line);
void				check_map(void);
void				ft_allocate(int	x, int y);
void				check_first_end_line(void);
void				ft_putmap(int x, int y);
int					check_map1(int check, int i);
int					ft_read_map(int check);
void				ft_valid_map(int x, int y);
void				ft_check_spaces(int i, int j, int x, int y);
int					put_check_help1(int i, int b);
int					put_check_help2(int i, int b);
int					put_check_help3(int i, int b);
int					find_player(int j, int i);
void				change_spaces(void);
int					quit_win();
int					create_trgb(int r, int g, int b);
int					ft_math_utils(int i, int a);
void				ft_floor_ceilling(int i);
int					ft_initial_sprite(void);
void				ft_get_data_sprite(void);
void				ft_sort_dis_sprite(void);
void				render_sprite(int x, double dis, double stripe_h, int btm);
void				ft_draw_sprite(void);
void				bmp_initialize_header(t_bmp *bmp);
void				create_file_bmp(int i);
void				my_mlx_pixels_put(int x, int y, int	color_spr);
void				ft_check_elements1(int	a, int	b);
int					ft_increment_line(int a);
void				ft_check_elements(void);
void				ft_readfile(int argc, char *av[]);
int					put_check_ceilling(int i, int b);
void				ft_floor_help(char	**f_free);
void				ft_ceilling_help(char **f_free);
int					haswallat_hassprite(double x, double y);

#endif
