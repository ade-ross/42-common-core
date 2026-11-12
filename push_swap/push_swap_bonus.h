/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:31:36 by ade-ross          #+#    #+#             */
/*   Updated: 2025/02/08 20:36:15 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int		check_command_exist_and_do_it(char *s, t_list **st_a, t_list **st_b);
int		write_result(int flag, t_list **st_a, t_list **st_b);

void	*ft_calloc(int nmemb, int size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, int start, int len);
char	*get_next_line(int fd);

char	*check_for_word(char *fin_buffer, int	*i);
char	*new_read(char *fin_buffer, int *buffercheck, int fd);
char	*final_checks(char **fin_buffer);
char	*check_buf_or_upd_fin_buf(char **fin_buffer, int i, char *buffer);
int		ft_strncmp(const char *s1, const char *s2, int n);

void	sa_b(t_list **stack_a);
void	sb_b(t_list **stack_b);
void	ss_b(t_list **stack_a, t_list **stack_b);
void	pa_b(t_list **stack_a, t_list **stack_b);
void	pb_b(t_list **stack_a, t_list **stack_b);
void	ra_b(t_list **stack_a);
void	rb_b(t_list **stack_b);
void	rr_b(t_list **stack_a, t_list **stack_b);
void	rra_b(t_list **stack_a);
void	rrb_b(t_list **stack_b);
void	rrr_b(t_list **stack_a, t_list **stack_b);
#endif
