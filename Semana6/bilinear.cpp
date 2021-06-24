//linear.cpp - grad2020
#include <cekeikon.h>

int main(int argc,char** argv){
    if(argc!=5){
        printf("linear: Muda resolucao de imagem usando interpolacao bilinear.\n");
        printf("linear ent.pgm sai.pgm nl nc\n");
        erro("Erro: Numero de argumentos invalido");
    }  
    
    Mat_<GRY> a; le(a,argv[1]);
    int nl,nc;
    if(sscanf(argv[3],"%d",&nl)!=1) erro("Erro: Leitura nl");
    if(sscanf(argv[4],"%d",&nc)!=1) erro("Erro: Leitura nc");
    
    Mat_<GRY> b(nl,nc);
    for(int l=0; l<b.rows; l++)
        for(int c=0; c<b.cols; c++){
            double ald = l *((a.rows-1.0)/(b.rows-1.0));
            double acd = c *((a.cols-1.0)/(b.cols-1.0));
            int fal=int(ald);int fac=int(acd);
            double dl=ald-fal;
            double dc=acd-fac;
            double p1=(1-dl)*(1-dc);
            double p2=(1-dl)*dc;
            double p3=dl*(1-dc);
            double p4=dl*dc;
            b(l,c)= cvRound(
                                p1*a(fal,fac)+ p2*a(fal,fac+1)+
                                p3*a(fal+1,fac)+ p4*a(fal+1,fac+1));
                }  
    imp(b,argv[2]);
}