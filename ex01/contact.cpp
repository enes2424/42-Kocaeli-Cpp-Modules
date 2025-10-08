/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:09:29 by eates             #+#    #+#             */
/*   Updated: 2023/10/12 18:33:07 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

Contact::Contact (std::string name, std::string surname, std::string nickname, std::string phone_no, std::string dark_secret) {
	this->name = name;
	this->surname = surname;
	this->nickname = nickname;
	this->phone_no = phone_no;
	this->dark_secret = dark_secret;
}

Contact::Contact(void) {
}

std::string Contact::get_info(void) {
	return "|" + fixed_to_ten_characters(name) + "|" + fixed_to_ten_characters(surname) + "|" + fixed_to_ten_characters(nickname)  + "|";
}

std::string Contact::fixed_to_ten_characters(std::string name) {
	std::string str;
	int i;
	for (i = 0; i < 10 - (int)name.length(); i++)
		str += ' ';
	for (i = 0; i < 9 && i < (int)name.length(); i++)
		str += name[i];
	if (name.length() > 10)
		str += '.';
	else if (name.length() == 10)
		str += name[i];
	return str;
}

void Contact::print_info(void) {
	std::cout << "Name : " << name << "\nSurname : " << surname << "\nNickname : " << nickname << "\nPhone Number : ";
	std::cout << phone_no << "\nDarkest Secret : " << dark_secret << std::endl;
}
