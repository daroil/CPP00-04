/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:06:11 by dhendzel          #+#    #+#             */
/*   Updated: 2023/07/03 15:44:50 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

class ClapTrap
{
	public:
		ClapTrap(void);
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &ClapTrap);
		ClapTrap &operator=( ClapTrap const &obj );
		void		attack(const std::string &target);
		void		trueAttack(ClapTrap *target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amoung);
		std::string	getName(void);
	protected:
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		std::string	_name;
};


#endif