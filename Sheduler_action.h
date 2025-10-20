
/**
 * @brief Clase que representa el programador de procesos
 * en un sistema de computo, se definen sus miembros.
 */
#ifndef SHEDULER_ACTION_H
#define SHEDULER_ACTION_H

#include "Proceso_listo.h"
#include<fstream>
#include<sstream>


#pragma once

class Sheduler_action
{
public:
    Sheduler_action();
    Sheduler_action(Proceso_listo *ini); // constructor adicionando un item
    ~Sheduler_action();

    /**
     * @brief
     * Recepciona la informacion del archivo de texto
     * en un vector de punteros de la clase Puntero_listo
     * @param info_text -> direccion del archivo de texto
     * con la data inicial de los procesos.
     */
    void set_listado(string info_text);

    /**
     * @brief AQUI INTUYO VA ASOCIADA LA COLA DE PRIORIDAD
     * Toma la etiqueta de un proceso y la incluye
     * tantas veces como se determine
     * @param prc 
     */
    void set_gantt_diagram(Proceso_listo *prc);


    void set_waiting_time(int dato);     //configura el tiempo de espera de un proceso
    void set_response_time(int rt);     //configura el tiempo de respuesta de un proceso
    void set_tiempo_completado(int tc); //configuara el tiempo de completado de un proceso
    void set_turnArounTime(int tat);    //configura el tiempo de un proceso desde su primera ejecucion parcial hasta su despacho total
    void set_priority(int prio);


    /**
     * @brief 
     * Retorna un vector con el listado de procesos
     * @return vector<Proceso_listo*> 
     */
    vector<Proceso_listo*> get_listado();

    /**
     * @brief
     * Retorna un vector con las etiquetas de los procesos
     * @return vector<string> 
     */
    vector<string> get_gantt_diagram();

    int get_waiting_time();       //entrega el tiempo de espera de un proceso
    int get_response_time();        //entrega el tiempo de respuesta de un proceso
    int get_tiempo_completado();    //entrega el tiempo en que se compoleta un proceso
    int get_turnArounTime();        //entrega tiempo transcurrido entre su primera ejecucion parcial hasta su despacho total
    int get_priority_P();           //entrega la prioridad de un proceso

    //funciones auxiliares
    /**
     * @brief suma los tiempos de espera de un proceso iterando
     * sobre el diagrama de gantt basandose en la etiqueta
     * @param en_diagrama 
     * @return int 
     */
    int calcula_waiting_time(Proceso_listo *en_diagrama);


    /**
     * @brief busca la primera coincidencia entre la etiqueta de un proceso
     * dado en el diagrama de gantt, entrega su indice
     * @param en_diagrama 
     * @return int 
     */
    int calcula_response_time(Proceso_listo *en_diagrama);


    /**
     * @brief busca la ultima coincidencia entre la etiqueta del 
     * proceso y los datos del diagrama de gantt; entregando el
     * indice para su proceso.
     * 
     * @param indagado 
     * @return int 
     */
    int calcula_tiempo_completado(Proceso_listo *indagado);



    int calcula_turnAroundTime(Proceso_listo *procs);










    
    int calcula_wt_alternativo(string la_etiqueta, vector<string>datosok);

    int response_time_alternativo(string etiqu, vector<string>vec);

    int calcula_tiempoCompletado_alternativo(string tcc, vector<string>vect);


    int suma_label(const string& texto);



    // Proceso_listo* rr_3(Proceso_listo *pt);
    // Proceso_listo* rr_5(Proceso_listo *pr);
    // Proceso_listo* fcfs(Proceso_listo *pp);

private:
    vector<Proceso_listo*>listado_inicial; // estaoo original de los procesos
    vector<string>gantt_diagram;            // diagrama de ghantt
    int waiting_time;                       // tiempo de espera
    int response_time;                     // tiempo de respuesta
    int tiempo_completado;                  // tiempo en que se completa un proceso
    int turnArounTime;
    int priority_p;                       // tiempo de un proceso en cola hasta su finalizacion                

    

};

#endif