//grad-2017 flann.cpp
//segmentacao de feijao usando FlaNN
//Usa OpenCV2

#include <cekeikon.h>

int main(){ 
    
    //Treino
     Mat_<COR> ax; 
     le(ax,"janei.pgm");  
     Mat_<GRY> ay; 
     le(ay,"janei-1.pgm"); 

    //Tentativa
    Mat_<COR> qx; 
    le(qx,"julho.pgm");
    
    if(ax.size()!=ay.size()) 
        erro("Erro dimensao");  


    //cout << ay << endl;



    Mat_<GRY> qp(qx.rows,qx.cols);
    
    //Cria as estruturas de dados para alimentar OpenCV  
    Mat_<FLT> features(ax.rows*ax.cols,1);  
    Mat_<FLT> saidas(ax.rows*ax.cols,1);

    int i=0;
    
    for(int l=0; l<ax.rows; l++)
        for(int c=0; c<ax.cols; c++){      
            features(i,0)=ax(l,c)[0]/255.0;      
            features(i,1)=ax(l,c)[1]/255.0;      
            features(i,2)=ax(l,c)[2]/255.0;      
            saidas(i)=ay(l,c)/255.0;      
            i=i+1;
        }  
    
    flann::Index ind(features,flann::KDTreeIndexParams(1));
    // Aqui, as 4 arvores estao criadas  
    
    Mat_<FLT> query(1,3);  
    vector<int> indices(1);  
    vector<FLT> dists(1);
    
    for(int l=0; l<qp.rows; l++)
        for(int c=0; c<qp.cols; c++){      
            query(0)=qx(l,c)[0]/255.0;      
            query(1)=qx(l,c)[1]/255.0;      
            query(2)=qx(l,c)[2]/255.0;
            
            // Zero indica sem backtracking      
            
            ind.knnSearch(query,indices,dists,1,flann::SearchParams(0));
            // Saida e' um numero entre 0 e 255      
            qp(l,c)=255*saidas(indices[0]);
        }  
    imp(qp,"julho-p1.pgm");
}