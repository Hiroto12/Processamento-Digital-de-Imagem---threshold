

#include<iostream>

using namespace std;


void TresholdAutomatico (double matriz[10][10],double T0, double T)
{
    double media1= 0, media2 = 0;
    int cont1 =0, cont2 = 0, k;
    double valor1 =0, valor2 = 0, aux;
    double a = 0,  dif = 0;

    double matriz2[10][10];

    for (int i = 0; i <10;i++)
        for (int j = 0; j<10; j++)
            matriz2[i][j] = matriz [i][j];

    do{

        a = T;
        for  (int i = 0 ; i<10; i++)
        {
            for (int j = 0; j<10; j++){
                aux = matriz2[i][j];

                if (aux > T)
                {
                    valor1 = valor1+ aux;
                    cont1++;

                    matriz2[i][j] = 255;

                }

                else {

                    valor2 = valor2 + aux;
                    cont2++;
                    matriz2[i][j] = 0;
                }
            }

        }

          if (cont1>0)
                    media1 = valor1/cont1;
          if(cont2>0)
                media2 = valor2/cont2;

                T = 0.5 *(media1+media2);

                if ((a-T)<0)
                    dif = -1*(a-T);
                else
                    dif = a-T;



    }while (dif>T0);
    for(int i=0;i<10;i++)
        {
            for(int j=0;j<10; j++)
                cout<<matriz2[i][j],cout<<" ";
            cout<<"\n";
        }

}


int main ()
{

    int dimensao = 10;

    double matriz [10][10] = {{252, 46, 115,18,73,203,60,229,112,183},
                            {109,31, 20, 53, 225,58,170,94},
                            {99,73,116,115,183,146,177,88,14,141},
                            {79,176,132,54,144,148,231,157,244,187},
                            {207,28,4,194,111,122,172,61,211,71},
                            {185,199,124,123,40,195,134,112,17,194},
                            {26,3,168,251,12,85,98,205,174,34},
                            {234,222,166,121,99,167,33,35,43,183},
                            {237,102,254,45,206,234,49,144,1,70},
                            {17,231,44,224,67,195,148,68,127,42}};

    TresholdAutomatico(matriz,0.4,100);


}
