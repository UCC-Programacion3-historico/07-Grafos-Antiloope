#include <iostream>
#include <string>
#include "GrafoMatriz.h"

using namespace std;

int main() {
    GrafoMatriz<string> gr(4);

    gr.nodo_agregar(1,"Hola");
    gr.nodo_agregar(2,"Como");
    gr.nodo_agregar(3,"Estas");

    gr.arco_agregar(1,2,20);


    for (int k = 0; k < 4; k++) {
        try {
            cout << gr.nodo_get_val(k) << " ";
        }catch (int e) {
            cout << "NULL ";
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            try {
                cout << gr.arco_get_val(i,j) << " ";
            } catch (int e) {
                cout << "0 ";
            }

        }
        cout << '\n';
    }
    return 0;
}
