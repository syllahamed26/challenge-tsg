#include <iostream>
#include "model/City.h"
#include "vector"
#include "services/FileManagement.cpp"
#include "services/solution.cpp"

using namespace std;

int main() {
    std::vector<City> cities = FileLManagement::read_file_to_vector("france_10.tsp");
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


    return 0;
}
