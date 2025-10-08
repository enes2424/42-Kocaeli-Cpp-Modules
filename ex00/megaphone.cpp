/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:10:10 by eates             #+#    #+#             */
/*   Updated: 2023/10/08 00:33:50 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[]) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j]; j++) {
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				std::cout << static_cast<char>(argv[i][j] - 32);
			else std::cout << argv[i][j];
		}
	return std::cout << std::endl, 0;
}
