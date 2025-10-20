
/**
 * @brief Clase que representa un proceso en la cola de listos
 * se definen sus miembros.
 */
#ifndef PROCESO_LISTO_H
#define PROCESO_LISTO_H


# include<iostream>
# include<string>
# include<vector>
using namespace std;

#pragma once


/**
 * @brief Clase que representa un proceso
 * 
 */
class Proceso_listo
{
public:

    Proceso_listo();            //constructor sin parametros, inicializa atributos
    Proceso_listo(string etq);  //constructor con el parametro de la etiqueta
    ~Proceso_listo();
    
    string get_etiqueta();      //obtiene la etiqueta y la retorna
    int get_bt();               //obtiene el burstime y lo retorna
    int get_at();               //obtiene el arrival time y lo retorna
    int get_quew();             //obtiene el numero de la cola y lo retorna
    int get_prior();            //obtiene la prioridad 5>1 y la retorna

    void set_etiqueta(string etiqueta); //asigna una etiqueta
    void set_bt(int bt);                //asigna un valor para el burstime
    void set_at(int at);                //asigna un valor para el arrival time
    void set_quew(int quew);            //asigna un valor que representa la cola asignada al proceso
    void set_prior(int prior);          //asigna un valor para la prioridad

    // funciones auxiliares
    /**
     * @brief muestra los atributos de un proceso con
     * sus atributos
     * 
     */
    void mostrar_proceso();

    // Devuelve true si la prioridad de este proceso es mayor que la del otro proceso
    bool operator>(const Proceso_listo& otro)const;  // criterio de comparación

    // Devuelve true si la prioridad de este proceso es menor que la del otro proceso.
    bool operator<(const Proceso_listo& otro) const;


private:

    string etiq_prc;        // label
    int bt;                 // burst time
    int at;                 // arrival time
    int quew;               // custom queue
    int prior;              // priority
     

};

#endif