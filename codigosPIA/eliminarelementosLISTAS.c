#include <stdio.h>
#include <stdlib.h>

// Definimos la estructura para un nodo de la lista encadenada
struct Nodo {
    int valor;
    struct Nodo* siguiente;
};

// Función para insertar un elemento al inicio de la lista
void insertar_inicio(struct Nodo** cabeza_ref, int nuevo_valor) {
    // Creamos un nuevo nodo y asignamos el valor
    struct Nodo* nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo_nodo->valor = nuevo_valor;
    
    // Asignamos el siguiente nodo del nuevo nodo a la cabeza actual de la lista
    nuevo_nodo->siguiente = *cabeza_ref;
    
    // Actualizamos la cabeza de la lista para que apunte al nuevo nodo
    *cabeza_ref = nuevo_nodo;
}

// Función para insertar un elemento al final de la lista
void insertar_final(struct Nodo** cabeza_ref, int nuevo_valor) {
    // Creamos un nuevo nodo y asignamos el valor
    struct Nodo* nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo_nodo->valor = nuevo_valor;
    nuevo_nodo->siguiente = NULL;
    
    // Si la lista está vacía, hacemos que la cabeza apunte al nuevo nodo
    if (*cabeza_ref == NULL) {
        *cabeza_ref = nuevo_nodo;
        return;
    }
    
    // Recorremos la lista hasta el último nodo y lo actualizamos para que apunte al nuevo nodo
    struct Nodo* nodo_actual = *cabeza_ref;
    while (nodo_actual->siguiente != NULL) {
        nodo_actual = nodo_actual->siguiente;
    }
    
    nodo_actual->siguiente = nuevo_nodo;
}

// Función para eliminar un elemento de la lista
void eliminar_elemento(struct Nodo** cabeza_ref, int valor_a_eliminar) {
    // Verificamos si la lista está vacía
    if (*cabeza_ref == NULL) {
        return;
    }
    
    // Si el valor a eliminar es el primer elemento de la lista, actualizamos la cabeza
    if ((*cabeza_ref)->valor == valor_a_eliminar) {
        struct Nodo* nodo_a_eliminar = *cabeza_ref;
        *cabeza_ref = (*cabeza_ref)->siguiente;
        free(nodo_a_eliminar);
        return;
    }
    
    // Buscamos el nodo anterior al nodo a eliminar
    struct Nodo* nodo_anterior = *cabeza_ref;
    while (nodo_anterior->siguiente != NULL && nodo_anterior->siguiente->valor != valor_a_eliminar) {
        nodo_anterior = nodo_anterior->siguiente;
    }
    
    // Si no encontramos el valor a eliminar, salimos
    if (nodo_anterior->siguiente == NULL) {
        return;
    }
    
    // Actualizamos los punteros para eliminar el nodo
    struct Nodo* nodo_a_eliminar = nodo_anterior->siguiente;
    nodo_anterior->siguiente = nodo_a_eliminar->siguiente;
    free(nodo_a_eliminar);
}

// Función para imprimir la lista
void imprimir_lista(struct Nodo* cabeza) {
    struct Nodo* nodo_actual = cabeza;
    while (nodo_actual != NULL) {
        printf("%d ", nodo_actual->valor);
        nodo_actual = nodo_actual->siguiente;
    }
}

int main() {
    struct Nodo* cabeza = NULL;
    
    insertar_final(&cabeza, 1);
    insertar_inicio(&cabeza, 2);
    insertar_final(&cabeza, 3);
    
    printf("La lista encadenada es: ");
    imprimir_lista(cabeza);
    
    return 0;
}
