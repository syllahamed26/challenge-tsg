//
// Created by 239371 on 04/06/2023.
//

#ifndef CHALLENGE_TSP_ALGORITHME_DESCENTE_H
#define CHALLENGE_TSP_ALGORITHME_DESCENTE_H

#include "../typeRecherche.h"
#include "best_ameliorate.h"


class algorithme_descente: public typeRecherche {

public:


    std::vector<int> recherche(std::vector<int> &solution, std::vector<int> &neighbor, const std::vector<City> &cities, typeSolution &typeSolution) override;
};


#endif //CHALLENGE_TSP_ALGORITHME_DESCENTE_H
