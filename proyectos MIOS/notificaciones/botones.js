function cerrarCajaVerde(){
    //Si existe la caja o el div...
    var div = document.getElementById('div');
    if(div !== null){
        while (div.hasChildNodes()){
            div.removeChild(div.lastChild);
        }
    }else{
        alert ("cerrar caja verde");
    }
}

function cerrarCajaAmarillo(){
    //Si existe la caja o el div...
    var div = document.getElementById('div');
    if(div !== null){
        while (div.hasChildNodes()){
            div.removeChild(div.lastChild);
        }
    }else{
        alert ("cerrar caja Amarilla");
    }
}

function cerrarCajaRoja(){
    //Si existe la caja o el div...
    var div = document.getElementById('div');
    if(div !== null){
        while (div.hasChildNodes()){
            div.removeChild(div.lastChild);
        }
    }else{
        alert ("cerrar caja Roja");
    }
}