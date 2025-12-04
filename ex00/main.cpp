#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "\n### TEST 1: CREATION AND BASICS ###\n" << std::endl;
    {
        ClapTrap hero("Hero");

        // Should have 10 HP and 10 Energy. Attack costs 1 Energy.
        hero.attack("Bandit"); 
        
        // Takes damage (e.g., 3). Should have 7 HP.
        hero.takeDamage(3); 

        // Repairs itself by 2. Should have 9 HP and lose 1 Energy.
        hero.beRepaired(2); 
    }

    std::cout << "\n### TEST 2: ENERGY EXHAUSTION ###\n" << std::endl;
    {
        ClapTrap spammer("Spammer");

        // Spammer has 10 energy. Let's force it to attack 11 times.
        // The last attack should display a 'no energy' message.
        for (int i = 0; i < 11; i++) {
            std::cout << "Attack attempt " << i + 1 << ": ";
            spammer.attack("TargetDummy");
        }
        
        // Attempting to repair without energy should also fail
        std::cout << "Repair attempt without energy: ";
        spammer.beRepaired(5);
    }

    std::cout << "\n### TEST 3: DEATH MECHANICS ###\n" << std::endl;
    {
        ClapTrap victim("Victim");

        // Taking all HP (and then some)
        victim.takeDamage(15);

        // Attack attempt by a dead robot (should fail)
        std::cout << "Attack attempt while dead: ";
        victim.attack("Ghost");

        // Repair attempt by a dead robot (should fail - dead can't heal)
        std::cout << "Repair attempt while dead: ";
        victim.beRepaired(10);
    }

    std::cout << "\n### TEST 4: CANONICAL FORM (COPYING) ###\n" << std::endl;
    {
        ClapTrap original("Original");
        original.takeDamage(5); // Original now has 5 HP

        // Copying - copy constructor
        // Clone should also have 5 HP (because it copied original's state)
        ClapTrap clone(original); 
        
        std::cout << "--- Clone attacks ---" << std::endl;
        clone.attack("Original"); // Check if clone is alive and functional
    } 
    // Destructors for TEST 4 will run here (first clone, then original)

    std::cout << "\n### END OF TESTS ###\n" << std::endl;

    return 0;
}