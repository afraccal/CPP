/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:28:22 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/30 14:35:41 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"
#include "iomanip"
#include "ctime"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    struct tm *stamp;
    time_t timer;

    timer = time(NULL);
    stamp = localtime(&timer);
    std::cout << "[";
    std::cout << stamp->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << stamp->tm_mon;
    std::cout << std::setfill('0') << std::setw(2) << stamp->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << stamp->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << stamp->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << stamp->tm_sec;
    std::cout << "]";
}

int Account::getNbAccounts(void)
{
    return(_nbAccounts);
}

int Account::getNbDeposits(void)
{
    return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return(_totalNbWithdrawals);
}

int Account::getTotalAmount(void)
{
    return(_totalAmount);
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << ";" << std::endl;
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount + deposit << ";";
    std::cout << "nb_deposits:" << _nbDeposits + 1<< ";" << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:";
    if (_amount >= withdrawal)
    {
        std::cout << withdrawal << ";";
        std::cout << "amount:" << _amount - withdrawal  << ";";
        std::cout << "nb_withdrawals:" << _nbWithdrawals + 1 << ";" << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
    }
    else
        std::cout << "refused" << std::endl;
    return (false);   
}

int Account::checkAmount( void ) const
{
    return (_amount);
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
    return;
}