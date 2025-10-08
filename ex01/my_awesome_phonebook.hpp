/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:38:58 by eates             #+#    #+#             */
/*   Updated: 2023/10/12 18:25:25 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MY_AWESOME_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_HPP

#include<iostream>

class Contact {

public:

	Contact (std::string name, std::string surname, std::string nickname, std::string phone_no, std::string dark_secret);
	Contact (void);
	std::string get_info(void);
	void print_info(void);

private:

	std::string fixed_to_ten_characters(std::string name);
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone_no;
	std::string dark_secret;

};

class PhoneBook {

public:

	PhoneBook(void);
	void add(void);
	void search(void);

private:

	Contact people_array[8];
	int	index;
	bool is_full;

};

#endif
