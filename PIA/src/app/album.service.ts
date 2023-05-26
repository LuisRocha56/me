import { Injectable } from '@angular/core';
import { environment } from '../environments/environment';
import { initializeApp } from "firebase/app";
import { Auth, createUserWithEmailAndPassword, signInWithEmailAndPassword } from 'firebase/auth';
import { getAuth, onAuthStateChanged } from "firebase/auth";
//import { User } from '../user';
//import { Usercom } from '../usuariocomponente';
import { getFirestore, collection, addDoc, getDocs, doc, setDoc, deleteDoc,query, getDoc} from 'firebase/firestore';
import { getDatabase } from "firebase/database";
import { Firestore } from 'firebase/firestore';
import { Observable } from 'rxjs';

//Se contacta con el firebase gracias al archivo enviroment que contiene la info
const firebaseApp = initializeApp(environment.firebaseConfig);
//Se accede a la parte que almacena informacion de bases de datos en firebase
const dbCloudFirestore = getFirestore(firebaseApp);
//Se hace una constante que esta definida por lo anterior
const db = dbCloudFirestore;
//Ahora una constante que gracias a db nos deja seleccionar la coleccion
const  q = query(collection(db,"playlist"));

@Injectable({
  providedIn: 'root'
})
export class AlbumService {
  //Se crean dos arreglos vacios y un string, uno para info de albums, otra para que sea solo un album determinado y otra la cancion del album
  album: any[] =[]
  albumb: any[] = []
  albumc: any = ""
  constructor() { }

  async getalbum(){
    //Se inicializa vacio para que no se quede la informacion retenida y vuelva a llenar con lo mismo
    this.album = []

    //Trae toda la info de la coleccion y en consola muestra lo que trajo, lo almacena en el arreglo
    const querySnapchot = await getDocs(q);
    querySnapchot.forEach((doc)=>{
      this.album.unshift(doc.data())
      console.log(doc.data())
    })
  }

  //Con la info de los album ahora si se le da otro parametro el cual es un campo de la tabla para traer
  //solo los que coincidan con el nombre tanto en parametro como en tabla
  async pornombre(nombre:string){
    this.albumb = []
    const querySnapchot = await getDoc(doc(db,'albums',nombre));
    console.log(querySnapchot.data());
    return querySnapchot.data();
  }



    
}