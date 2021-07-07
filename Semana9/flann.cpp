//Flann.cpp com 4 arvores - pos2020
//Linkar com OpenCV2 ou OpenCV3

#include <cekeikon.h>

int main(){  
    MNIST mnist(10,true,true);  
    mnist.le("/home/gabriel/cekeikon5/tiny_dnn/data");  
    TimePoint t1=timePoint();  
    flann::Index ind(mnist.ax,flann::KDTreeIndexParams(1024));  
    
    TimePoint t2=timePoint();  
    vector<int> indices(1); 
    vector<float> dists(1);
    
    for(int l=0; l<mnist.qx.rows; l++){    
        ind.knnSearch(mnist.qx.row(l),indices,dists,1,flann::SearchParams(1024));    
        mnist.qp(l)=mnist.ay(indices[0]);
    }  
    
    TimePoint t3=timePoint();  
    printf("Erros=%10.2f%%\n",100.0*mnist.contaErros()/mnist.nq);  
    printf("Tempo de treinamento: %f\n",timeSpan(t1,t2));  
    printf("Tempo de predicao: %f\n",timeSpan(t2,t3));
}