//mediana.cpp - pos2018
#include <cekeikon.h>

Mat_<GRY> mediana(Mat_<GRY> a){  
    Mat_<GRY> b(a.rows,a.cols);
    
    for(int l=0; l<b.rows; l++)
        for(int c=0; c<b.cols; c++){ 
                 vector<int> v;
                 for(int l2=-2; l2<=2; l2++)
                    for(int c2=-2; c2<=2; c2++)
                        if(0<=l+l2 && l+l2<a.rows &&0<=c+c2 && c+c2<a.cols){
                                 v.push_back(a(l+l2,c+c2));
                        }
                                 
                        //vector<int>::iterator meio=v.begin()+v.size()/2;
                        
                        auto meio= v.begin()+v.size()/2;  
                        nth_element(v.begin(), meio, v.end()); 

                        b(l,c)=*meio;
                    
                        }
    return b;
                            }        
                            int main(){ 
                                 Mat_<GRY> a;  le(a,"janei_flann.png"); 
                                  Mat_<GRY> b=mediana(a); 
                                  imp(b,"janei_flann_final.pgm");}

