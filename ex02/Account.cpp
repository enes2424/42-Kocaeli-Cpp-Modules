/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eates <eates@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:17:17 by eates             #+#    #+#             */
/*   Updated: 2023/07/29 19:55:52 by eates            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<ctime>
#include"Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit( int deposit ) {
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused\n";
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amounts:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	char buffer[18];
	std::time_t now = std::time(NULL);
    std::tm* timeinfo = std::localtime(&now);
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "] ";
}
