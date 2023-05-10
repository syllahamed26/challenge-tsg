//
// Created by Hamed Cédric Sylla on 14/02/2023.
//

#include <fstream>
#include <iostream>
#include <vector>
#include "../model/City.h"

using namespace std;

class FileLManagement {
public:
    void writeToFile(string fileName, string content) {
        ofstream file;
        file.open(fileName);
        file << content;
        file.close();
    }

    static std::vector<City> read_file_to_vector(const std::string &nom_fichier) {
        std::vector<City> cities;
        std::ifstream fichier("../resources/" + nom_fichier);
        if (!fichier) {
            std::cerr << "Impossible d'ouvrir le fichier " << nom_fichier << std::endl;
            return cities;
        }
        int n;
        fichier >> n;
        for (int i = 0; i < n; ++i) {
            std::string nom;
            double latitude, longitude;
            fichier >> nom >> latitude >> longitude;
            cities.emplace_back(nom, latitude, longitude);
        }
        return cities;
    }

};