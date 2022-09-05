#include <iostream>
#include "Lista.h"

using namespace std;


int main() {

    Lista<int>* listaEnteros = new Lista<int>;


    listaEnteros->agregar(1);
    listaEnteros->agregar(2);
    listaEnteros->agregar(3);
    listaEnteros->agregar(4);
    listaEnteros->agregar(5);

    listaEnteros->intercambiarDatos(1,4);
    listaEnteros->eliminarDato(5);


    listaEnteros->iniciarActual();

    while (listaEnteros->avanzarActual()){
        int numero = listaEnteros->obtenerActual();
        cout << "Elemento = " << numero << endl;
    }

    delete listaEnteros;

    return 0;
}
