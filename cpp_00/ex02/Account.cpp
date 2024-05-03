/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:12:52 by angela            #+#    #+#             */
/*   Updated: 2024/05/03 19:08:46 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

/* CONSTRUCTOR */

Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
    return ;
}

/* DESTRUCTOR */

Account::~Account(void)
{
    return ;
}

void	Account::_displayTimestamp( void )
{
    return ;
}

void	Account::displayStatus( void ) const
{
    return ;
}

int		Account::checkAmount( void ) const
{
    return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > _amount)
        return(false);
    else
        _amount = _amount - withdrawal;
    return (true);
}

void	Account::makeDeposit( int deposit )
{
    return ;
}

void	displayAccountsInfos( void )
{
    return ;
}


/* GETTERS */

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}


