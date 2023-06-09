/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:10:55 by dhendzel          #+#    #+#             */
/*   Updated: 2023/07/03 15:52:00 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) 
{
	ScavTrap	bot5("hei");
	ScavTrap	bot4;
	ClapTrap	bot3;
	ClapTrap	bot("bot");
	ClapTrap	bot2("Vanya");

	bot4 = ScavTrap(bot5);
	std::cout << bot.getName() << std::endl;
	for (int i = 0; i < 5; i++)
		bot.trueAttack(&bot5);
	bot3.trueAttack(&bot5);
	bot4.trueAttack(&bot5);
	bot4.trueAttack(&bot5);
	bot4.trueAttack(&bot5);
	bot4.trueAttack(&bot5);
	bot4.trueAttack(&bot5);
	bot4.trueAttack(&bot5);
	bot4.trueAttack(&bot5);
	
	bot5.guardGate();
	return (0);
}