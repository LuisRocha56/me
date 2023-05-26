//PERSONAS QUE HICIERON ESTE TRABAJO//

//EDSON LUIS ROCHA RODRÍGUEZ - 1863555 - GPO: 032//

//PERSONAS QUE HICIERON ESTE TRABAJO//
#include <stdio.h>

typedef struct Entidad
{ 
	char Matricula[10];
	char Nombre[60];
	char Apellido[40];
	char Grupo[5];
	char Materia[50];
	float  Calificacion;
	char status[1];
	//Entidad.Matricula[0]='z';
}Alumnos;
//void Promedios(Alumnos * puntero);
void Alta(Alumnos * puntero);
void Listar(Alumnos * puntero);
void Busqueda(Alumnos * puntero);
void Modificar(Alumnos * puntero);
void Eliminar(Alumnos * puntero);
void Obtenerpromedio(Alumnos * puntero);
//void Imprimir(Alumnos * punteros);
int main()
{
int opcion=9;	
Alumnos RegistroAlu[60];
Alumnos * puntero;
Alumnos * lt;
lt=&RegistroAlu[0];
puntero=&RegistroAlu[0];
puntero->Matricula[0]='z';

while (opcion!=0)
{
printf("---------MENU----------\n");
printf("[1] Alta Alumnos\n");
printf("[2] Busqueda Alumnos\n");
printf("[3] Listar Alumnos\n");
printf("[4] Modificar Dato\n");
printf("[5] Ver promedios\n");
printf("[6] Eliminar Dato\n");
//printf("[9] Imprimir\n");
printf("[0] Salir del programa\n");
printf("que opcion desea ingresar?:");scanf("%d",&opcion);
printf("\n\n");



switch(opcion)
{

case 1:{
	        while(lt->Matricula[0]!='z')
								{
									lt=lt+1;
								}
	       
	       Alta(lt);
	       system("pause");
system("cls");
	      }break;	
case 2:{
	system("cls");
       Busqueda(puntero);
       }break;
case 3:{
	system("cls");
       Listar(puntero);
       }break;

case 4:{
	system("cls");
       Modificar(puntero);
       }break;
case 5:{
		system("cls");
	    Obtenerpromedio(puntero);

       //Promedios(puntero);
       }break;
case 6:{
	system("cls");
		Eliminar(puntero);
       //Eliminar(puntero);
       }break;
/*case 9:{
	system("cls");
		Imprimir(puntero);
       //Eliminar(puntero);
       }break;*/
	
	
}

};

	
	return 4;
	}

//funcion para dar de Alta los datos de alumno
void Alta(Alumnos * puntero)
{
	int opcion=9;

	while (opcion!=0)
{
printf("1--------Desea ingresar datos del alumno? [1-SI 0-NO]:"); scanf("%d",&opcion);

if (opcion==1)
{
printf("favor de ingresar la matricula: "); getchar();
gets(puntero->Matricula);
printf("ingrese su nombre:");
gets(puntero->Nombre);
printf("ingrese su apellido:");
gets(puntero->Apellido);
printf("ingrese su grupo:");
gets(puntero->Grupo);
printf("ingrese la materia:");
gets(puntero->Materia);
printf("favor de ingresar la calificacion general:");
scanf("%f",&puntero->Calificacion);
puntero=puntero+1;
puntero->Matricula[0]='z';

}
};
}
//funcion para dar de Alta los datos de alumno


//Funcion para listar los datos de los alumnos
void Listar(Alumnos * puntero)
{
	
while(puntero->Matricula[0]!='z')
{
	if(puntero->status[0]!='B'){
		printf("matricula: %s\n",puntero->Matricula);
		printf("nombre: %s \n",puntero->Nombre);
		printf("apellido: %s\n",puntero->Apellido);
		printf("grupo: %s \n",puntero->Grupo);
		printf("materia: %s \n",puntero->Materia);
		printf("calificacion: %f \n\n",puntero->Calificacion);

	}
puntero=puntero+1;
};
}
//Funcion para listar los datos de los alumnos

