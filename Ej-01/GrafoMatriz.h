#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H


template<class T>
class GrafoMatriz {
private:
    T** Nodos;
    int** PesoArcos;
    bool** Arcos;
    int tam;
public:
    GrafoMatriz(int size);

    // Metodos de Nodos

    void nodo_agregar(int n, T val);

    void nodo_remover(int n);

    void nodo_set_val(int n, T val);

    T nodo_get_val(int n2);


    // Metodos de Arcos

    void arco_agregar(int n1, int n2, int val);

    void arco_remover(int n1, int n2);

    void arco_set_val(int n1, int n2, int val);

    int arco_get_val(int n1, int n2);


    int adyacentes(int n1, int n2);

    int *vecinos(int n);

    bool esVacio();
};

template<class T>
GrafoMatriz<T>::GrafoMatriz(int size) {
    tam = size;
    Nodos = new T*[size];
    Arcos = new bool*[size];
    PesoArcos = new int*[size];
    for (int i = 0; i < size; i++) {
        Nodos[i] = NULL;
        Arcos[i] = new bool[size];
        PesoArcos[i] = new int[size];
        for (int j = 0; j < size; j++) {
            Arcos[i][j] = 0;
        }
    }
}

template<class T>
void GrafoMatriz<T>::nodo_agregar(int n, T val) {
    if (Nodos[n] == NULL && n < tam) {
        Nodos[n] = new T;
        *Nodos[n] = val;
        return;
    }
    throw 1;
}

template<class T>
void GrafoMatriz<T>::nodo_remover(int n) {
    if (Nodos[n] == NULL) {
        throw 1;
    }
    if (n < tam) {
        delete Nodos[n];
        Nodos[n] = NULL;
    }
}

template<class T>
void GrafoMatriz<T>::nodo_set_val(int n, T val) {
    if (n < tam && Nodos[n] != NULL) {
        *Nodos[n] = val;
        return;
    }
    throw 1;
}

template<class T>
T GrafoMatriz<T>::nodo_get_val(int n2) {
    if (n2 < tam && Nodos[n2] != NULL) {
        return *Nodos[n2];
    }
    throw 1;
}

template<class T>
void GrafoMatriz<T>::arco_agregar(int n1, int n2, int val) {
    if (Arcos[n1][n2] == 1 || n1 > tam || n2 > tam || Nodos[n1] == NULL || Nodos[n2] == NULL) {
        throw 1;
    }
    Arcos[n1][n2] = 1;
    PesoArcos[n1][n2] = val;
}

template<class T>
void GrafoMatriz<T>::arco_remover(int n1, int n2) {
    if (n1 > tam || n2 > tam) {
        throw 1;
    }
    Arcos[n1][n2] = 0;
}

template<class T>
void GrafoMatriz<T>::arco_set_val(int n1, int n2, int val) {
    if (Arcos[n1][n2] == 0) {
        throw 1;
    }
    PesoArcos[n1][n2] = val;
}

template<class T>
int GrafoMatriz<T>::arco_get_val(int n1, int n2) {
    if (n1 > tam || n2 > tam || Arcos[n1][n2] == 0) {
        throw 1;
    }
    return PesoArcos[n1][n2];
}

template<class T>
int GrafoMatriz<T>::adyacentes(int n1, int n2) {
    if (n1 > tam || n2 > tam) {
        throw 1;
    }
    return Arcos[n1][n2];
}

template<class T>
int *GrafoMatriz<T>::vecinos(int n) {
    return Arcos[n];
}

template<class T>
bool GrafoMatriz<T>::esVacio() {
    for (int i = 0; i < tam; i++) {
        if (Nodos[i] != NULL) {
            return false;
        }
    }
    return true;
}


#endif //GRAFOMATRIZ_H
