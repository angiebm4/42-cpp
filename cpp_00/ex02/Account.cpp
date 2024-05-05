/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:12:52 by angela            #+#    #+#             */
/*   Updated: 2024/05/04 14:04:41 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

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
    return ;
}

/* DESTRUCTOR */

Account::~Account(void)
{
    return ;
}


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
    std::cout << " index:" << _accountIndex;
    //  index:1;amount:54;deposits:0;withdrawals:0
    return ;
}
void	Account::displayStatus(void) const
{
    return ;
}

int		Account::checkAmount(void) const
{
    return (0);
}

bool	Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
        return(false);
    else
        _amount = _amount - withdrawal;
    return (true);
}

void	Account::makeDeposit(int deposit)
{
    _nbDeposits += 1;
    _amount = _amount + deposit;
    return ;
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


