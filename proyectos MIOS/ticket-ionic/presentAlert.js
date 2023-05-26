
async function presentarAlerta() {
    const alert = document.createElement('ion-alert');
    alert.header = 'Exito'; //encabezado de la alerta
    alert.subHeader = 'Ticket de compra'; //esta linea es para crear un subtema
    alert.message = 'El elemento se ha añadido al ticket';
    alert.buttons = ['Cerrar'];//lo que quieres que se muestre para cerrar el mensaje

    document.body.appendChild(alert);
    await alert.present();
}