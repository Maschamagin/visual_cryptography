//
// Created by Mascha
//

#ifndef VISUAL_CRYPTOGRAPHY_C_IMAGES_H
#define VISUAL_CRYPTOGRAPHY_C_IMAGES_H

class c_images {
public:
    c_images();
    virtual ~c_images();
    void read_image_file(const char* image_file);
    void substitute_pixels_with_pixel_blocks(const char* block_image_file);
    void get_block_from_pixel(int row, int column);

private:
    int matrix_of_pixel_blocks[2*304][2*88];
    char matrix[304][88];
};


#endif //VISUAL_CRYPTOGRAPHY_C_IMAGES_H
