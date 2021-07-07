#include <cekeikon.h>

int main(){

    Mat_<COR> mapa;
    le(mapa, "julho.pgm");

    Mat_<GRY> area;
    le(area, "julho_final.pgm");

    for(int i=0; i< mapa.rows; i++)
        for(int j=0; j< mapa.cols;j++){
            if(area[i][j] == 0.0){
                mapa[i][j][2] = 255.0;
            }
        }
    
    imp(mapa, "mapa.pgm");


}