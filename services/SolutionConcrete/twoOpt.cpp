//
// Created by 239371 on 31/05/2023.
//

#include "twoOpt.h"
#include <cmath>
#include <algorithm>

std::vector<int> twoOpt::solution(std::vector<int> &s, int i, int j) {
    std::reverse(s.begin() + i, s.begin() + j + 1);
    return s;
}

std::vector<int> twoOpt::solution_from_index(std::vector<int> &s, int index) {
    int n = (1 + sqrt(1 + 8 * index)) /2;
    int i = index - (n * (n-1)) /2;
    int j = n - 1;
    return solution(s,i,j);
}