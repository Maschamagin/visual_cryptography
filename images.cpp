//
// Created by Mascha on 25.10.18.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "images.h"
using namespace std;

images::images(){
    // constructor for the class "images"
};

char images::read_image() {
    int x, y;
    ifstream file;
    file.open("beispielbild_1.txt");
    if (!file) {
            cout << "Cannot open file.\n";
        }
    for (y = 0; y < 89; y++) {
        for (x = 0; x < 303; x++) {
            file >> matrix[x][y];
            cout << matrix[x][y];
                    }
                    cout << endl;

    }
    file.close();
    return matrix[x][y];
    }
;
// to do: auf Koordinaten zugreifen und im file verändern


