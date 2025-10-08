/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:49:55 by eates             #+#    #+#             */
/*   Updated: 2023/10/12 18:28:19 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

PhoneBook::PhoneBook(void) {
	index = 0;
	is_full = false;
}

void PhoneBook::add(void) {
	std::string name, surname, nickname, phone_no, dark_secret;
	std::cout << "Name : ";
	std::cin >> name;
	std::cout << "Surname : ";
	std::cin >> surname;
	std::cout << "Nickname : ";
	std::cin >> nickname;
	std::cout << "Phone Number : ";
	std::cin >> phone_no;
	std::cout << "Darkest Secret : ";
	std::cin >> dark_secret;
	if (index == 8) {
		index = 0;
		is_full = true;
	}
	people_array[index] = Contact(name, surname, nickname, phone_no, dark_secret);
	index++;
}

void PhoneBook::search(void) {
	std::string	b;
	int			a = 0;

	std::cout << "|     index|      name|   surname|  nickname|" << std::endl;
	if (is_full)
		for (int i = 0; i < 8; i++)
			std::cout << "|         " << i + 1 << people_array[i].get_info() << std::endl;
	else
		for (int i = 0; i < index; i++)
			std::cout << "|         " << i + 1 << people_array[i].get_info() << std::endl;
	std::cout << "search : ";
	std::cin >> b;
	a = b[0] - 48;
	if (b.length() > 1 || (is_full && a > 8) || (!is_full &&  a > index) || a < 1)
		std::cout << "Error" << std::endl;
	else
		people_array[a - 1].print_info();
}
