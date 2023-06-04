//
// Created by 239371 on 04/06/2023.
//

#ifndef CHALLENGE_TSP_RANDOM_AMELIORATE_H
#define CHALLENGE_TSP_RANDOM_AMELIORATE_H

#include "../typeSolution.h"
#include "../typeRecherche.h"
#include "../SolutionConcrete/twoOpt.h"
#include "../../model/City.h"



class random_ameliorate: public typeRecherche {

public:


    std::vector<int> recherche(std::vector<int> &solution, std::vector<int> &neighbor, const std::vector<City> &cities, typeSolution &typeSolution) override;
    Score score;

};


#endif //CHALLENGE_TSP_RANDOM_AMELIORATE_H
