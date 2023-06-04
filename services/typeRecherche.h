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


class typeRecherche {

public:
    virtual std::vector<int> recherche(std::vector<int>& solution, std::vector<int>& neighbor, const std::vector<City>& cities) = 0;
};


#endif //CHALLENGE_TSP_TYPERECHERCHE_H
