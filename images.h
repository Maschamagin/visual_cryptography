//
// Created by Mascha on 25.10.18.
//

#ifndef VISUAL_CRYPTOGRAPHY_IMAGES_H
#define VISUAL_CRYPTOGRAPHY_IMAGES_H


class images {
public:
    images();
    ~images();
    void read_image();
    char operator()(int row, int column, char new_value);
    char operator()(int row, int column) const;



private:
    char matrix [304][88];
};



#endif //VISUAL_CRYPTOGRAPHY_IMAGES_H
