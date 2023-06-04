//
// Created by 239371 on 31/05/2023.
//

#ifndef CHALLENGE_TSP_TWOOPT_H
#define CHALLENGE_TSP_TWOOPT_H

#include "../typeSolution.h"

class twoOpt: public typeSolution {

    std::vector<int> solution_from_index(std::vector<int> &s, int index) override;

    std::vector<int> solution(std::vector<int> &s, int i, int j) override;
};


#endif //CHALLENGE_TSP_TWOOPT_H
