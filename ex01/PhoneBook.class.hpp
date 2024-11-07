/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:35:54 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/24 13:51:22 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "main.hpp"
#include <iostream>
#include "Contact.class.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		void		add_contact();
		void		search_contact() const;

	private:
		Contact		_contacts[8];
		int			_nbContacts;
		
		int			get_oldest_contact() const;
		Contact		create_contact(Contact contact);
};

#endif