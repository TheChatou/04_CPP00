/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:07:46 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/24 14:20:17 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "PhoneBook.class.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	while (true)
	{
		std::cout << std::endl << BOLD << " > Enter command: " << RESET << std::endl;
		getline(std::cin, input);

		if (input == "ADD")
			phoneBook.add_contact();
		else if (input == "SEARCH")
			phoneBook.search_contact();
		else if (input == "EXIT")
			break;
		else
			std::cout << RED << "Invalid command. Please try again." << RESET << std::endl;
	}
	return 0;
}