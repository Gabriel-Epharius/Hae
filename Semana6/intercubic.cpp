//cvvizinho.cpp pos2018 - usa funcao resize do OpenCV
#include <cekeikon.h>

int main(int argc,char** argv){
    if(argc!=4){
        printf("cvvizinho ent.pgm sai.pgm fator\n");
        erro("Erro: Numero de argumentos invalido");
    }  
    
    Mat_<GRY> a;
    le(a,argv[1]);
    double fator;
    sscanf(argv[3],"%lf",&fator);
    Mat_<GRY> b;
    resize(a, b, Size(0,0), fator, fator, INTER_CUBIC);

    imp(b,argv[2]); 
}