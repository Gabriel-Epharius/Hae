//boost.cpp grad2021OpenCV2


#include <cekeikon.h>

Mat_<GRY> opencv2(Mat_<COR> ax, Mat_<GRY> ay,  Mat_<GRY> qx);
Mat_<GRY> mediana(Mat_<GRY> a, int le, int ld, int ce, int cd);

Mat_<GRY> mediana(Mat_<GRY> a, int le, int ld, int ce, int cd){  
    Mat_<GRY> b(a.rows,a.cols);
    
    for(int l=0; l<b.rows; l++)
        for(int c=0; c<b.cols; c++){ 
                 vector<int> v;
                 for(int l2=le; l2<=ld; l2++)
                    for(int c2=ce; c2<=cd; c2++)
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


Mat_<GRY> opencv2(Mat_<COR> ax, Mat_<GRY> ay, Mat_<COR> qx){  
    //Mat_<COR> ax; 
    //le(ax,"janei_filtrado.pgm");  
    
    //Mat_<GRY> ay; 
    //le(ay,"janei-1.pgm");
    
    if(ax.size()!=ay.size())
        erro("Erro: Dimensoes diferentes");  
        
    Mat_<FLT> features(ax.total(),5);  
    Mat_<FLT> saidas(ay.total(),1);
    for(unsigned i=0; i<ax.total(); i++){ 
           features(i,0)=ax(i)[0]/255.0;    
           features(i,1)=ax(i)[1]/255.0;    
           features(i,2)=ax(i)[2]/255.0; 
    
           
           saidas(i,0)= round(ay(i)/255.0);
        }  
        
    CvBoost ind(features,CV_ROW_SAMPLE,saidas);  
    
    //Mat_<COR> qx; 
    //le(qx,"janei_filtrado.pgm");  
    Mat_<GRY> qp(qx.rows,qx.cols);
    
    for(unsigned i=0; i<qx.total(); i++){    
        Mat_<FLT> query(1,5);    
        query(0)=qx(i)[0]/255.0;    
        query(1)=qx(i)[1]/255.0;       
        query(2)=qx(i)[2]/255.0; 
        
        int pred = saturate_cast<GRY>(255*ind.predict(query));    
        
        qp(i)= pred;
            
    }  

    //cout << qp << endl; 
    //imp(qp,"janei-p1.pgm");

    return qp;
}
    
int main (){
    
    /*Mat_<GRY> janei;
    le(janei, "janei_mv.pgm");
    Mat_<GRY> janei_filtrado;
    janei_filtrado = mediana(janei, -2, 2, -2, 2);
    imp(janei_filtrado, "janei_mv_mediana.pgm");
    */

   
    Mat_<COR> ax;
    le(ax, "janei_mv_mediana.pgm");

    Mat_<GRY> ay;
    le(ay, "janei-1.pgm");

    Mat_<COR> qx;
    le(qx, "janei_mv_mediana.pgm");

    Mat_<GRY> qp = opencv2(ax, ay, qx);
    imp(qp, "janei_qp.pgm");

    Mat_<GRY> qp_filtrado;
    qp_filtrado = mediana(qp, -4, 4, -4, 4);

    imp(qp_filtrado, "janei_qp_filtrado.pgm");
    



}