#include <iostream>
#include "model/City.h"
#include "services/FileManagement.cpp"
#include "services/solution.cpp"
#include "services/score.cpp"
#include "services/SolutionConcrete/permutation.cpp"
#include "services/SolutionConcrete/reinsertion.cpp"
#include "services/SolutionConcrete/twoOpt.cpp"
#include "services/rechercheConcrete/best_ameliorate.cpp"
#include "services/rechercheConcrete/first_ameliorate.cpp"
#include "services/rechercheConcrete/algorithme_descente.cpp"

using namespace std;

int main() {
    Score score = *new Score();
    std::vector<City> cities = FileLManagement::read_file_to_vector("france_500.tsp");
    //Print cities
    cout << "Number of cities: " << cities.size() << endl;
    for (const auto & citie : cities) {
        cout << citie.getName() << " " << citie.getLatitude() << " " << citie.getLongitude() << " / ";
    }
    cout << endl << endl;

    //Solution greedy and evaluation
    std::vector<int> solution_greeedy = Solution().generate_greedy(cities);
    double evaluation_of_greedy = score.evaluate(cities, solution_greeedy);
    //Print greedy solution
    for (int i : solution_greeedy) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Evaluation of greedy solution: " << evaluation_of_greedy << endl;

    //Permutation
    permutation permutation;
    std::vector<int> permutationImp = permutation.solution(solution_greeedy, 1, 2);
    //Print permutation
    for (int i : permutationImp) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Evaluation of permutation solution: " << score.evaluate(cities, permutationImp) << endl;

    //Permutation par index
    std::vector<int> permutation_by_index = permutation.solution_from_index(solution_greeedy, 1);
    //Print permutation
    for (int i : permutation_by_index) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Evaluation of permutation solution: " << score.evaluate(cities, permutation_by_index) << endl;

    //Question 4.3 Combien de solutions voisines possibles pour l’échange ?
    cout << "Number of neighbors: " << score.number_of_neighbors(solution_greeedy.size()) << endl;

    //Reinsertion
    reinsertion reinsertion;
    std::vector<int> reinsertionImp = reinsertion.solution(solution_greeedy, 1, 2);
    //Print reinsertion
    for (int i : reinsertionImp) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Evaluation of reinsertion solution: " << score.evaluate(cities, reinsertionImp) << endl;

    //Reinsertion par index
    std::vector<int> reinsertion_by_index = reinsertion.solution_from_index(solution_greeedy, 1);
    //Print reinsertion
    for (int i : reinsertion_by_index) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Evaluation of reinsertion solution: " << score.evaluate(cities, reinsertion_by_index) << endl;

    //Question 5.3 Combien de solutions voisines possibles pour la ré-insertion ?
    cout << "Number of neighbors for reinsertion from index: " << score.number_of_neighbors(reinsertion_by_index.size()) << endl;

    //Question 6.1
    twoOpt twoOpt;
    std::vector<int> solution_two_opt = twoOpt.solution(solution_greeedy, 1, 2);
    //Print two_opt
    for (int i : solution_two_opt) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Evaluation of two_opt solution: " << score.evaluate(cities, solution_two_opt) << endl;

    //Question 6.2
    std::vector<int> solution_two_opt_by_index = twoOpt.solution_from_index(solution_greeedy, 1);
    //Print two_opt_by_index
    for (int i : solution_two_opt_by_index) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Evaluation of two_opt solution: " << score.evaluate(cities, solution_two_opt_by_index) << endl;

    //Question 7.1
    std::vector<int> solution_best_ameliorate = best_ameliorate().recherche(solution_greeedy, solution_two_opt_by_index, cities, twoOpt);
    //Print best_ameliorate
    for (int i = 0; i < solution_best_ameliorate.size(); ++i) {
        cout << solution_best_ameliorate[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of best_ameliorate solution: " << score.evaluate(cities, solution_best_ameliorate) << endl;

    //Question 7.2
    std::vector<int> solution_algorithme_descente = algorithme_descente().recherche(solution_greeedy, solution_two_opt_by_index, cities, twoOpt);
    //Print best_ameliorate
    for (int i = 0; i < solution_algorithme_descente.size(); ++i) {
        cout << solution_algorithme_descente[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of best_ameliorate solution: " << score.evaluate(cities, solution_algorithme_descente) << endl;

    //voisin de solution_algorithme_descente
    //recherche locale itere
    std::vector<int> solution_recherche_locale_itere = twoOpt.recherche_locale_itere(cities, solution_greeedy,solution_best_ameliorate, 10000);
    //Print best_ameliorate
    for (int i : solution_recherche_locale_itere) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Evaluation of best_ameliorate solution: " << score.evaluate(cities, solution_recherche_locale_itere) << endl;

    return 0;
}
