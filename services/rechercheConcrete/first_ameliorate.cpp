//
// Created by 239371 on 04/06/2023.
//

#include "first_ameliorate.h"

std::vector<int> recherche(std::vector<int> &solution, std::vector<int> &neighbor, const std::vector<City> &cities, typeSolution &typeSolution) {
    Score score = *new Score();
    std::vector<int> best_solution = solution;
    double best_score = score.evaluate(cities, solution);
    bool found_improvement = false;

    for(int i = 0; i < score.number_of_neighbors(solution.size()); i++){
        std::vector<int> current_solution = typeSolution.solution_from_index(solution, i);
        double current_score = score.evaluate(cities, current_solution);

        if(current_score < best_score){
            best_solution = current_solution;
            found_improvement = true;
            break;
        }
    }

    if(!found_improvement){
        best_solution = solution;
    }

    return best_solution;
}