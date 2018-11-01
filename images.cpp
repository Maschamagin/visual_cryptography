// This is the implementation of a class to read an "image" (a matrix containing only 0 and 1
// assembling to an image) from a file in the method "read image", 
// to access and change any coordinate provided as parameters and rewrites it in the original image file
// in the method "operator()"
// and to read any coordinate from the image, provided as parameters to the method "operator() const".
// Class created by Mascha.

#include <iostream>
#include <fstream>
#include <string>
#include "images.h"
using namespace std;

images::images(){
    // constructor for the class "images"
};

images::~images(){
    // deconstructor for the class "images"
};


void images::read_image() {
    //a method to read an image from a file as a matrix
    int x, y;
    ifstream file;
    file.open("beispielbild_1.txt");
    if (!file) {
        cout << "Cannot open file.\n";
    }
    for (y = 0; y < 89; y++) {
        for (x = 0; x < 303; x++) {
            file >> matrix[x][y];
            if (matrix[x][y] != '0' && matrix[x][y] != '1') {
                //checks if image contains only of two kinds of characters or colors
                cout << "Not a black and white image" << endl;
            }
        }
    }
}

char images::operator()(int row, int column, char new_value){
    //a method that accesses and changes the images' coordinates
    cout << "new value at row " << row << endl;
    cout << "and column " << column << ": " << endl;
    matrix[column-1][row-1] = new_value;   //sets the new value
    cout << matrix[column-1][row-1] << endl;
    int x,y;
    ofstream file;
    file.open("beispielbild_1.txt");
    for (y = 0; y < 89; y++) {      //writes the new whole image to the original file
        for (x = 0; x < 303; x++) {
            file << matrix[x][y];
            if ((x + 1) % 303 == 0) {
                file << endl;}
        }
    }
    file.close();
    return matrix[column - 1][row - 1];

}

char images::operator()(int row, int column) const {
    //a method to access and read a coordinate's value
    cout << "value at row " << row << endl;
    cout << "and column " << column << ": " << endl;
    cout << matrix[column-1][row-1] << endl;
    return matrix[column-1][row-1];
};
