#ifndef LISTA_H_
#define LISTA_H_
#include "Nodo.h"


template<class T> class Lista {

    private:
        //Atributos
        Nodo<T>* primero;
        Nodo<T>* actual;
        int tamanio;

    public:

        // Constructor
        // PRE: -
        // POS: crea una lista vacía.
        Lista();

        // PRE: Lista creada.
        // POS: devuelve la cantidad de elementos de la Lista.
        int contarElementos();

        // PRE: Lista creada.
        // POS: agrega elemento al final de la Lista.
        void agregar(T elemento);

        // PRE: -
        // POS: agrega el nuevo elemento en la posición indicada.
        void agregar(T elemento, int posicion);

        // PRE: -
        // POS: reinicia el elemento actual.
        void iniciarActual();

        // PRE: -
        // POS: el actual avanza al siguiente elemento.
        //      Es decir, el nuevo actual ahora es el siguiente del anterior actual.
        bool avanzarActual();

        // PRE: -
        // POS: devuelve el elemento actual.
        T obtenerActual();

        // PRE: las posiciones de los datos son válidas, es decir son <= al tamaño de la lista.
        //      ADemás, es x<y        
        // POS: intercambia los datos que se encuentran en las posiciones dadas.
        void intercambiarDatos(int x, int y);

        // PRE: recibe una lista.
        // POS: modifica la lista original agregandole al final la lista recibida por parámetro.
        //      Es decir, une la lista original con la lista recibida por parámetro.
        void unirListas(Lista<T>* listaAux);


        // PRE: recibe un dato.
        // POS: elimina la primera ocurrencia del dato en la lista.
        //      Si no lo encuentra no hace nada.
        void eliminarDato(T dato);

        // PRE: Lista creada.
        // POS: libera los recursos de memoria de la lista.
        ~Lista();

    private:

        // PRE: posición tiene que ser dato válido.
        // POS: devuelve el nodo según la posición.
        Nodo<T>* obtenerNodo(int posicion);

        // PRE: -
        // POS: compara el dato pasado por paràmetro con un dato de la lista.
        //      Devuelve 0 si son iguals, 1 si el dato de la lista es mayor y -1 si es menor.
        int comparar(T datoA, T datoB);
};

template<class T> Lista<T>::Lista() {
    this->primero = nullptr;
    this->tamanio = 0;
    this->actual = nullptr;
}

template<class T> int Lista<T>::contarElementos() {
    return this->tamanio;
}

template<class T> void Lista<T>::agregar(T elemento) {
    this->agregar(elemento, this->tamanio + 1);
}

template<class T> void Lista<T>::agregar(T elemento, int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {
        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (posicion == 1) {
            nuevo->cambiarSiguiente(this->primero);
            this->primero = nuevo;

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
            anterior->cambiarSiguiente(nuevo);
        }
        this->tamanio++;
        this->iniciarActual();
    }
}

template<class T> void Lista<T>::iniciarActual() {
    this->actual = nullptr;
}

template<class T> bool Lista<T>::avanzarActual() {

    if (this->actual == nullptr) {
        this->actual = this->primero;
    } else {
        this->actual = this->actual->obtenerSiguiente();
    }
    return (this->actual != nullptr);
}

template<class T> T Lista<T>::obtenerActual() {

    T elemento;
    if (this->actual != nullptr) {
        elemento = this->actual->obtenerDato();
    }
    return elemento;
}

template<class T> void Lista<T>::intercambiarDatos(int x, int y) {

    Nodo<T>* nodoPrimerDato = this->primero;
    Nodo<T>* nodoSegundoDato = nodoPrimerDato;
    T dato;

    for (int i = 1; i < x; i++) {
        nodoPrimerDato = nodoPrimerDato->obtenerSiguiente();
    }

    for (int j = x; j < y; j++) {
        nodoSegundoDato = nodoSegundoDato->obtenerSiguiente();
    }

    dato = nodoPrimerDato->obtenerDato();
    nodoPrimerDato->cambiarDato(nodoSegundoDato->obtenerDato());
    nodoSegundoDato->cambiarDato(dato);

}


template<class T> void Lista<T>::unirListas(Lista<T>* listaAux) {

    Nodo<T>* nodoAux = this->primero;

    while (nodoAux->obtenerSiguiente()){
        nodoAux = nodoAux->obtenerSiguiente();
    }

    nodoAux->cambiarSiguiente(listaAux->primero);

}

template<class T> void Lista<T>::eliminarDato(T dato) {

    Nodo<T>* nodoActual = this->primero;
    Nodo<T>* nodoAnterior = nullptr;
    bool encontrado = false;

    while (nodoActual && !encontrado){
        encontrado = (comparar(nodoActual->obtenerDato(), dato) == 0) ? true : false;
        if (encontrado) {
            nodoAnterior->cambiarSiguiente(nodoActual->obtenerSiguiente());
            delete nodoActual;
        }
        else {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->obtenerSiguiente();
        }
    }

}

template<class T> Lista<T>::~Lista() {

    while (this->primero != nullptr) {
        Nodo<T>* nodoBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();

        delete nodoBorrar;
    }
}

template<class T> Nodo<T>* Lista<T>::obtenerNodo(int posicion) {

    Nodo<T>* nodoActual = this->primero;
    for (int i = 1; i < posicion; i++) {
        nodoActual = nodoActual->obtenerSiguiente();
    }
    return nodoActual;
}

template<class T> int Lista<T>::comparar(T datoA, T datoB) {

    if (datoA == datoB)
        return 0;
    else if (datoA > datoB)
        return 1;
    else
        return -1;
}


#endif /* LISTA_H_ */
