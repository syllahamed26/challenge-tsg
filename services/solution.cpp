//
// Created by Hamed Cédric Sylla on 14/02/2023.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include "../model/City.h"

using namespace std;

class Solution {
private:
    const double PI = 3.141592;
    const double R_TERRE = 6378.137;
public:

    double evaluate(const std::vector<City>& cities, const std::vector<int>& ordre_livraison)
    {
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

    std::vector<int> generate_random(int n)
    {
        std::vector<int> solution(n);
        for(int i = 0; i < n; ++i) {
            solution[i] = i;
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(solution.begin(), solution.end(), g);
        return solution;
    }

    double distance_between_villes(const City& ville1, const City& ville2) {
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

    std::vector<int> generate_greedy(const std::vector<City>& cities) {
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


    std::vector<int> permutation(const std::vector<int>& s, int i, int j) {
        std::vector<int> s_prime = s;
        int temp = s_prime[i];
        s_prime[i] = s_prime[j];
        s_prime[j] = temp;
        return s_prime;
    }

    std::vector<int> permutation_from_index(const std::vector<int>& s, int index){
        int n = (1 + sqrt(1 + 8 * index)) / 2;
        int i = index - (n * (n - 1)) / 2;
        int j = s.size() - n + i;
        return permutation(s, i, j);
    }

    int number_of_neighbors(int n) {
        return (n * (n - 1)) / 2;
    }

    vector<int> reinsertion(vector<int> solution, int i, int j) {
        int city = solution[i];
        solution.erase(solution.begin() + i);
        solution.insert(solution.begin() + j, city);
        return solution;
    }

    vector<int> reinsertion_from_index(vector<int> s, int index) {
        int i, j;
        if (index <= s.size() - 2) {
            i = 0;
            j = index + 1;
        }
        else {
            i = (index - 1) / (s.size() - 2);
            j = (index - 1) % (s.size() - 2);
            if (j >= i - 1) {
                j = j + 2;
            }
        }
        return reinsertion(s, i, j);
    }

    std::vector<int> find_best_solution(const std::vector<City>& cities, const std::vector<int>& initial_solution, int max_iterations) {
        std::vector<int> best_solution = initial_solution;
        double best_score = evaluate(cities,initial_solution);
        int iteration = 0;

        while (iteration < max_iterations) {
            std::vector<int> current_solution = generate_neighbor_solution(best_solution);
            double current_score = evaluate(cities, current_solution);

            if (current_score < best_score) {
                best_solution = current_solution;
                best_score = current_score;
            }

            iteration++;
        }

        return best_solution;
    }

    std::vector<int> generate_neighbor_solution(const std::vector<int>& solution) {
        int n = solution.size();
        int index = rand() % number_of_neighbors(n);
        return permutation_from_index(solution, index);
    }

    // question 6.1
    std::vector<int> two_opt(std::vector<int>&solution, int i, int j) {
        std::reverse(solution.begin() + i, solution.begin() + j + 1);
        return solution;
    }

    // question 6.2
    std::vector<int> two_opt_from_index(std::vector<int> &s, int index) {
        int n = (1 + sqrt(1 + 8 * index)) /2;
        int i = index - (n * (n-1)) /2;
        int j = n - 1;
        return two_opt(s,i,j);
    }

    // question 7.1
    std::vector<int> best_ameliorate(std::vector<int>&solution, std::vector<int>& neighbor, const std::vector<City>& cities){
        std::vector<int> best_solution = solution;
        double best_score = evaluate(cities,solution);
        for(int i = 0; i < number_of_neighbors(solution.size()); i++){
            std::vector<int> current_solution = two_opt_from_index(solution,i);
            double current_score = evaluate(cities,current_solution);
            if(current_score < best_score){
                best_solution = current_solution;}
        }

        return best_solution;
    }

    // question 7.2
    std::vector<int> algorithme_descente(std::vector<int> &s, std::vector<int> &v, std::vector<City> &cities) {
        std::vector<int> solution = s;
        double distance_solution = evaluate(cities, v);
        double meilleur_distance = 0;
        std::vector<int> meilleur_solution;
        while(meilleur_distance > distance_solution){
            meilleur_solution = solution;
            meilleur_distance = distance_solution;
            solution = best_ameliorate(solution, v, cities);
            distance_solution = evaluate(cities, solution);
        }
        return meilleur_solution;
    }
};