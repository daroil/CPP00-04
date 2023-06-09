/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:06:34 by dhendzel          #+#    #+#             */
/*   Updated: 2023/07/03 15:41:29 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name("Untitled")
{
	std::cout << "Assembling the ClapTrap without name" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name)
{
	std::cout << "Assembling the ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ClapTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ClapTrap;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &instance) {
	this->_name = instance._name;
	this->_hitPoints = instance._hitPoints;
	this->_energyPoints = instance._energyPoints;
	this->_attackDamage = instance._attackDamage;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << "Dissassembling the ClapTrap" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage" << std::endl;
	}
	else
		std::cout << _name << " can't do anything" << std::endl;
}

std::string	ClapTrap::getName(void)
{
	return (_name);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << _name << " takes " << amount << " points of damage" << std::endl;
	}	
	else
		std::cout << _name << " is already broken" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << _name << " repairs itself for " << amount << " of hit points" << std::endl;
	}	
	else
		std::cout << _name << " can't do anything" << std::endl;
}

void	ClapTrap::trueAttack(ClapTrap *target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->attack(target->getName());	
		target->takeDamage(this->_attackDamage);
	}
	else
		std::cout << this->_name << " can't do anything" << std::endl;
}
