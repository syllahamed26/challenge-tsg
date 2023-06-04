//
// Created by 239371 on 04/06/2023.
//

#include "algorithme_descente.h"

std::vector<int> recherche(std::vector<int> &solution, std::vector<int> &neighbor, const std::vector<City> &cities) {
    Score score = *new Score();
    std::vector<int> s = solution;
    double distance_solution = score.evaluate(cities, neighbor);
    double meilleur_distance = 0;
    std::vector<int> meilleur_solution;
    while(meilleur_distance > distance_solution){
        meilleur_solution = s;
        meilleur_distance = distance_solution;
        best_ameliorate bestAmeliorate = *new best_ameliorate();
        s = bestAmeliorate.recherche(s, neighbor, cities);
        distance_solution = score.evaluate(cities, s);
    }
    return meilleur_solution;
}