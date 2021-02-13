#include "../cub3d.h"

void	bmp_initialize_header(t_bmp *bmp)
{
	int		i;
	i = 0;
	bmp->bpp = 32;
	bmp->image_size = g_dt.win_w * g_dt.win_h * 4;
	bmp->dh_size = 40;
	bmp->pd_off_bits = 54;
	bmp->filesize = 54 + bmp->image_size;
	//bmp->bi_planes = 1;
	while (i < 54)
		bmp->header[i++] = 0;
	ft_memcpy(bmp->header, "BM", 2);
	ft_memcpy(bmp->header + 2, &bmp->filesize, 4);
	ft_memcpy(bmp->header + 10, &bmp->pd_off_bits, 4);
	ft_memcpy(bmp->header + 14, &bmp->dh_size, 4);
	ft_memcpy(bmp->header + 18, &g_dt.win_w, 4);
	ft_memcpy(bmp->header + 22, &g_dt.win_h, 4);
	ft_memcpy(bmp->header + 26, &bmp->bi_planes, 2);
	ft_memcpy(bmp->header + 28, &bmp->bpp, 2);
	ft_memcpy(bmp->header + 34, &bmp->image_size, 4);
}
void	create_file_bmp(int i)
{
	t_bmp			bmp;
	int				j;
	int				*pixel;
	bmp_initialize_header(&bmp);
	j = g_dt.win_h - 1;
	if ((bmp.fd = open("cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		perror("Error\nopen");
		exit(EXIT_FAILURE);
	}
	write(bmp.fd, bmp.header, 54);
	while (j > -1)
	{
		i = 0;
		while (i < g_dt.win_w)
		{
			bmp.pos = (i + g_dt.win_w * j);
			pixel = g_dt.addr + bmp.pos;
			write(bmp.fd, pixel, 4);
			i++;
		}
		j--;
	}
	close(bmp.fd);
}