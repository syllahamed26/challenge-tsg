//
// Created by 239371 on 31/05/2023.
//

#ifndef CHALLENGE_TSP_TYPESOLUTION_H
#define CHALLENGE_TSP_TYPESOLUTION_H

#include <vector>
#include "../model/City.h"


class typeSolution {

public:
    virtual std::vector<int> solution_from_index(std::vector<int> &s, int index) = 0;
    virtual std::vector<int> solution(std::vector<int> &s, int i, int j) = 0;
    std::vector<int> recherche_locale_voisinage_variable(const std::vector<City>& cities, std::vector<int> &s, const std::vector<int> &neighbor);
    std::vector<int> perturber_solution(const std::vector<int>& solution, int forcer);
    std::vector<int> recherche_locale_itere(const std::vector<City>& cities, const std::vector<int>& s, const std::vector<int>& voisinage, int critere_arret);

};


#endif //CHALLENGE_TSP_TYPESOLUTION_H
