// Programa que permite manejar la lista de espera de un restaurante
#include<iostream>
using namespace std;

struct nodo
{
    int turno; 
    int personas; 
    struct nodo *sgte;
};
 

struct cola
{
    nodo *Head; //apuntador a cabecera
    nodo *Tail; //apuntador a último
};
 
 
/*                        Insertar en cola de espera     
------------------------------------------------------------------------*/
struct cola * verificarCola(struct cola *cArr, int nPersonas) {

    struct cola * aux;
    nPersonas <=4 ? aux = &cArr[0] : aux = &cArr[1];

    return aux; 
}

void espera(struct cola *cArr, int turno)
{
       
	struct nodo *aux = new(struct nodo);
	
	cout<<"\n\t ** DATOS DEL COMENSAL ** ";
    
    do {
    cout<<"\n\n\t NUMERO DE PERSONAS: (de 1 a 8) "; 
	cin>>aux->personas;
    } while(aux->personas <= 0 || aux->personas > 8);

    aux->turno=turno;    
	cout<<"\n\t TURNO: "<<turno; 

    aux->sgte = NULL;
    // encontrar cola correcta
    struct cola * q = verificarCola(cArr, aux->personas);

     if( q->Head == NULL)
         q->Head = aux;   // encola el primero elemento
     else
         (q->Tail)->sgte = aux;
         
     q->Tail = aux;        // puntero que siempre apunta al ultimo elemento
  
}

/*                        Pasar a mesa al comensal    
------------------------------------------------------------------------*/
int pasar( struct cola &q )
{
     int z;
     struct nodo *aux ;
     
     aux = q.Head;      // aux apunta al inicio de la cola
     z = aux->turno;
     q.Head = (q.Head)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return z;
}
 
/*                        Mostrar Reservas    
------------------------------------------------------------------------*/
void muestraReservas( struct cola q )
{
     struct nodo *aux;
     
     aux = q.Head;
         
     while( aux != NULL )
     {
            cout<<"   Turno:"<< aux->turno <<endl;
            cout<<"   Cant.Pers:"<< aux->personas <<endl<<endl ;
            aux = aux->sgte;
     }    
}
 
/*                        Menu de opciones    
------------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\t LISTA DE ESPERA RESTAURANTE ** LA GLORIETA ** \n\n";
    cout<<" 1. ENTRAR A LISTA DE ESPERA              "<<endl;
    cout<<" 2. PASAR A UNA RESERVA A MESA            "<<endl;
    cout<<" 3. MOSTRAR RESERVAS EN ESPERA            "<<endl;
	cout<<" 4. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
 
/*                        Funcion Principal        
------------------------------------------------------------------------*/
int main()
{
    // vars
    struct cola cArr[2]; // cArr[0] = cola <= 4 personas ; carr[1] = 4 < cola <= 8
    cArr[0].Head = cArr[0].Tail = cArr[1].Head = cArr[1].Tail = NULL;
   
    int i=0;  // contabiliza el turno 
    int t=0;  // contabiliza las reservas en espera
    int op;    // opción del menu
    int x ;    // numero que devuelve la función pasar
   
	system("color 0b");
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
                 i=i+1; 
                 t=t+1;
				 espera( cArr,i );
                 cout<<"\n\n\t\t Hay " << t << " reservas en espera";
            break;
 
 
            case 2:
 				if(cArr[0].Head !=NULL || cArr[1].Head != NULL)
                    {
                        int opcMesa = 0; // var para determinar cual cola pasar
                        do {
                            cout << "Elegir: Mesa para 4 o para 8" << endl; cin >> opcMesa;

                        } while(opcMesa != 4 && opcMesa != 8);
                        struct cola * q = verificarCola(cArr, opcMesa);
                            if(q->Head != NULL) {
                                t=t-1;
                                x = pasar( *q );
                                cout<<"\n\n\t\EL COMENSAL "<< x <<" PUEDE PASAR A SU MESA...\n\n";
                            } else 
                                cout<<"\n\n\t NO HAY RESERVAS EN ESPERA...!"<<endl;
                        }
                    else   
                        cout<<"\n\n\t NO HAY RESERVAS EN ESPERA...!"<<endl;
			break;
                 
 
            case 3:
 
                cout << "\n\n RESERVAS EN ESPERA\n\n";
                if(cArr[0].Head!= NULL || cArr[1].Head != NULL) 
				{
                    cout << "Reservaciones de mesas hasta 4 personas." << endl << endl;
                    muestraReservas(cArr[0]);
                    cout << "Reservaciones de mesas hasta 8 personas." << endl << endl;
                    muestraReservas(cArr[1]);
                    cout<<"\n\n\t\t Hay " << t << " reservas en espera";}
                else 
                    cout<<"\n\n\t NO HAY RESERVAS EN ESPERA...!"<<endl;

            break;
 
          }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=4);
   
   
    return 0;
}