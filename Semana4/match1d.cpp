//match1d.cpp - grad2020

#include <cekeikon.h>


int main(){ 
    Mat_<FLT> a =( Mat_<FLT>(1,13)<<0,1,0,0,1,0,1,1,1,0,1,1,0); xprint(a); 
    Mat_<FLT> q =( Mat_<FLT>(1,3)<<0,1,1); xprint(q); 
    Mat_<FLT> p=filtro2d(a,q,BORDER_REPLICATE); xprint(p);

    Mat_<FLT> q2=dcReject(q); xprint(q2);  
    Mat_<FLT> p2=filtro2d(a,q2,BORDER_REPLICATE); xprint(p2);

    Mat_<FLT> a3=a+10; xprint(a3);  
    Mat_<FLT> p3=filtro2d(a3,q2,BORDER_REPLICATE); xprint(p3);

    Mat_<FLT> q4=somaAbsDois(dcReject(q)); xprint(q4);  
    Mat_<FLT> p4=filtro2d(a,q4,BORDER_REPLICATE); xprint(p4);

    Mat_<FLT> q5=somaAbsDois(dcReject(q)); xprint(q5);   //retira a influência do brilho
    
    Mat_<FLT> p5=filtro2d(a3,q4,BORDER_REPLICATE); xprint(p5);
    
}