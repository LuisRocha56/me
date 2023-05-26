#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50 // Longitud máxima del nombre del comensal
#define MAX_PARTY_SIZE 8 // Tamaño máximo de grupo de comensales
#define MAX_WAITING_LIST_SIZE 100 // Tamaño máximo de la lista de espera

typedef struct {
    char name[MAX_NAME_LEN];
    int party_size;
} Customer;

typedef struct {
    Customer customers[MAX_WAITING_LIST_SIZE];
    int num_customers;
} WaitingList;

WaitingList non_smoking_lists[2]; // Lista de espera para no fumadores
WaitingList smoking_lists[2]; // Lista de espera para fumadores

// Función para agregar un comensal a la lista de espera
void add_customer() {
    Customer new_customer;
    int area_preference, table_preference;
    printf("Ingrese el nombre del comensal: ");
    scanf("%s", new_customer.name);
    printf("Ingrese el tamaño del grupo (1-8): ");
    scanf("%d", &new_customer.party_size);
    printf("Ingrese la preferencia de área (0 = no fumar, 1 = fumar): ");
    scanf("%d", &area_preference);
    printf("Ingrese la preferencia de mesa (4 o 8 personas): ");
    scanf("%d", &table_preference);
    
    if (table_preference != 4 && table_preference != 8) {
        printf("Preferencia de mesa inválida.\n");
        return;
    }
    
    if (area_preference == 0) { // No fumadores
        if (table_preference == 4) {
            if (non_smoking_lists[0].num_customers < MAX_WAITING_LIST_SIZE) {
                non_smoking_lists[0].customers[non_smoking_lists[0].num_customers] = new_customer;
                non_smoking_lists[0].num_customers++;
                printf("El comensal %s ha sido agregado a la lista de espera para no fumadores de mesa para 4 personas.\n", new_customer.name);
            } else {
                printf("Lo siento, la lista de espera para no fumadores de mesa para 4 personas está llena.\n");
            }
        } else { // table_preference == 8
            if (non_smoking_lists[1].num_customers < MAX_WAITING_LIST_SIZE) {
                non_smoking_lists[1].customers[non_smoking_lists[1].num_customers] = new_customer;
                non_smoking_lists[1].num_customers++;
                printf("El comensal %s ha sido agregado a la lista de espera para no fumadores de mesa para 8 personas.\n", new_customer.name);
            } else {
                printf("Lo siento, la lista de espera para no fumadores de mesa para 8 personas está llena.\n");
            }
        }
    } else { // area_preference == 1, fumadores
        if (table_preference == 4) {
            if (smoking_lists[0].num_customers < MAX_WAITING_LIST_SIZE) {
                smoking_lists[0].customers[smoking_lists[0].num_customers] = new_customer;
                smoking_lists[0].num_customers++;
                printf("El comensal %s ha sido agregado a la lista de espera para");
            }
        }
    }
}

