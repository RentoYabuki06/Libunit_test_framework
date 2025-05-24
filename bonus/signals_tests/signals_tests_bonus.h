/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_tests_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:10:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 17:25:46 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_TESTS_BONUS_H
# define SIGNALS_TESTS_BONUS_H

int	signals_launcher(void);
int	segv_test(void);
int	bus_test(void);
int	abrt_test(void);
int	fpe_test(void);
int	pipe_test(void);
int	ill_test(void);
int	timeout_test(void);
int	sleep_timeout_test(void);

#endif