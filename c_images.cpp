// the method "read_image_file" is designed to read values from an image file into a matrix,
// representing every pixel in a cell of the matrix.
//
// the method "substitute_pixels_with_pixel_blocks" is designed to translate every pixel of the original
// image into a matrix double the size of the original one, each pixel representing a block of four cells in the
// new matrix_of_pixel_blocks. The original value of te pixel being '0' (or white), is represented
// by block A (with (1 0) in the first row of the block and (0 1) in the second row), be it '1' (or black),
// the pixel is represented by block B (consisting of a 2 by 2 matrix with (0 1) as the first row, and (1 0)
// as the second). It also writes the thereby created 2D array containing the blocks A or B into another file.
//
//
// The method get_block_from_pixel takes two integers as arguments when called, each one as a
// coordinate of a pixel in an image. When called, it lets the user know by which block the
// respective pixel is represented in the matrix_of_pixel_blocks and writes it to the screen.
//
// Created by Mascha.
//

#include "c_images.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

c_images::c_images() {
    //constructor
}

c_images::~c_images() {
    //deconstructor
}

void c_images::read_image_file(const char* image_file){
        // a method to read an image from a file as a 2D array. every item in the matrix is of type character.
        int x, y;
        ifstream file;
        file.open(image_file);
        if (!file) {
            cout << "Cannot open file.\n";
        }
        for (y = 0; y < 88; y++) {
            for (x = 0; x < 303; x++) {
                file >> matrix[x][y];
            }
        }
    }

    /* This method translates every item of a 2D array into another one double the size.
     * Every char in the original matrix is represented
     * as a block of four integers after translation into the matrix_of_pixel_blocks,
     * being one of two different choices block A or block B.
     * After translating the matrix into the matrix_of_pixel_blocks, the method writes
     * it to a file.
     * Parameters to call the Method: The name of the .txt file where the matrix_of_pixel_blocks
     * should be written into. */
void c_images::substitute_pixels_with_pixel_blocks(const char* block_image_file) {
    int i, j, k, l;
    for (j = 0; j < 88; j++) {
        for (i = 0; i < 303; i++) {
            if (matrix[i][j] == '0') {
                // this is the actual translation of a one-pixel-value into block A:
                matrix_of_pixel_blocks[i * 2][j * 2] = 1;
                matrix_of_pixel_blocks[i * 2][(j * 2) + 1] = 0;
                matrix_of_pixel_blocks[(i * 2) + 1][j * 2] = 0;
                matrix_of_pixel_blocks[(i * 2) + 1][(j * 2) + 1] = 1;

            } else {
                // this is the actual translation of a one-pixel-value into block B:
                matrix_of_pixel_blocks[i * 2][j * 2] = 0;
                matrix_of_pixel_blocks[i * 2][(j * 2) + 1] = 1;
                matrix_of_pixel_blocks[(i * 2) + 1][j * 2] = 1;
                matrix_of_pixel_blocks[(i * 2) + 1][(j * 2) + 1] = 0;
            }
        }
    }
    ofstream file;
    file.open(block_image_file);
    for (l = 0; l < 2*88; l++) {      //writes the new blocky image to a file
        for (k = 0; k < 2 * 303; k++) {
            file << matrix_of_pixel_blocks[k][l];
            if ((k + 1) % (2 * 303) == 0) {
                file << endl;
            }
        }
    }
    file.close();

}
    /* This method is designed to get the kind of block created from the original pixel at a coordinate.
     * arguments are two integers row and column to define which pixel is of interest. It then prints the
     * result to the screen. */
void c_images::get_block_from_pixel(int column, int row){
    column--; row--;
    if (matrix_of_pixel_blocks[row*2][column * 2] == 1 &&
        matrix_of_pixel_blocks[row * 2][(column * 2) + 1] == 0 &&
        matrix_of_pixel_blocks[(row * 2) + 1][column * 2] == 0 &&
        matrix_of_pixel_blocks[(row * 2) + 1][(column * 2) + 1] == 1) {
        cout << "pixel represented as a block in encrypted image: Block A. " << endl;
        cout << matrix_of_pixel_blocks[row*2][column * 2];
        cout << matrix_of_pixel_blocks[row * 2][(column * 2) + 1] << endl;
        cout << matrix_of_pixel_blocks[(row * 2) + 1][column * 2];
        cout << matrix_of_pixel_blocks[(row * 2) + 1][(column * 2) + 1] << endl;

    } else if (matrix_of_pixel_blocks[row * 2][column * 2] == 0 &&
               matrix_of_pixel_blocks[row * 2][(column * 2) + 1] == 1 &&
               matrix_of_pixel_blocks[(row * 2) + 1][column * 2] == 1 &&
               matrix_of_pixel_blocks[(row * 2) + 1][(column * 2) + 1] == 0) {
        cout << "pixel represented as a block in encrypted image: Block B. " << endl;
        cout << matrix_of_pixel_blocks[row*2][column * 2];
        cout << matrix_of_pixel_blocks[row * 2][(column * 2) + 1] << endl;
        cout << matrix_of_pixel_blocks[(row * 2) + 1][column * 2];
        cout << matrix_of_pixel_blocks[(row * 2) + 1][(column * 2) + 1] << endl;
    }

};


