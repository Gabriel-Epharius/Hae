//nearest_v3.cpp - pos2020
//Linkar com opencv3 (compila knearest_v3 -c -v3)

#include <cekeikon.h>

int main(){ 
    MNIST mnist(10,true,true);  
    mnist.le("/home/gabriel/cekeikon5/tiny_dnn/data");  


    for (int i = 0; i != mnist.AX.end()); i++){
        cout << mnist.AX.push_back(i) << endl;
    }
    
    /*
    TimePoint t1=timePoint();  
    Ptr<ml::KNearest>  knn(ml::KNearest::create());  
    knn->train(mnist.ax, ml::ROW_SAMPLE, mnist.ay);  
    TimePoint t2=timePoint();  
    Mat_<FLT> dist;  
    knn->findNearest(mnist.qx,1, noArray(), mnist.qp, dist);  
    TimePoint t3=timePoint();  
    printf("Erros=%10.2f%%\n",100.0*mnist.contaErros()/mnist.nq);  
    printf("Tempo de treinamento: %f\n",timeSpan(t1,t2));  
    printf("Tempo de predicao: %f\n",timeSpan(t2,t3));*/
}