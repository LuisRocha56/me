#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50 // Longitud máxima del nombre del comensal
#define MAX_TAMANO_GRUPO 8 // Tamaño máximo de grupo de comensales
#define MAX_TAMANO_LISTA_ESPERA 100 // Tamaño máximo de la lista de espera

typedef struct {
    char nombre[MAX_NOMBRE];
    int tamano;
} Cliente;

typedef struct {
    Cliente cliente[MAX_TAMANO_LISTA_ESPERA];
    int num_clientes;
} ListaEspera;

ListaEspera Lista_noFumadores[2]; // Lista de espera para no fumadores
ListaEspera Lista_Fumadores[2]; // Lista de espera para fumadores

// Función para agregar un comensal a la lista de espera
void anadir_clientes() {
    Cliente nuevo_cliente;
    int area_preferida, mesa_preferida;
    printf("Ingrese el nombre del comensal: ");
    scanf("%s", nuevo_cliente.nombre);
    printf("Ingrese el tamaño del grupo (1-8): ");
    scanf("%d", &nuevo_cliente.tamano);
    printf("Ingrese la preferencia de área (0 = no fumar, 1 = fumar): ");
    scanf("%d", &area_preferida);
    printf("Ingrese la preferencia de mesa (4 o 8 personas): ");
    scanf("%d", &mesa_preferida);
    
    if (mesa_preferida != 4 && mesa_preferida != 8) {
        printf("Preferencia de mesa inválida.\n");
        return;
    }
    
    if (area_preferida == 0) { // No fumadores
        if (mesa_preferida == 4) {
            if (Lista_noFumadores[0].num_clientes < MAX_TAMANO_LISTA_ESPERA) {
                Lista_noFumadores[0].cliente[Lista_noFumadores[0].num_clientes] = nuevo_cliente;
                Lista_noFumadores[0].num_clientes++;
                printf("El comensal %s ha sido agregado a la lista de espera para no fumadores de mesa para 4 personas.\n", nuevo_cliente.nombre);
            } else {
                printf("Lo siento, la lista de espera para no fumadores de mesa para 4 personas está llena.\n");
            }
        } else { // table_preference == 8
            if (Lista_noFumadores[1].num_clientes < MAX_TAMANO_LISTA_ESPERA) {
                Lista_noFumadores[1].cliente[Lista_noFumadores[1].num_clientes] = nuevo_cliente;
                Lista_noFumadores[1].num_clientes++;
                printf("El comensal %s ha sido agregado a la lista de espera para no fumadores de mesa para 8 personas.\n", nuevo_cliente.nombre);
            } else {
                printf("Lo siento, la lista de espera para no fumadores de mesa para 8 personas está llena.\n");
            }
        }
    } else { // area_preference == 1, fumadores
        if (mesa_preferida == 4) {
            if (Lista_Fumadores[0].num_clientes < MAX_TAMANO_LISTA_ESPERA) {
                Lista_Fumadores[0].cliente[Lista_Fumadores[0].num_clientes] = nuevo_cliente;
                Lista_Fumadores[0].num_clientes++;
                printf("El comensal %s ha sido agregado a la lista de espera para");
				}
			}
		}
}

