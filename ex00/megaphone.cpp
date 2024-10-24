/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:00:46 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/21 13:43:04 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int j = 1; argc > 1 && argv[j]; j++)
	{
		for (int i = 0; i < (int)strlen(argv[j]); i++)
		{
			if (argv[j][i] == ' ')
				std::cout << ' ';
			else
				std::cout << (char) toupper(argv[j][i]);
		}
	}
	std::cout << std::endl;
	return (0);
}
