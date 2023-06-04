//
// Created by 239371 on 31/05/2023.
//

#include "reinsertion.h"

std::vector<int> reinsertion::solution(std::vector<int> &s, int i, int j) {
    int city = s[i];
    s.erase(s.begin() + i);
    s.insert(s.begin() + j, city);
    return s;
}

std::vector<int> reinsertion::solution_from_index(std::vector<int> &s, int index) {
    int i, j;
    if (index <= s.size() - 2) {
        i = 0;
        j = index + 1;
    }
    else {
        i = (index - 1) / (s.size() - 2);
        j = (index - 1) % (s.size() - 2);
        if (j >= i - 1) {
            j = j + 2;
        }
    }
    return solution(s, i, j);
}