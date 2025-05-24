/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_pipe_test_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:35 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:01:36 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <unistd.h>
#include <signal.h>

int pipe_test(void)
{
    int pipefd[2];
    
    if (pipe(pipefd) < 0)
        return (-1);
        
    close(pipefd[0]);  // 読み取り側を閉じる
    
    signal(SIGPIPE, SIG_DFL);  // SIGPIPEのデフォルト動作を確実に有効化
    
    write(pipefd[1], "test", 4);
    close(pipefd[1]);
    
    // 閉じたパイプの読み取り側にさらに書き込み
    write(pipefd[0], "more data", 9);  // SIGPIPEを発生
    
    return (0);
}