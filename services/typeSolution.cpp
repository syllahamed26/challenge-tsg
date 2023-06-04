//
// Created by 239371 on 31/05/2023.
//

#include "typeSolution.h"
#include "score.h"
#include "../model/City.h"
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> typeSolution::recherche_locale_voisinage_variable(const std::vector<City>& cities, std::vector<int> &s, const std::vector<int> &neighbor) {
    Score score = *new Score();
    std::vector<int> meilleureSolution = s;
    double meilleureDistance = score.evaluate(cities, s);

    for (int i = 0; i < score.number_of_neighbors(s.size()); i++) {
        std::vector<int> solutionCourante = solution_from_index(s, i);
        double distanceCourante = score.evaluate(cities, solutionCourante);

        // Si la solution courante est meilleure que la meilleure solution, on la remplace
        if (distanceCourante < meilleureDistance) {
            meilleureSolution = solutionCourante;
            meilleureDistance = distanceCourante;
        }
    }

    return meilleureSolution;
}

std::vector<int> typeSolution::perturber_solution(const std::vector<int>& solution, int force) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(0, 1);
    int choixOperateur = distribution(gen);

    std::vector<int> nouvelleSolution = solution;

    for (int i = 0; i < force; i++) {
        if (choixOperateur == 0) {
            std::uniform_int_distribution<int> distributionPos(1, solution.size() - 2);
            int position1 = distributionPos(gen);
            int position2 = distributionPos(gen);

            if (position1 > position2) {
                std::swap(position1, position2);
            }

            int element = nouvelleSolution[position1];

            for (int i = position1; i < position2; i++) {
                nouvelleSolution[i] = nouvelleSolution[i + 1];
            }

            nouvelleSolution[position2] = element;
        }
        else {
            std::uniform_int_distribution<int> distributionPos(1, solution.size() - 2);
            int position1 = distributionPos(gen);
            int position2 = distributionPos(gen);

            if (position1 > position2) {
                std::swap(position1, position2);
            }

            std::reverse(nouvelleSolution.begin() + position1, nouvelleSolution.begin() + position2 + 1);
        }
    }

    return nouvelleSolution;
}

std::vector<int> typeSolution::recherche_locale_itere(const std::vector<City>& cities, const std::vector<int>& s, const std::vector<int>& voisinage, int critere_arret) {
    std::vector<int> solution = s;
    int iterations = 0;

    while (iterations < critere_arret) {
        std::vector<int> meilleureSolution = recherche_locale_voisinage_variable(cities, solution, voisinage);
        std::vector<int> nouvelleSolution = perturber_solution(meilleureSolution, 1);

        // Vérifier si la nouvelle solution est meilleure que la solution actuelle
        if (nouvelleSolution != meilleureSolution) {
            solution = nouvelleSolution;
            iterations = 0; // Réinitialiser le compteur d'itérations
        }
        else {
            iterations++;
        }
    }

    return solution;
}