//
// Created by 239371 on 31/05/2023.
//

#include "permutation.h"
#include <cmath>

std::vector<int> permutation::solution(std::vector<int> &s, int i, int j) {
    std::vector<int> s_prime = s;
    int temp = s_prime[i];
    s_prime[i] = s_prime[j];
    s_prime[j] = temp;
    return s_prime;
}

std::vector<int> permutation::solution_from_index(std::vector<int> &s, int index) {
    int n = (1 + sqrt(1 + 8 * index)) / 2;
    int i = index - (n * (n - 1)) / 2;
    int j = s.size() - n + i;
    return solution(s, i, j);
}