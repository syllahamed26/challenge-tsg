//
// Created by 239371 on 04/06/2023.
//

#ifndef CHALLENGE_TSP_SOLUTION_H
#define CHALLENGE_TSP_SOLUTION_H

#include <vector>
#include "../model/City.h"

class Solution {
public:
    std::vector<int> generate_greedy(const std::vector<City>& cities);
    double distance_between_villes(const City& city1, const City& city2);
};

#endif //CHALLENGE_TSP_SOLUTION_H
