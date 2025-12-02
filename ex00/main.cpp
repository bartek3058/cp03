#include "ClapTrap.hpp"

int main(void) {
    std::cout << "\n### TEST 1: STWORZENIE I PODSTAWY ###\n" << std::endl;
    {
        ClapTrap hero("Hero");

        // Powinien mieć 10 HP i 10 Energii. Atak zabiera 1 Energię.
        hero.attack("Bandit"); 
        
        // Otrzymuje obrażenia (np. 3). Powinien mieć 7 HP.
        hero.takeDamage(3); 

        // Naprawia się o 2. Powinien mieć 9 HP i stracić 1 Energię.
        hero.beRepaired(2); 
    }

    std::cout << "\n### TEST 2: WYCZERPANIE ENERGII ###\n" << std::endl;
    {
        ClapTrap spammer("Spammer");

        // Spammer ma 10 energii. Zmuśmy go do 11 ataków.
        // Ostatni atak powinien wyświetlić komunikat o braku energii.
        for (int i = 0; i < 11; i++) {
            std::cout << "Attack attempt " << i + 1 << ": ";
            spammer.attack("TargetDummy");
        }
        
        // Próba naprawy bez energii też powinna się nie udać
        std::cout << "Repair attempt without energy: ";
        spammer.beRepaired(5);
    }

    std::cout << "\n### TEST 3: ŚMIERĆ I KOPIEM LEŻĄCEGO ###\n" << std::endl;
    {
        ClapTrap victim("Victim");

        // Zabieramy mu całe życie (i jeszcze trochę)
        victim.takeDamage(15);

        // Próba ataku martwym robotem (nie powinno się udać)
        std::cout << "Attack attempt while dead: ";
        victim.attack("Ghost");

        // Próba naprawy martwego robota (nie powinno się udać - trup się nie leczy)
        std::cout << "Repair attempt while dead: ";
        victim.beRepaired(10);
    }

    std::cout << "\n### TEST 4: FORMA KANONICZNA (KOPIOWANIE) ###\n" << std::endl;
    {
        ClapTrap original("Original");
        original.takeDamage(5); // Original ma teraz 5 HP

        // Kopiowanie - copy constructor
        // clone powinien mieć też 5 HP (bo skopiował stan original)
        ClapTrap clone(original); 
        
        std::cout << "--- Klon atakuje ---" << std::endl;
        clone.attack("Original"); // Sprawdzamy czy klon żyje i działa
    } 
    // Tutaj uruchomią się destruktory dla TEST 4 (najpierw clone, potem original)

    std::cout << "\n### KONIEC TESTÓW ###\n" << std::endl;

    return 0;
}