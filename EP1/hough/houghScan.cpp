//HoughCV.cpp pos2014
#include <cekeikon.h>

int main(){ 
    Mat_<GRY> a; 
    le(a,"f3.bmp"); { 
        using namespace Morphology;
        a=-a;   // imagem deve ser backg preto e foreg branco
    }
    
    vector<Vec2f> lines;
    HoughLines(a, lines, 1, deg2rad(2), 60);
    // void HoughLines(InputArray image, OutputArray lines,
    //                 double rho, double theta, int threshold, 
    //                 double srn=0, double stn=0 )
    
    for (unsigned i=0; i<lines.size(); i++) {
        printf("%u %g %g\n",i,lines[i][0],rad2deg(lines[i][1]));
        }
        
        Mat_<COR> d; 
        le(d,"fig1.jpg");
        
        for( size_t i = 0; i < lines.size(); i++ ) {
            float rho = lines[i][0], theta = lines[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a*rho, y0 = b*rho;
            pt1.x = cvRound(x0 + 1000*(-b));
            pt1.y = cvRound(y0 + 1000*(a));
            pt2.x = cvRound(x0 - 1000*(-b));
            pt2.y = cvRound(y0 - 1000*(a));
            line( d, pt1, pt2, Scalar(0,0,255), 1, CV_AA);
            }
            mostra(d);
        }