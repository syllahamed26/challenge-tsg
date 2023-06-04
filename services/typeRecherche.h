//
// Created by 239371 on 31/05/2023.
//

#ifndef CHALLENGE_TSP_TYPERECHERCHE_H
#define CHALLENGE_TSP_TYPERECHERCHE_H

#include <vector>
#include "../model/City.h"
#include <cmath>
#include <algorithm>
#include <random>
#include "score.h"
#include "typeSolution.h"


class typeRecherche {

public:
    virtual std::vector<int> recherche(std::vector<int>& solution, std::vector<int>& neighbor, const std::vector<City>& cities, typeSolution &typeSolution) = 0;
    std::vector<int> recherche_locale_voisinage_variable(const std::vector<City>& cities, std::vector<int> &s, std::vector<int> &neighbor, typeSolution &typeSolution);
    std::vector<int> perturber_solution(const std::vector<int>& solution, int forcer);
    std::vector<int> recherche_locale_itere(const std::vector<City>& cities, const std::vector<int>& s, std::vector<int>& voisinage, int critere_arret, typeSolution &typeSolution);
};


#endif //CHALLENGE_TSP_TYPERECHERCHE_H
