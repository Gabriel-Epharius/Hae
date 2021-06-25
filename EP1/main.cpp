#include<cekeikon.h>

int main() {
    Mat_<FLT> m[3];
    Mat_<FLT> temp[21];
    for(int i = 2; i<=4; i++){
        string path;
        path = "imgs/m";
        path += to_string(i);
        path += ".pgm";
        le(m[i-2], path);
        m[i-2] = somaAbsDois(dcReject(m[i-2]));
    }
    
    int j = 0;

    for(int i = 2; i<=4; i++){
        string path;
        if (i == 3) {
            for(int n = 1; n<=3; n++){
                path = "imgs/m";
                path += to_string(i);
                path.append("_00");
                path += to_string(n);
                path += ".jpg";

                le(temp[j], path);
                //temp[j] = dcReject(temp[j]);
                j++;
                cout << path << " i:" << j << endl;
            }
        } else {
            for(int n = 1; n<=9; n++){
                path = "imgs/m";
                path += to_string(i);
                path.append("_00");
                path += to_string(n);
                path += ".jpg";

                le(temp[j], path);
                temp[j] = dcReject(temp[j]);
                j++;
                cout << path << " i:" << j << endl;
            }
        }
    }



    float cor[21][3];
    Mat_<FLT> p_temp;


    p_temp = matchTemplateSame(temp[0], m[0] ,CV_TM_CCORR);

    for(int i = 0; i<= 20; i++){
        for(int j = 0; j<=2; j++){
            //p_temp = matchTemplateSame(temp[i], m[j], CV_TM_CCORR);

            /*for (int l=0; l<p_temp.rows; l++)
                for (int c=0; c<p_temp.cols; c++)
                       if (p_temp(l,c) > 1)
                            cor[i][j] += p_temp(l,c);*/

            //cout << i << " " << j << " Correlação:" << cor[i][j] << endl;   
        }      
    }
}

