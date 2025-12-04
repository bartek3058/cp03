#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "\n### TEST 1: CONSTRUCTION CHAINING ###\n" << std::endl;
    {
        // Expected output:
        // 1. ClapTrap Constructor
        // 2. FragTrap Constructor
        std::cout << "[Creating FragTrap 'Grenadier']" << std::endl;
        FragTrap frag("Grenadier");
    }
    // Expected output (reverse order):
    // 1. FragTrap Destructor
    // 2. ClapTrap Destructor
    std::cout << "[Grenadier went out of scope - Destructors called]" << std::endl;


    std::cout << "\n### TEST 2: ATTACK DAMAGE CHECK ###\n" << std::endl;
    {
        FragTrap frag("Blaster");

        std::cout << "\n--- Attack Test ---" << std::endl;
        // FragTrap should deal 30 points of damage (unlike ClapTrap's 0 or ScavTrap's 20)
        frag.attack("Target Dummy");
    }


    std::cout << "\n### TEST 3: SPECIAL ABILITY (HIGH FIVE) ###\n" << std::endl;
    {
        FragTrap positiveBot("Mr. Nice Guy");

        std::cout << "\n--- Requesting High Five ---" << std::endl;
        // This is the unique method for FragTrap
        positiveBot.highFiveGuys();
    }


    std::cout << "\n### TEST 4: DURABILITY & ENERGY STATS ###\n" << std::endl;
    {
        // FragTrap has 100 HP and 100 Energy.
        FragTrap tank("Tank");

        std::cout << "--- Taking massive damage (90 points) ---" << std::endl;
        // With 100 HP, it should survive 90 damage (leaving 10 HP).
        tank.takeDamage(90);

        std::cout << "--- Trying to repair ---" << std::endl;
        // It should still be alive to repair itself.
        tank.beRepaired(10);
        
        // Optional: Check if High Five works after damage
        tank.highFiveGuys();
    }

    std::cout << "\n### END OF TESTS ###\n" << std::endl;

    std::cout << "\n### TEST 1: DIAMONDTRAP CONSTRUCTION ###\n" << std::endl;
    {
        // Kolejność powinna być: ClapTrap -> ScavTrap -> FragTrap -> DiamondTrap
        // Ale ClapTrap tylko RAZ!
        DiamondTrap monster("Monster");

        std::cout << "\n--- Who Am I? ---" << std::endl;
        monster.whoAmI(); 
        // Powinno wypisać:
        // I am DiamondTrap named: Monster
        // My ClapTrap name is: Monster_clap_name

        std::cout << "\n--- Stats Check ---" << std::endl;
        // Atak ze ScavTrapa -> "ScavTrap Monster attacks..."
        monster.attack("Victim"); 
        
        // Sprawdź w debuggerze lub wypisz gettery, czy:
        // HP = 100 (od Frag)
        // Energy = 50 (od Scav)
        // Dmg = 30 (od Frag)
        
    } // Destruktory w odwrotnej kolejności

    return 0;
}