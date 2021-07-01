//houghb.cpp

#include <cekeikon.h>

int main(int argc, char** argv){ 
    if (argc!=3 && argc!=4 && argc!=5) {
        
        printf("HoughB: Transformada de Hough de imagem binaria\n");
        printf("HoughB ent.bmp sai.pgm [graus_theta/pix_x_sai] [pix_ent/pix_y_sai]\n");
        printf("Eixo horizontal de sai.tga = theta indo de -90 a +90 graus\n");
        printf("  Se graus_theta/pix_x_sai=2.0, sai tera 91 colunas.\n");
        printf("  Graus_theta/pix_x_sai=1.0 por default\n");
        printf("Eixo vertical de sai.tga = rho com zero central\n");
        printf("  Se pix_ent/pix_y_sai=2.0, cada linha de sai = 2 pixels de ent\n");
        printf("  pix_ent/pix_y_sai=1.0 por default\n");
        printf("Nota: ent.lc=ent.rows/2; ent.cc=ent.cols/2\n");
        erro("Erro: Numero de parametros invalido");
        }
        
        double gtpxs=1.0;
        
        if (argc>=4) {
            if (sscanf(argv[3],"%lf",&gtpxs)!=1)
            erro("Erro: leitura graus_theta/pix_x_sai");
            }
        double pepys=1.0;
        
        if (argc==5) {
            if (sscanf(argv[4],"%lf",&pepys)!=1)
            erro("Erro: leitura pix_ent/pix_y_sai");
            }
            
        ImgXyb<GRY> ent;
        le(ent,argv[1]);
        ent.centro(ent.rows/2,ent.cols/2);
        
        //Constructor faz diferente
        
        int nl2=teto( sqrt(double( elev2(ent.lc)+elev2(ent.cc)))/pepys );
        
        int nl=2*nl2+1;// indexacao de rho vai de -nl2 ent +nl2.
        // y=rho/pepys;
        
        int nc2=teto(90.0/gtpxs);
        int nc=2*nc2+1;
        // indexacao de theta vai de -nc2 ent +nc2
        // x=theta/gtpxs;
        
        ImgXyb<FLT> sai(nl,nc,0.0);
        sai.centro(nl2,nc2);
        
        for (int xa=ent.minx; xa<=ent.maxx; xa++) {
            for (int ya=ent.miny; ya<=ent.maxy; ya++)
                if (ent(xa,ya)==0) {
                    for (int theta=-nc2; theta<=nc2; theta++) {
                        double rad=gtpxs*(M_PI*double(theta)/180);
                        int rho=arredonda((xa*cos(rad)+ya*sin(rad))/pepys);
                        sai(theta,rho)-=0.01;
                    }
                }
            }
            
        sai=normaliza(sai);
        imp(sai,argv[2]);
}