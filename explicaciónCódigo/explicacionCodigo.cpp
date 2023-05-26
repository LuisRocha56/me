#include <conio.h> //se agrega esta libreria para la función getch
#include <iostream> //se agrega esta libreria para las funciones de entrada y salida
using namespace std;
void torres_foca(int,int,int,int); //se usa para solución del problema, recibe 4 parametros enteros
main(){
      int a; //esta variable almacena el numero de discos que se ingresarán
      cout<<"Torres de Hanoi\n\n"<<endl; //se imprime este mensaje de pantalla
      cout<<"Ingresa el numero de discos : \t"; //se imprime este mensaje de pantalla para solicitar el numero de discos
       cin>>a; //se lee el valor de a

      torres_foca(a,1,3,2); //se llama a la funcion con los valores que hay adentro, incluyendo el de a
      getch(); //se utiliza esta función para que el usuario preciose cualquier tecla antes de salir
      }
void torres_foca(int foca,int uno,int tres,int dos){ //es la definición de la función
      if(foca==1){  //si el valor de foca es 1, se imprime en pantalla la info de movimiento del disco 1 a 3
            cout<<"Disco : "<<foca<<" del poste  "<<uno<<" al poste "<<tres<<endl;
            getch();  
      }
      else{  //en caso de que no sea así, se llama recursivamente a la función con los valores de foca-1,1 ,2 y 3 como parametros
            torres_foca(foca-1,uno,dos,tres);
            cout<<"Disco : "<<foca<<" del poste  "<<uno<<" al poste "<<tres<<endl;//se imprime la info y se llama recursivamente a la funcion
            getch(); 															  //con los valores de foca-1,2, 3 y 1 como parametros
            torres_foca(foca-1,dos,tres,uno);
      }
}

