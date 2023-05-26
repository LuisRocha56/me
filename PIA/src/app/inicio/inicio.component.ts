import { Component, OnInit } from '@angular/core';
import { Component, OnInit } from '@angular/core';
import { AutService } from '../service/aut.service';
import { Router } from '@angular/router';
//import { User } from '../user';
//import { MenuServiceService } from '../service/menu-service.service';
import { FormBuilder, FormGroup, Validators, FormControl, AbstractControl } from '@angular/forms';

@Component({
  selector: 'app-inicio',
  templateUrl: './inicio.component.html',
  styleUrls: ['./inicio.component.scss'],
})

export class RegisterComponent implements OnInit{
  //Se crean las variables necesarias y un objeto del tipo usuario
  //user: User = new User();
  name:string = "";
  formRegister : any;

  constructor(
    //private autSvc: AutService,
    private router: Router,
    //private menuService: MenuServiceService,
    private formBuilder: FormBuilder,
    //private modalCtrl: ModalController
  ) { }
}

export class InicioComponent  implements OnInit {

  constructor() { }

  ngOnInit() {}

}
