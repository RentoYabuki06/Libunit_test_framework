/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:53:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/11 09:42:14 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_range(long num, char c)
{
	if (num > LONG_MAX / 10)
		return (-1);
	if (num == LONG_MAX / 10 && c - '0' > LONG_MAX % 10)
		return (-1);
	return (0);
}

static int	ft_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	ans;

	ans = 0;
	sign = 1;
	i = ft_sign(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_check_range(ans, str[i]) == -1)
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			if (sign == -1)
				return ((int)LONG_MIN);
		}
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return ((int)ans * sign);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int ft_atoi(const char *str); // 自作関数のプロトタイプ

// void run_test(const char *input)
// {
// 	int std = atoi(input);
// 	int custom = ft_atoi(input);
// 	printf("入力: \"%s\"\n", input);
// 	printf("→ atoi    = %d\n", std);
// 	printf("→ ft_atoi = %d\n", custom);
// 	printf("%s\n\n", (std == custom) ? "✅ OK" : "❌ 差異あり");
// }

// int main(void)
// {
// 	const char *tests[] = {
// 		"42",
// 		"-42",
// 		"   123",
// 		"+7",
// 		"4193 with words",
// 		"words and 987",
// 		"-91283472332",
// 		"9223372036854775808",
// 		"-9223372036854775808",
// 		"92233720368547758080000000000",
// 		"-92233720368547758080000000000",
// 		"",
// 		"0",
// 		"000001",
// 		"2147483647"
// 	};

// 	int total_tests = sizeof(tests) / sizeof(tests[0]);

// 	for (int i = 0; i < total_tests; i++)
// 	{
// 		run_test(tests[i]);
// 	}

// 	return 0;
// }
