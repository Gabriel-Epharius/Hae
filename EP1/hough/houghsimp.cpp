//houghsimp.cpp - pos2017
#include <cekeikon.h>

int main() {
    
    ImgXyb<GRY> ent; 
    le(ent,"1pto.bmp");
    ent.centro(ent.rows/2,ent.cols/2); 
    int nl2=teto( sqrt(50*50+50*50) );

    int nl=2*nl2+1;
    int nc2=90;
    int nc=2*nc2+1;
    ImgXyb<FLT> sai(nl,nc, 1.0);
    sai.centro(nl2,nc2);

    int n = 0;
    
    for (int xa=ent.minx; xa<=ent.maxx; xa++) {
        for (int ya=ent.miny; ya<=ent.maxy; ya++) {
            if (ent(xa,ya)==0) {
                for (int theta=-90; theta<=+90; theta++) {
                    double rad=deg2rad(theta);
                    int rho=cvRound((xa*cos(rad)+ya*sin(rad)));
                    sai(theta,rho) -= 1;
                }   
            }
        }


    sai=normaliza(sai);

    imp(sai,"1pt_saida_normalizado.png");

    }
}
