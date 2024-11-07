/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:02:11 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/24 14:51:09 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

// PUBLIC	////////////////////////////////////////////////////////////////////
Contact::Contact(void)
{
	orderNb = 0;
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_phoneNumber = "";
	_darkestSecret = "";
}

Contact::~Contact() {}

void	Contact::setFirstName()
{
	std::string firstName;
	
	std::cout << BLUE << " > " << RESET << UNDERLINE << "Enter first name:" << RESET << " \t\t";
	getline(std::cin, firstName);
	if (_checkInput(firstName) == 1)
	{
		std::cout << RED << "Invalid input, try again: " << RESET << std::endl;
		return setFirstName();
	}
	_firstName = firstName;
}

void	Contact::setLastName()
{
	std::string lastName;
	
	std::cout << BLUE << " > " << RESET << UNDERLINE << "Enter last name:" << RESET << " \t\t";
	getline(std::cin, lastName);
	if (_checkInput(lastName) == 1)
	{
		std::cout << RED << "Invalid input, try again: " << RESET << std::endl;
		return setFirstName();
	}
	_lastName = lastName;
}
void	Contact::setNickname()
{
	std::string nickname;
	
	std::cout << BLUE << " > " << RESET << UNDERLINE << "Enter nickname:" << RESET << " \t\t";
	getline(std::cin, nickname);
	if (_checkInput(nickname) == 1)
	{
		std::cout << RED << "Invalid input, try again: " << RESET << std::endl;
		return setFirstName();
	}
	_nickname = nickname;
}

void	Contact::setPhoneNumber()
{
	std::string	phoneNumber;

	std::cout << BLUE << " > " << RESET << UNDERLINE << "Enter phone number:" << RESET << " \t\t";
	getline(std::cin, phoneNumber);
	if (_checkInput(phoneNumber) == 1)
	{
		std::cout << RED << "Invalid input, try again: " << RESET << std::endl;
		return setFirstName();
	}
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret()
{
	std::string darkestSecret;
	
	std::cout << BLUE << " > " << RESET << UNDERLINE << "Enter darkest secret:" << RESET << " \t";
	getline(std::cin, darkestSecret);
	if (_checkInput(darkestSecret) == 1)
	{
		std::cout << RED << "Invalid input, try again: " << RESET << std::endl;
		return setFirstName();
	}
	_darkestSecret = darkestSecret;
	
}

void	Contact::displayFullContacts(int i) const
{
    std::cout << "| " << std::setw(10) << i + 1 << " | ";
    std::cout << std::setw(10) << _truncateString(_firstName) << " | ";
    std::cout << std::setw(10) << _truncateString(_lastName) << " | ";
    std::cout << std::setw(10) << _truncateString(_nickname) << " |" << std::endl;
}

void	Contact::displaySingleContact(int i) const
{
	std::cout << std::endl << BOLD << " > CONTACT " << i + 1 << " :" << RESET << std::endl;
	std::cout << ITALIC << "First Name: " << "\t\t" << RESET << _firstName << std::endl;
	std::cout << ITALIC << "Last Name: " << "\t\t" << RESET << _lastName << std::endl;
	std::cout << ITALIC << "Nickname: " << "\t\t" << RESET << _nickname << std::endl;
	std::cout << ITALIC << "Phone Number: " << "\t\t"<< RESET << _phoneNumber  << std::endl;
	std::cout << ITALIC << "Darkest Secret: " << "\t"<< RESET << _darkestSecret  << std::endl << std::endl;
}

// _PRIVATE	///////////////////////////////////////////////////////////////////
std::string Contact::_truncateString(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

// Check if input is valid
// Nouvelle maniere d'iterer sur une string, grace a std::string::iterator,
// qui cree un iterateur sur la string, et permet de parcourir la string via
// begin et end (qui sont des fonctions de l'iterateur)
int	Contact::_checkInput(std::string input) const
{
	if (std::cin.eof())
		return 1;
	for (std::string::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (!isprint(*it))
			return 1;
	}
	bool onlySpaces = true;
	for (std::string::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (!std::isspace(*it))
		{
			onlySpaces = false;
			break;
		}
	}
	if (onlySpaces || input.empty())
		return 1;
	return 0;
}
