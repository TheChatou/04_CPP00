/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:00:00 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/24 12:52:07 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

// PUBLIC	////////////////////////////////////////////////////////////////////
PhoneBook::PhoneBook()
{
	_nbContacts = 0;
    std::cout << BOLD << RED << "*" << RESET;
    std::cout << BOLD << GREEN << "*" << RESET;
    std::cout << BOLD << YELLOW << "*" << RESET;
    std::cout << BOLD << BLUE << "*" << RESET;
    std::cout << BOLD << MAGENTA << "*" << RESET;
    std::cout << BOLD << CYAN << "*" << RESET;
    std::cout << BOLD << WHITE << "* " << RESET;
    std::cout << BOLD << " Welcome to the PhoneBook " << RESET;
    std::cout << BOLD << WHITE << " *" << RESET;
    std::cout << BOLD << CYAN << "*" << RESET;
    std::cout << BOLD << MAGENTA << "*" << RESET;
    std::cout << BOLD << BLUE << "*" << RESET;
    std::cout << BOLD << YELLOW << "*" << RESET;
    std::cout << BOLD << GREEN << "*" << RESET;
    std::cout << BOLD << RED << "*" << RESET;
    std::cout << std::endl;
	std::cout << ITALIC << "You can ADD, SEARCH or EXIT" << RESET << std::endl;
	return;
}

PhoneBook::~PhoneBook()
{
	std::cout << BLUE << "*** See you soon ;) ***" << RESET << std::endl;
}

void	PhoneBook::add_contact()
{
	int oldestIndex;
	
	_nbContacts += 1;
	if (_nbContacts > 8)
	{
		std::cout << MAGENTA << "*** The Phone Book is full ***" << RESET << std::endl;
		std::cout << "do you want to erase the oldest contact ? (y/n)" << std::endl;
		std::string input;
		getline(std::cin, input);
		while (input != "y" && input != "n" && input != "Y" && input != "N")
		{
			std::cout << RED << "DUH ! Wrong input, try again: " << RESET;
			getline(std::cin, input);
		}
		if (input == "n" || input == "N")
			return;
		else if (input == "y" || input == "Y")
		{
			oldestIndex = get_oldest_contact();
			_contacts[oldestIndex] = create_contact(_contacts[oldestIndex]);
		}
	}
	else
		_contacts[_nbContacts - 1] = create_contact(_contacts[_nbContacts - 1]);
	
}

void	PhoneBook::search_contact() const
{
	int	nbContacts = _nbContacts;
	if (nbContacts > 8)
		nbContacts = 8;
	if (_nbContacts == 0)
	{
		std::cout << MAGENTA << "*** The Phone Book is empty ***" << RESET << std::endl;
		return;
	}
	std::cout << " ---------------------------------------------------" << std::endl;
	std::cout << "| " << std::setw(10) <<"Index" << " | "
          << std::setw(10) << "First Name" << " | "
          << std::setw(10) << "Last Name" << " | "
          << std::setw(10) << "Nickname" << " |" << std::endl;
	std::cout << " ---------------------------------------------------" << std::endl;
	for (int i = 0; i < nbContacts; i++)
		_contacts[i].displayFullContacts(i);
	std::cout << " ---------------------------------------------------" << std::endl;
	std::cout << std::endl << " -- Enter the index of the contact you want to display: ";
	std::string input;
	getline(std::cin, input);
	char *end;
	int index = (static_cast<int>(std::strtol(input.c_str(), &end, 10))) - 1;
	while (index < 0 || index >= nbContacts || *end != '\0')
	{
		std::cout << RED << "DUH ! Wrong input, try again: " << RESET;
		getline(std::cin, input);
		index = (static_cast<int>(std::strtol(input.c_str(), &end, 10))) - 1;
	}
	_contacts[index].displaySingleContact(index);
}

// _PRIVATE	///////////////////////////////////////////////////////////////////
int	PhoneBook::get_oldest_contact() const
{
	int	oldestIndex = 0;
	
	if (_nbContacts < 8)
		return _nbContacts - 1;
	else
	{
		int	oldest = _contacts[0].orderNb;
		int	nbContacts = _nbContacts;
		if (nbContacts > 8)
			nbContacts = 8;
		for (int i = 0; i < nbContacts; ++i)
		{
			if (_contacts[i].orderNb < oldest)
			{
				oldest = _contacts[i].orderNb;
				oldestIndex = i;
			}
		}
		return oldestIndex;
	}
}

Contact	PhoneBook::create_contact(Contact contactToCreate)
{
	contactToCreate.orderNb = _nbContacts;
	contactToCreate.setFirstName();
	contactToCreate.setLastName();
	contactToCreate.setNickname();
	contactToCreate.setPhoneNumber();
	contactToCreate.setDarkestSecret();
	return (contactToCreate);
	std::cout << "Contact added" << std::endl;
	std::cout << "The PhoneBook has " << _nbContacts << " contacts now" << std::endl << std::endl;
}
