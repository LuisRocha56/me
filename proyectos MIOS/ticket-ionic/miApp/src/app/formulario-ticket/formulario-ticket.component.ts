import { Component , OnInit} from '@angular/core';

@Component({
  selector: 'app-formulario-ticket',
  templateUrl: './formulario-ticket.component.html',
  styleUrls: ['./formulario-ticket.component.css']
})
export class FormularioTicketComponent implements OnInit {
  constructor() {}

  ngOnInit(): void {
    
  }

  mensaje: string = "Hola mundo";

  hola: string = "No platiquen en clase";

  total: number = 0;



  calcularTotal() {
    //algo aqui
  }

}
