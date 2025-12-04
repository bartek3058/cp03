#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "\n### TEST 1: CONSTRUCTOR CHAINING ###\n" << std::endl;
    {
        // Demonstration of construction order: ClapTrap -> ScavTrap
        std::cout << "[Creating ScavTrap named 'Serena']" << std::endl;
        ScavTrap serena("Serena");
    } 
    // Demonstration of destruction order: ScavTrap -> ClapTrap
    std::cout << "[Serena went out of scope - Destructors called]" << std::endl;


    std::cout << "\n### TEST 2: CLAPTRAP VS SCAVTRAP ATTACK ###\n" << std::endl;
    {
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavvy");

        std::cout << "\n--- Attack Comparison ---" << std::endl;
        // ClapTrap uses standard attack
        clap.attack("Target A");
        
        // ScavTrap uses overwritten attack (should display different message/damage)
        scav.attack("Target B");
    }


    std::cout << "\n### TEST 3: SPECIAL ABILITY (GUARD GATE) ###\n" << std::endl;
    {
        ScavTrap guard("GateKeeper");
        
        // Testing the new member function specific to ScavTrap
        guard.guardGate();
    }


    std::cout << "\n### TEST 4: DURABILITY & STATS CHECK ###\n" << std::endl;
    {
        // ScavTrap should have 100 HP. ClapTrap only had 10.
        ScavTrap tank("Tank");

        std::cout << "--- Taking massive damage (50 points) ---" << std::endl;
        // A regular ClapTrap would die here. ScavTrap should survive.
        tank.takeDamage(50); 
        
        std::cout << "--- Repairing ---" << std::endl;
        tank.beRepaired(10); // Should work if alive
    }

    std::cout << "\n### END OF TESTS ###\n" << std::endl;

    return 0;
}