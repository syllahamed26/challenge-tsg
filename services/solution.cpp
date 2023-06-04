//
// Created by Hamed Cédric Sylla on 14/02/2023.
//

#include <vector>
#include <cmath>
#include "../model/City.h"
#include "solution.h"

using namespace std;

double Solution::distance_between_villes(const City& ville1, const City& ville2) {
    const double PI = 3.141592;
    const double R_TERRE = 6378.137;

    double lat1 = ville1.getLatitude() * PI / 180.0;
    double long1 = ville1.getLongitude() * PI / 180.0;
    double lat2 = ville2.getLatitude() * PI / 180.0;
    double long2 = ville2.getLongitude() * PI / 180.0;

    double sin_lat1 = sin(lat1);
    double sin_lat2 = sin(lat2);
    double cos_lat1 = cos(lat1);
    double cos_lat2 = cos(lat2);
    double cos_delta_long = cos(long2 - long1);

    double arc_cos_arg = sin_lat1 * sin_lat2 + cos_lat1 * cos_lat2 * cos_delta_long;

    double distance = R_TERRE * acos(arc_cos_arg);

    return distance;
}

std::vector<int> Solution::generate_greedy(const std::vector<City>& cities) {
    int n = cities.size();
    std::vector<int> solution(n);

    // Initialise la liste des villes visitées et de la solution
    std::vector<bool> visited(n, false);
    visited[0] = true; // On commence à la première ville
    solution[0] = 0;

    // Pour chaque étape, on choisit la ville la plus proche parmi les villes non visitées
    for (int i = 1; i < n; i++) {
        int last_city = solution[i - 1];
        double min_distance = std::numeric_limits<double>::max();
        int closest_city = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                double distance = distance_between_villes(cities[last_city], cities[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_city = j;
                }
            }
        }
        solution[i] = closest_city;
        visited[closest_city] = true;
    }

    return solution;
}

