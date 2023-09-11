/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jternero <jternero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:19:40 by lde-la-h          #+#    #+#             */
/*   Updated: 2023/06/28 16:20:22 by jternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.h"
#include "/Users/jternero/Desktop/so_long/include/MLX42/include/MLX42/MLX42.h"

int32_t main(void)
{
	TEST_DECLARE("mlx_init");
	TEST_EXPECT(PASS);

	mlx_set_setting(MLX_HEADLESS, true);
	mlx_t* mlx = mlx_init(32, 32, "TEST", false);
	assert(mlx);
	assert(mlx_errno == MLX_SUCCESS);
	mlx_terminate(mlx);
	TEST_EXIT(EXIT_SUCCESS);
}
