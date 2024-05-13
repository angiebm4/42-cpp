/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:12:52 by angela            #+#    #+#             */
/*   Updated: 2024/05/13 23:46:56 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* CONSTRUCTOR */

Account::Account()
{
    return ;
}

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created";
    std::cout << std::endl;
}

/* DESTRUCTOR */

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed";
    std::cout << std::endl;
}

/* METODS */

void	Account::_displayTimestamp(void)
{
    time_t aux;
    struct tm *time_info;

    time (&aux);
    time_info = localtime(&aux); 
    std::cout << "[";
    std::cout << time_info->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_mday;
    std::cout << "_"; 
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_sec;
    std::cout << "]";
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts;
    std::cout <<  ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawal:" << _totalNbWithdrawals;
    std::cout << std::endl;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals; 
    std::cout << std::endl;
}

int		Account::checkAmount(void) const
{
    return (0);
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawal:" << withdrawal;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused";
        std::cout << std::endl;
        return(false);
    }
    else
    {
        _amount = _amount - withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";amount:" << _amount;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals;
        std::cout << std::endl;

    }
    return (true);
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _nbDeposits += 1;
    _totalNbDeposits++;
    _amount = _amount + deposit;
    _totalAmount += deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

/* GETTERS */

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}
