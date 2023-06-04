//
// Created by 239371 on 31/05/2023.
//

#ifndef CHALLENGE_TSP_TYPESOLUTION_H
#define CHALLENGE_TSP_TYPESOLUTION_H

#include <vector>


class typeSolution {

public:
    virtual std::vector<int> solution_from_index(std::vector<int> &s, int index) = 0;
    virtual std::vector<int> solution(std::vector<int> &s, int i, int j) = 0;

};


#endif //CHALLENGE_TSP_TYPESOLUTION_H
