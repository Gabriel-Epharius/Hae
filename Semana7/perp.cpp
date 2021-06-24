//pers.cpp grad-2018
#include <cekeikon.h>

int main(){
    
      Mat_<FLT> src =(Mat_<FLT>(4,2)<< 
      137,35, 
      323,23,
      106, 320,
      352, 320);
      
      Mat_<FLT> dst =(Mat_<FLT>(4,2)<< 
      106,0, 
      336, 0,
      106, 323,
      352, 323);
      
      Mat_<double> m= getPerspectiveTransform(src,dst);
      
      cout << m << endl;//Verifica se a transformacao esta fazendo o que queremos  
      
      Mat_<double> v=(Mat_<double>(3,1)<< 323,34,1);  

      Mat_<double> w=m*v;
      cout << w << endl;  
      cout << w(0)/w(2)<<" "<< w(1)/w(2)<< endl;//Corrige a perspectiva  
      
      Mat_<COR> a; 
      le(a,"tabuleiro.jpg");
      Mat_<COR> b;
      warpPerspective(a,b,m,a.size());
      
      imp(b,"tabuleiro1.jpg");//Refaz a perspectiva  
      
      m=m.inv(); 
      warpPerspective(b,a,m,a.size());  
      imp(a,"tauleiro2.jpg");
}