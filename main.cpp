#include <iostream>
#include <fstream>
#include <string>
#include "images.h"
#include "c_images.h"
#include <iostream>
using namespace std;

int main()
    {
    int row;
    int column;
    char new_value;
    cout << "type in which coordinate you would like to acces(row, column): " << endl;
    cin >> row >> column;

    images test;
    test.read_image();
    test.operator()(row, column);
    cout << "what should be the new value for the coordinate? " << endl;
    cout << "please choose between 1 and 0. " << endl;
    cin >> new_value;
    test.operator()(row, column, new_value);

    c_images object;
    object.read_image_file("beispielbild_1.txt");
    object.substitute_pixels_with_pixel_blocks("beispielbild_3.txt");
    object.get_block_from_pixel(row, column);

    return 0;
}