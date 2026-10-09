/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	t_itoa_neg(void)
{
	char	*out;

	out = ft_itoa(INT_MIN);
	check_str(out, "-2147483648", "ft_itoa INT_MIN");
	free(out);
	out = ft_itoa(1000000);
	check_str(out, "1000000", "ft_itoa powers of ten");
	free(out);
	out = ft_itoa(-1000000);
	check_str(out, "-1000000", "ft_itoa negative powers of ten");
	free(out);
	out = ft_itoa(-1);
	check_str(out, "-1", "ft_itoa -1");
	free(out);
}

static void	idx_set(unsigned int i, char *c)
{
	*c = (char)(i + '0');
}

void	t_iteri(void)
{
	char	buf[8];

	strcpy(buf, "abcd");
	ft_striteri(buf, idx_set);
	check_str(buf, "0123", "ft_striteri index and in-place write");
	strcpy(buf, "");
	ft_striteri(buf, idx_set);
	check_str(buf, "", "ft_striteri empty string untouched");
}

static void	fd_write_all(int fd)
{
	ft_putchar_fd('A', fd);
	ft_putstr_fd("BC", fd);
	ft_putendl_fd("DE", fd);
	ft_putnbr_fd(0, fd);
	ft_putnbr_fd(-42, fd);
	ft_putnbr_fd(INT_MIN, fd);
	ft_putnbr_fd(INT_MAX, fd);
	ft_putstr_fd("", fd);
	ft_putendl_fd("", fd);
}

void	t_fd(void)
{
	char	path[32];
	char	buf[128];
	ssize_t	nb;
	int		fd;

	strcpy(path, "/tmp/ft_libft_XXXXXX");
	fd = mkstemp(path);
	check(fd >= 0, "mkstemp for the fd tests");
	if (fd < 0)
		return ;
	fd_write_all(fd);
	lseek(fd, 0, SEEK_SET);
	nb = read(fd, buf, sizeof(buf) - 1);
	if (nb < 0)
		nb = 0;
	buf[nb] = '\0';
	close(fd);
	unlink(path);
	check_str(buf, "ABCDE\n0-42-21474836482147483647\n", "fd output stream");
}
