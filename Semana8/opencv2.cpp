//boost.cpp grad2021OpenCV2

#include <cekeikon.h>

int main(){  
    Mat_<COR> ax; 
    le(ax,"janei.pgm");  
    
    Mat_<GRY> ay; 
    le(ay,"janei-1.pgm");
    
    if(ax.size()!=ay.size()) 
        erro("Erro: Dimensoes diferentes");  
        
    Mat_<FLT> features(ax.total(),3);  
    Mat_<FLT> saidas(ay.total(),1);
    for(unsigned i=0; i<ax.total(); i++){ 
           features(i,0)=ax(i)[0]/255.0;    
           features(i,1)=ax(i)[1]/255.0;    
           features(i,2)=ax(i)[2]/255.0;    
           
           saidas(i,0)=ay(i)/255.0;
        }  
        
    CvBoost ind(features,CV_ROW_SAMPLE,saidas);  
    
    Mat_<COR> qx; le(qx,"julho.pgm");  
    Mat_<GRY> qp(qx.rows,qx.cols);
    
    for(unsigned i=0; i<qx.total(); i++){    
        Mat_<FLT> query(1,3);    
        query(0)=qx(i)[0]/255.0;    
        query(1)=qx(i)[1]/255.0;    
        query(2)=qx(i)[2]/255.0;
        
        int pred=saturate_cast<GRY>(155*ind.predict(query));    
        
        qp(i)=pred;
    }  
        
    imp(qp,"julho-p1-opencv2.png");
}
    
