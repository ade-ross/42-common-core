/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-ross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:20:11 by ale               #+#    #+#             */
/*   Updated: 2025/03/26 19:14:40 by ade-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
/* long int	get_time_m(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	printf("tv.tv_sec: %ld\n", tv.tv_sec);
	printf("tv.tv_usec: %ld\n", tv.tv_usec);
	long int n = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	printf("get_time: %ld\n", n);
	return (n);
} */
//return (((tv.tv_sec % 1000000) * (long int)1000) + (tv.tv_usec / 1000));
/* int main ()
{
long int i = get_time();
printf("i:       %ld\n", i);
printf("longmax: %ld\n",__LONG_MAX__);
printf("longmax3: %u\n",__UINT32_MAX__);
} */
