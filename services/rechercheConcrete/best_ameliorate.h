//
// Created by 239371 on 04/06/2023.
//

#ifndef CHALLENGE_TSP_BEST_AMELIORATE_H
#define CHALLENGE_TSP_BEST_AMELIORATE_H

#include "../typeRecherche.h"
#include "../SolutionConcrete/twoOpt.h"


class best_ameliorate: public typeRecherche {

public:
    std::vector<int> recherche(std::vector<int> &solution, std::vector<int> &neighbor, const std::vector<City> &cities, typeSolution &typeSolution) override;
};


#endif //CHALLENGE_TSP_BEST_AMELIORATE_H
