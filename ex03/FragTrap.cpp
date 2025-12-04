#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default Constructor called" << std::endl;
    this->Name = "Default";
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap Constructor for " << this->Name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap Assignation operator called" << std::endl;
    if (this != &src)
        ClapTrap::operator=(src);
return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints--;
        std::cout<<"FragTrap "<<this->Name<<" attacks "<<target
        <<", causing "<<this->AttackDamage<<" points of damage!"<<std::endl;
    }
    else
        std::cout << "FragTrap " << this->Name << " can't attack (no energy or dead)!" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
    	std::cout<<"FragTrap "<< this->Name<< " says: Give me a high five !"<<std::endl;
	else
		std::cout<<"FragTRap " << this->Name << " is too tired/dead for a high five." << std::endl;
}