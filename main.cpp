#include <iostream>
#include "model/City.h"
#include "vector"
#include "services/FileManagement.cpp"
#include "services/solution.cpp"

using namespace std;

int main() {
    std::vector<City> cities = FileLManagement::read_file_to_vector("france_500.tsp");
    //Print cities
    cout << "Number of cities: " << cities.size() << endl;
    for (int i = 0; i < cities.size(); ++i) {
        cout << cities[i].getName() << " " << cities[i].getLatitude() << " " << cities[i].getLongitude() << " / ";
    }
    cout << endl << endl;

    //Solution greedy and evaluation
    std::vector<int> solution_greeedy = Solution().generate_greedy(cities);
    double evaluation_of_greedy = Solution().evaluate(cities, solution_greeedy);
    //Print greedy solution
    for (int i = 0; i < solution_greeedy.size(); ++i) {
        cout << solution_greeedy[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of greedy solution: " << evaluation_of_greedy << endl;

    //Permutation
    std::vector<int> permutation = Solution().permutation(solution_greeedy, 1, 2);
    //Print permutation
    for (int i = 0; i < permutation.size(); ++i) {
        cout << permutation[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of permutation solution: " << Solution().evaluate(cities, permutation) << endl;

    //Permutation par index
    std::vector<int> permutation_by_index = Solution().permutation_from_index(solution_greeedy, 1);
    //Print permutation
    for (int i = 0; i < permutation_by_index.size(); ++i) {
        cout << permutation_by_index[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of permutation solution: " << Solution().evaluate(cities, permutation_by_index) << endl;

    //Question 4.3 Combien de solutions voisines possibles pour l’échange ?
    cout << "Number of neighbors: " << Solution().number_of_neighbors(solution_greeedy.size()) << endl;

    //Reinsertion
    std::vector<int> reinsertion = Solution().reinsertion(solution_greeedy, 1, 2);
    //Print reinsertion
    for (int i = 0; i < reinsertion.size(); ++i) {
        cout << reinsertion[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of reinsertion solution: " << Solution().evaluate(cities, reinsertion) << endl;

    //Reinsertion par index
    std::vector<int> reinsertion_by_index = Solution().reinsertion_from_index(solution_greeedy, 1);
    //Print reinsertion
    for (int i = 0; i < reinsertion_by_index.size(); ++i) {
        cout << reinsertion_by_index[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of reinsertion solution: " << Solution().evaluate(cities, reinsertion_by_index) << endl;

    //Question 5.3 Combien de solutions voisines possibles pour la ré-insertion ?
    cout << "Number of neighbors for reinsertion from index: " << solution_greeedy.size() - 1 << endl;

    //Question 6.1
    std::vector<int> solution_two_opt = Solution().two_opt(solution_greeedy, 1, 2);
    //Print two_opt
    for (int i = 0; i < solution_two_opt.size(); ++i) {
        cout << solution_two_opt[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of two_opt solution: " << Solution().evaluate(cities, solution_two_opt) << endl;

    //Question 6.2
    std::vector<int> solution_two_opt_by_index = Solution().two_opt_from_index(solution_greeedy, 1);
    //Print two_opt_by_index
    for (int i = 0; i < solution_two_opt_by_index.size(); ++i) {
        cout << solution_two_opt_by_index[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of two_opt solution: " << Solution().evaluate(cities, solution_two_opt_by_index) << endl;

    //Question 7.1
    std::vector<int> solution_best_ameliorate = Solution().best_ameliorate(solution_greeedy, solution_two_opt_by_index, cities);
    //Print best_ameliorate
    for (int i = 0; i < solution_best_ameliorate.size(); ++i) {
        cout << solution_best_ameliorate[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of best_ameliorate solution: " << Solution().evaluate(cities, solution_best_ameliorate) << endl;

    //Question 7.2
    std::vector<int> solution_algorithme_descente = Solution().algorithme_descente(solution_greeedy, solution_two_opt_by_index, cities);
    //Print best_ameliorate
    for (int i = 0; i < solution_algorithme_descente.size(); ++i) {
        cout << solution_algorithme_descente[i] << " ";
    }
    cout << endl;
    cout << "Evaluation of best_ameliorate solution: " << Solution().evaluate(cities, solution_algorithme_descente) << endl;

    return 0;
}
