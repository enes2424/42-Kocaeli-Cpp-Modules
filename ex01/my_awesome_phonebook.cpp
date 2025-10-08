/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:25:40 by eates             #+#    #+#             */
/*   Updated: 2023/10/08 00:57:38 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

int main(void) {
	PhoneBook phone_book;
	std::string command;
	while (true) {
		std::cin >> command;
		if (command == "ADD")
			phone_book.add();
		if (command == "SEARCH")
			phone_book.search();
		if (command == "EXIT")
			break;
	}
	return 0;
}
