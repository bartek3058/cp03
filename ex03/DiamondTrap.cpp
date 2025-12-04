#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->Name = "Default";
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;

	std::cout<< "DiamondTrap Default Constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name)
		: ClapTrap(name + "_clap_name"),
		  ScavTrap(name),
		  FragTrap(name)
{
	this->Name = name;
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;

	std::cout << "DiamondTrap Constructor for " << this->Name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}
void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap named: " << this->Name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::Name << std::endl;
}