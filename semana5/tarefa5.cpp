#include <cekeikon.h>
int main()
{
    Mat_<FLT> a; le(a,"a.png");
    Mat_<FLT> q; le(q,"q.png");
    Mat_<FLT> p;
    q=somaAbsDois(dcReject(q));
    p=matchTemplateSame(a, q, CV_TM_CCOEFF_NORMED);
    imp(p,"ncc.pgm");
    Mat_<COR> d; converte(a,d);
    for (int l=0; l<a.rows; l++)
        for (int c=0; c<a.cols; c++)
            if (p(l,c)>=0.90 || p(l,c) < -0.90 )
                rectangle(d,Point(c-2,l-2),Point(c+2,l+2),Scalar(0,0,255),2);
    imp(d,"resultado.png");
}