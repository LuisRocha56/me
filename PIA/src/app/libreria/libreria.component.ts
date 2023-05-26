import { Component, OnInit } from '@angular/core';
import { AlbumService } from '../album.service';

@Component({
  selector: 'app-libreria',
  templateUrl: './libreria.component.html',
  styleUrls: ['./libreria.component.scss'],
})
export class LibreriaComponent  implements OnInit {
  al: any[] = []
  constructor(
    private album : AlbumService
  ) { }

  ngOnInit(): void { 
    //Nos trae los album creados
  this.album.getalbum().then(()=>{
    this.al = this.album.album
  console.log(this.al)
  })
  }

}
