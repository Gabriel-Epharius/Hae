//shear.cpp pos2016
#include <cekeikon.h>

int main(){ 
    Mat_<FLT> src =(Mat_<FLT>(3,2)<<0,0,0,511,511,511);
    cout << src << endl;

    Mat_<FLT> dst =(Mat_<FLT>(3,2)<<200,100,100,400,400,400);
    cout << dst << endl;

    Mat_<FLT> m=getAffineTransform(src,dst);
    cout << m << endl;

    Mat_<GRY> a; 
    le(a,"lennag.jpg");

    Mat_<GRY> b;
    warpAffine(a,b,m,a.size(),INTER_LINEAR,BORDER_WRAP);
    
    imp(b,"afim.png");
}


