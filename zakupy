#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <array>

class Produkt {
public:
    std::string nazwa;
    double cena;

    Produkt(std::string n, double c) : nazwa(n), cena(c) {}
};

std::vector<Produkt> generujLosoweProdukty(int liczbaProduktow) {
    std::vector<Produkt> produkty;
    std::array <std::string, 6> nazwy = {"chleb", "mleko", "jajka", "maslo", "cukier", "jablka"};
    
    for (int i = 0; i < liczbaProduktow; ++i) {
        std::string nazwa = nazwy[rand() % nazwy.size()];
        double cena = (rand() % 1000) / 100.0;
        produkty.push_back(Produkt(nazwa, cena));
    }
    
    return produkty;
}

void wyswietlProdukty(const std::vector<Produkt>& produkty) {
    std::cout << "lista produktow:\n";
    for (size_t i = 0; i < produkty.size(); ++i) {
        std::cout << i+1 << ". " << produkty[i].nazwa << " - " << produkty[i].cena << " zł\n";
    }
}

void wyswietlInfoOProdukcie(const Produkt& produkt) {
    std::cout << "informacje o produkcie:\n";
    std::cout << "nazwa: " << produkt.nazwa << "\n";
    std::cout << "cena: " << produkt.cena << " zł\n";
}

std::map<std::string, std::vector<double>> generujMapeCen(const std::vector<Produkt>& produkty) {
    std::map<std::string, std::vector<double>> mapa_cen;
    for(const auto& produkt : produkty) {
        mapa_cen[produkt.nazwa].push_back(produkt.cena);
    }
    return mapa_cen;
}

int main() {
    std::srand(std::time(nullptr));

    std::vector<Produkt> produkty;
    int liczbaProduktow;
    std::cout << "podaj liczbe produktow do wygenerowania: ";
    std::cin >> liczbaProduktow;
    produkty = generujLosoweProdukty(liczbaProduktow);
    
    wyswietlProdukty(produkty);
    
    int opcja;
    std::cout << "\nwpisz numer produktu aby zobaczyc informacje (0 aby zakonczyc): ";
    std::cin >> opcja;
    while (opcja != 0) {
        if (opcja > 0 && opcja <= static_cast<int>(produkty.size())) {
            wyswietlInfoOProdukcie(produkty[opcja - 1]);
        } else {
            std::cout << "nieprawidlowy numer produktu.\n";
        }
        std::cout << "\nwpisz numer produktu aby zobaczyc informacje (0 aby zakonczyc): ";
        std::cin >> opcja;
    }

    std::map<std::string, std::vector<double>> mapaCen = generujMapeCen(produkty);
    std::cout << "\nmapa cen:\n";
    for (const auto& [nazwa, ceny] : mapaCen) {
        std::cout << nazwa << ":\n";
        for (const auto& cena : ceny) {
            std::cout << cena << " zł\n";
        }
    }

    return 0;
}
