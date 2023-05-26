#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo* siguiente;
};

// Función para insertar un elemento al inicio de la lista
void insertar_inicio(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevo_nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = *cabeza;
    *cabeza = nuevo_nodo;
}

// Función para insertar un elemento al final de la lista
void insertar_final(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevo_nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = NULL;
    
    if (*cabeza == NULL) {
        *cabeza = nuevo_nodo;
    } else {
        struct Nodo* nodo_actual = *cabeza;
        while (nodo_actual->siguiente != NULL) {
            nodo_actual = nodo_actual->siguiente;
        }
        nodo_actual->siguiente = nuevo_nodo;
    }
}

// Función para eliminar un elemento de la lista
void eliminar_elemento(struct Nodo** cabeza, int valor) {
    struct Nodo* nodo_actual = *cabeza;
    struct Nodo* nodo_anterior = NULL;
    
    while (nodo_actual != NULL && nodo_actual->valor != valor) {
        nodo_anterior = nodo_actual;
        nodo_actual = nodo_actual->siguiente;
    }
    
    if (nodo_actual != NULL) {
        if (nodo_anterior == NULL) {
            *cabeza = nodo_actual->siguiente;
        } else {
            nodo_anterior->siguiente = nodo_actual->siguiente;
        }
        free(nodo_actual);
    }
}

// Función para buscar un elemento en la lista
struct Nodo* buscar_elemento(struct Nodo* cabeza, int valor_a_buscar) {
    // Recorremos la lista hasta encontrar el nodo con el valor buscado o hasta llegar al final de la lista
    struct Nodo* nodo_actual = cabeza;
    while (nodo_actual != NULL && nodo_actual->valor != valor_a_buscar) {
        nodo_actual = nodo_actual->siguiente;
    }
    
    // Si llegamos al final de la lista y no encontramos el valor buscado, retornamos NULL
    if (nodo_actual == NULL) {
        return NULL;
    }
    
    // Si encontramos el valor buscado, retornamos el nodo correspondiente
    return nodo_actual;
}

// Función para imprimir la lista
void imprimir_lista(struct Nodo* nodo_actual) {
    while (nodo_actual != NULL) {
        printf("%d ", nodo_actual->valor);
        nodo_actual = nodo_actual->siguiente;
    }
    printf("\n");
}


void vaciar(struct Nodo** cabeza_ref) {
    struct Nodo* actual = *cabeza_ref;
    struct Nodo* siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    *cabeza_ref = NULL;
}
