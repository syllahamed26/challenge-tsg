//
// Created by 239371 on 04/06/2023.
//

#include "score.h"
#include <cmath>
#include <vector>

double Score::evaluate(const std::vector<City>& cities, const std::vector<int>& ordre_livraison) {
    const double Rterre = 6378.137; // rayon de la Terre en km

    double distance_totale = 0.0;

    // Calcul de la distance entre chaque paire de villes consécutives
    for (int i = 0; i < ordre_livraison.size() - 1; i++) {
        const int city_start = ordre_livraison[i];
        const int city_end = ordre_livraison[i+1];

        const double latA = cities[city_start].getLatitude() * M_PI / 180.0; // conversion en radians
        const double longA = cities[city_start].getLongitude() * M_PI / 180.0;
        const double latB = cities[city_end].getLatitude() * M_PI / 180.0;
        const double longB = cities[city_end].getLongitude() * M_PI / 180.0;

        const double distance_AB = Rterre * std::acos(std::sin(latA) * std::sin(latB) + std::cos(latA) * std::cos(latB) * std::cos(longB - longA));
        distance_totale += distance_AB;
    }

    // Ajout de la distance entre le dernier point de livraison et le point de départ
    const int city_start = ordre_livraison.back();
    const int city_end = ordre_livraison.front();

    const double latA = cities[city_start].getLatitude() * M_PI / 180.0;
    const double longA = cities[city_start].getLongitude() * M_PI / 180.0;
    const double latB = cities[city_end].getLatitude() * M_PI / 180.0;
    const double longB = cities[city_end].getLongitude() * M_PI / 180.0;

    const double distance_AB = Rterre * std::acos(std::sin(latA) * std::sin(latB) + std::cos(latA) * std::cos(latB) * std::cos(longB - longA));
    distance_totale += distance_AB;

    return distance_totale;
}

int number_of_neighbors(int n) {
    return (n * (n - 1)) / 2;
}