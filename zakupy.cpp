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
    auto mapaCen = generujMapeCen(produkty);

    wyswietlProdukty(produkty);
    
    int opcja;
    std::cout << "0: wyjscie z programu\n1: informacje o produkcie\n2:informacja o cenach\n";
    std::cin >> opcja;
    while(opcja != 0) {
    switch(opcja) {
        case 1:
        {
            std::cout << "\nwpisz numer produktu aby zobaczyc informacje: ";
            int nr;
            std::cin>>nr;
            if (nr > 0 && nr <= static_cast<int>(produkty.size())) {
            wyswietlInfoOProdukcie(produkty[nr - 1]);}
                else{
                    std::cout << "nieprawidlowa opcja\n";
                }
            break;
        }
        case 2: 
        {
            std::string nazwaProd;
            std::cout << "\nwpisz nazwe produktu aby zobaczyc informacje o jego cenach: ";
            std::cin >> nazwaProd;
            auto ceny = mapaCen[nazwaProd];
            if(ceny.empty()){
                std::cout << "\nnie znaleziono produktu\n";
            } else{
            for(auto cena : ceny){
                std::cout << cena << "\n";
            }}
            break;
        }
        default: {
            std::cout << "nieprawidlowa opcja\n";
            break;
        }
        }
            std::cout << "0: wyjscie z programu\n1: informacje o produkcie\n2:informacja o cenach\n";
        std::cin >> opcja;   
    }

    return 0;
}
