//
// Created by 239371 on 04/06/2023.
//

#ifndef CHALLENGE_TSP_SCORE_H
#define CHALLENGE_TSP_SCORE_H

#include <vector>
#include "../model/City.h"


class Score {
public:
    double evaluate(const std::vector<City>& cities, const std::vector<int>& ordre_livraison);
    int number_of_neighbors(int n);
};


#endif //CHALLENGE_TSP_SCORE_H
