/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:40:06 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/06/14 08:15:09 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define ERROR -1
# define CONTINUE 1
# define NOREAD 2
# define ALLOUTPUT 3
# define SPLITSTOCK 4
# define DONOTHING 5
# define GUACA_FDMAX 256
# define BUFFER_SIZE 256
int		ft_join_stck_rd(char **stockdata, char **readbuf, int INFO);
int		ft_make_readbuf(int fd, char **readbuf);
int		ft_howoutput(char **stockdata, char **rtn, int INFO);
char	*get_next_line(int fd);
#endif
