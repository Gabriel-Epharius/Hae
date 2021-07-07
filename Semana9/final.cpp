//Flann.cpp com 4 arvores - pos2020
//Linkar com OpenCV2 ou OpenCV3

#include <cekeikon.h>


Mat translateImg(Mat &img, int offsetx, int offsety){
    Mat transmat = (Mat<double>(2,3) << 1, 0, offsetx, 0, 1, offsety);
    warpAffine(img,img,trans_mat,img.size());
    return img;
}


int main() {
    Mat_<GRY> a;
    le(a, "mickey.bmp");

        //b = translateImg(a, 1, 1);

}