//funcion para buscar los datos de un alumno
void Busqueda(Alumnos * puntero)
{
char Matricula[10];
int val;
printf("Captura la matricula que deseas buscar \n");	
getchar();
gets(Matricula);

while(puntero->Matricula[0]!='z')
{
	val=strcmp(puntero->Matricula,Matricula);
	if (val==0)
	 {
	 	if(puntero->status[0]!='B'){
	 		printf("matricula %s\n",puntero->Matricula);
			  printf("nombre %s \n",puntero->Nombre);
			  printf("apellido %s\n",puntero->Apellido);
			  printf("grupo %s \n",puntero->Grupo);
			  printf("materia %s \n",puntero->Materia);
			  printf("calificacion %f \n",puntero->Calificacion);
		 }
  }
puntero=puntero+1;
};
	
}
//funcion para buscar los datos de un alumno

//función para modificar los datos de un alumno
void Modificar(Alumnos * puntero)
{
char Matricula[10];
int val;
printf("Captura la matricula que deseas modificar \n");	
getchar();
gets(Matricula);

while(puntero->Matricula[0]!='z')
{
	val=strcmp(puntero->Matricula,Matricula);
	if (val==0)
	 {
printf("captura el nombre\n");
gets(puntero->Nombre);
printf("captura apellido\n");
gets(puntero->Apellido);
printf("captura el grupo\n");
gets(puntero->Grupo);
printf("captura la materia\n");
gets(puntero->Materia);
printf("captura la calificacion la materia\n");
scanf("%f",&puntero->Calificacion);
  }
puntero=puntero+1;
};
	
}	
//función para modificar los datos de un alumno

//funcion para eliminar los datos de un alumno
 void Eliminar(Alumnos * puntero)
{
char Matricula[10];
int val;
printf("Ingresa la matricula del alumno que deseas eliminar: ");
getchar();	
gets(Matricula);
//gets(Matricula);

while(puntero->Matricula[0]!='z')
{
//la linea de abajo (199) me dice que si puntero esta apuntando a matricula, es lo mismo que esta en matricula
//me refiera a la matricula despues de la coma, si es igual me regresa un 0
	val=strcmp(puntero->Matricula,Matricula);
	if (val==0)
	 {
	puntero->status[0]='B';
  }
puntero=puntero+1;
};
	
}
//funcion para eliminar los datos de un alumno


//funcion para obtener el promedio de un alumno
void Obtenerpromedio(Alumnos * puntero)
{
	{
char Matricula[10];
int val;
int cantidad=0;
float calificacion, promedio;
printf("ingrese la matricula del alumno que desea calcular su promedio: \n");	
getchar();
gets(Matricula);

while(puntero->Matricula[0]!='z')
{
	val=strcmp(puntero->Matricula,Matricula);
	if (val==0)
	 {
	 	
	 	if(puntero->status[0]!='B'){
	 		cantidad=cantidad+1;
			calificacion=calificacion+puntero->Calificacion;
		 }
  }
puntero=puntero+1;
};
promedio = calificacion/cantidad;
printf("La calificación de la matricula: %s, es: %f", Matricula, promedio);
}
}
//funcion para obtener el promedio de un alumno

//funcion para obtener el promedio de un alumno

//PERSONAS QUE HICIERON ESTE TRABAJO//

//EDSON LUIS ROCHA RODRÍGUEZ - 1863555 - GPO: 032//

//PERSONAS QUE HICIERON ESTE TRABAJO//

/*void Imprimir (Alumnos * puntero)
{
	
	FILE* fichero;
	fichero = fopen("programalista.txt", "a");
	
	while(puntero->Matricula[0]!='z')
{
	if(puntero->status[0]!='B'){
		fputs(puntero->Matricula,fichero);
		fputs(puntero->Nombre,fichero);
		fputs(puntero->Apellido,fichero);
		fputs(puntero->Grupo,fichero);
		fputs(puntero->Materia,fichero);
		fprintf(fichero,"%f",puntero->Calificacion);

	}
puntero=puntero+1;
};*/
	
	
	
