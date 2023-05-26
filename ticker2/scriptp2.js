var verde = document.getElementById("verde");
var cajas = document.querySelector(".cajas");
var boton = document.querySelector("#verde");
var cajaAEliminar = document.querySelector(".caja");

let articulo = document.getElementById("articulo");
let precio = document.getElementById("precio");
let listaArticulos = document.getElementById("listaArticulos");
let totalMSG = document.getElementById("total"); //mensaje de pantalla de total, no el total calculado
let total = 0;

//Esta función sirve para agregar el total o calcularlo
function agregarATicket() {
    //esta parte la uso para obtener los valores de los campos de texto
    let articuloTexto = articulo.value;
    let precioTexto = precio.value;


     //agrego las cosas a la lista de ticket
     let elementoLista = document.createElement("li");
     elementoLista.innerHTML=articuloTexto + "  $" + precioTexto;

     listaArticulos.appendChild(elementoLista);
     
     //las siguientes dos lineas sirven para limpiar las cajas de texto
     articulo.value="";
     precio.value="";

     //aqui calculo el precio total de los elemtos que se van agregando
     var numerico = parseInt(precioTexto); //en esta linea convierto el precio a texto
     total = total + numerico
     console.log(total);//lo imprimo en la consola

     //imprimo el total
     totalMSG.innerHTML= "Total: $" + total;

     //la siguiente linea es para mostrar la caja de texto cada que se agregue un elemento
     cajaAEliminar.style.removeProperty("display");
    }

//oculta la caja
function cerrarCaja(caja){
    cajaAEliminar.style.display = "none"; 
}