#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor called" << std::endl;
    this->Name = "Default";
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout<<name<<" created !"<<std::endl;
    this->Name = name;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &settings)
{
    std::cout<<"Copy constructor called"<<std::endl;
    this->Name = settings.Name;
    this->HitPoints = settings.HitPoints;
    this->EnergyPoints = settings.EnergyPoints;
    this->AttackDamage = settings.AttackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &settings)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if(this != &settings)
    {
        this->Name = settings.Name;
        this->HitPoints = settings.HitPoints ;
        this->EnergyPoints = settings.EnergyPoints;
        this->AttackDamage = settings.AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"Destructor called"<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints--;
        std::cout<<"ClapTrap "<<this->Name<<" attacks "<<target
        <<", causing "<<this->AttackDamage<<" points of damage!"<<std::endl;
    }
    else
        std::cout << "ClapTrap " << this->Name << " can't attack (no energy or dead)!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoints - amount < 0)
        this->HitPoints = 0;
    else
        this->HitPoints -= amount;
    std::cout<<"ClapTrap "<<this->Name<<" takes "<<amount<<" points of damage"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->EnergyPoints--;
        this->HitPoints += amount;
        std::cout<<"ClapTrap "<<this->Name<<" repairs itself for "<<amount<<" HitPoints"<<std::endl;
    }
    else
        std::cout << "ClapTrap " << this->Name << " can't repair (no energy or dead)!" << std::endl;
}