#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default Constructor called" << std::endl;
    this->Name = "Default";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap Constructor for " << this->Name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    if (this != &src)
        ClapTrap::operator=(src);
return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints--;
        std::cout<<"ScavTrap "<<this->Name<<" attacks "<<target
        <<", causing "<<this->AttackDamage<<" points of damage!"<<std::endl;
    }
    else
        std::cout << "ScavTrap " << this->Name << " can't attack (no energy or dead)!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap is now in Gate keeper mode."<<std::endl;
}