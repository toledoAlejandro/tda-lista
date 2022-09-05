#ifndef NODO_H_
#define NODO_H_

template<class T> class Nodo {

    private:
        //Atributos
        Nodo<T>* siguiente;
        T dato;

    public:
        // Constructor
        // PRE: -
        // POS: crea un nuevo nodo que va a contener un dato.
        //      El nuevo nodo no tiene siguiente.
        Nodo(T dato) {
            this->dato = dato;
            this->siguiente = nullptr;
        }

        //PRE:-
        //POS: devuelve el dato.
        T obtenerDato() {
            return this->dato;
        }

        // PRE: -
        // POS: cambia el dato del nodo por el nuevo dato.
        void cambiarDato(T nuevoDato) {
            this->dato = nuevoDato;
        }

        // PRE: -
        // POS: devuelve el siguiente nodo.
        Nodo<T>* obtenerSiguiente() {
            return this->siguiente;
        }

        // PRE: -
        // POS: cambia el nodo siguiente por el nuevo nodo siguiente.
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {
            this->siguiente = nuevoSiguiente;
        }

};

#endif /* NODO_H_ */
