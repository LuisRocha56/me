function ingresar(){
    var usuario = document.getElementById("cajausuario").value; 
    var contraseña = document.getElementById("cajacontra").value;

    if(usuario== "luis" && contraseña == "1234")
    {
        alert("Usuario y contraseña correctos");
        document.getElementById("resultado").value;
    } else {
        alert("Usuario y contraseña incorrectos");
    }
    
}

function registro(){
    var usuario = document.getElementById("cajausuario").value; 
    var contraseña = document.getElementById("cajacontra").value;

    if(usuario== "luis" && contraseña == "1234")
    {
        alert("Usuario y contraseña correctos") + usuario;
    } else {
        alert("Usuario y contraseña incorrectos");
    }
}

function mostrar() {
    var tipo = document.getElementById("cajacontra");
    if(tipo.type == "password"){
        tipo.type = "text";
    }else{
        tipo.type = "password";
    }
}

/*function mostrar() {
    var tipo = document.getElementById("cajacontra");
    if(passwordtxt.type == 'password'){
        passwordtxt.type == 'text';
        boton.textContent = "ocultar contraseña";
    } else {
        passwordtxt.type == 'text';
        boton.textContent = "ocultar contraseña";
    }
}*/
