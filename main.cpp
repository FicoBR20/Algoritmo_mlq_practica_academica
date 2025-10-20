/**
 * @file main.cpp
 * @author federico.barbetti@correounivalle.edu.co
 * @brief funcion primcipal en donde se ejecuta la simulacion
 * del algoritmo mlq con las 3 colas sugeridas.
 * @version 0.1
 * @date 2025-10-19
 * 
 * @copyright GNU-GPL
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<sstream>


#include "Sheduler_action.h"

using namespace std;


int main(int argc, char const *argv[])
{
    
    //recurso de datos

    vector<Proceso_listo*>probador;
    
    string datos_txt = "/home/fede/Documents/2025-2-Univalle/Sistemas_OPerativos_2025-2/Primer_Parcial/mlq_Algoritmo/datos_profe/mlq019.txt";
    
    Sheduler_action sh;

    sh.set_listado(datos_txt);

    probador=sh.get_listado();//retorna un vector de punteros

    //probabdor de funciones

    int waitin, resptim, tiempoCom, sumalabel = 0;

    vector<string> vector7 = {"G", "A", "A", "A", "A", "A", "X"};

    vector<string> vector12 = {"H", "I", "P", "A", "L", "M", "A", "O", "K", "A", "R", "S"};


    waitin = sh.calcula_wt_alternativo("A", vector12);
    resptim = sh.response_time_alternativo("A", vector12);
    tiempoCom = sh.calcula_tiempoCompletado_alternativo("A", vector7);
    sumalabel = sh.suma_label(probador[0]->get_etiqueta());

    
    // limpieza de memoria

    cout<<"Gracias a Dios"<<endl;


    

    
    return 0;
}
