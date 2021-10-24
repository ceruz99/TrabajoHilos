#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

int contadorManzanas=0;
int contadorPeras=0;

void manzanas()
{
    for(int i=0;i < 100; i++){
        int aleatorio1=rand()%(2);
        if(aleatorio1==1){
            cout<<"Este cliente compro manzana"<<endl;
            contadorManzanas+=1;
        }
        else{
            cout<<"Este cliente no compro manzana"<<endl;
        }
    }
}

void peras()
{
    for(int i=0;i< 100;i++){
        int aleatorio2=rand()%(2);
        if(aleatorio2==1){
            cout<<"Este cliente compro pera"<<endl;
            contadorPeras+=1;
        }
        else{
            cout<<"Este cliente no compro pera"<<endl;
        }
    }
}

int main()
{
    /*
    Tienda de Informa2
    En la tienda de Informa2 se está haciendo una oferta de peras y manzanas. Muchas
    personas estan yendo a visitar la tienda para revisar la calidad del producto y
    así, decidir si comprar o no. Se lleva el inventario de las manzanas y peras
    vendidas y al final del día se sabrá cuantas manzanas y peras se habrán vendido.
    */
    std::thread first (manzanas);
    std::thread second (peras);

    srand(time(NULL));


    first.join();
    second.join();

    cout<<endl<<"Se vendieron "<<contadorManzanas<<" manzanas"<<endl;
    cout<<endl<<"Se vendieron "<<contadorPeras<<" peras"<<endl;
    return 0;
}
