import { Component, NgModule } from '@angular/core';
import { PreloadAllModules, RouterModule, Routes } from '@angular/router';
import { InicioComponent } from './inicio/inicio.component';
import { LoginComponent } from './login/login.component';
import { PerfilComponent } from './perfil/perfil.component';
import { BusquedaComponent } from './busqueda/busqueda.component';
import { Page404Component } from './page404/page404.component';
import { HomeinicioComponent } from './homeinicio/homeinicio.component';
import { LibreriaComponent } from './libreria/libreria.component';

const routes: Routes = [
  //{path: 'libreria/:nombre', component}, 
  {path: 'home',loadChildren: () => import('./home/home.module').then( m => m.HomePageModule)},
  {path: '', redirectTo: 'home', pathMatch: 'full'},
  {path: 'inicio',component: InicioComponent},
  {path: 'login',component: LoginComponent},
  {path: 'perfil',component: PerfilComponent},
  {path: 'busqueda',component: BusquedaComponent},
  {path: 'homeinicio', component: HomeinicioComponent},
  {path: 'busqueda', component: BusquedaComponent},
  {path: 'libreria', component: LibreriaComponent},
  
  {path: '**', component: Page404Component}
  
];

@NgModule({
  imports: [
    RouterModule.forRoot(routes, { preloadingStrategy: PreloadAllModules })
  ],
  exports: [RouterModule]
})
export class AppRoutingModule { }
