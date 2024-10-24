/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:39:42 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/24 12:43:25 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include "main.hpp"
#include <iostream>
#include <algorithm>

class Contact
{
	public:
		Contact();
		~Contact();
		
		int			orderNb;
		void		setFirstName();
		void		setLastName();
		void		setNickname();
		void		setPhoneNumber();
		void		setDarkestSecret();
		void		displayFullContacts(int i) const;
		void		displaySingleContact(int i) const;
		
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

		std::string	truncateString(const std::string &str) const;
		int			_checkInput(std::string input) const;
};

#endif
