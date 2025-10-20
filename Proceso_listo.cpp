
/**
 * @file Proceso_listo.cpp
 * @author federico.barbetti@correounivalle.edu.co
 * @brief implementacion de las funciones de la clase
 * @version 0.1
 * @date 2025-10-19
 * 
 * @copyright GNU-GPL
 * 
 */
#include "Proceso_listo.h"


/**
 * @brief Construct a new Proceso_listo::Proceso_listo object
 * inicializa sus atributos
 */
Proceso_listo::Proceso_listo()
{
    etiq_prc = "";
    bt=0;
    at=0;
    quew=0;
    prior=0;

}

/**
 * @brief Construct a new Proceso_listo::Proceso_listo object
 * construye un objeto con solo la etiqueta
 * @param etq 
 */
Proceso_listo::Proceso_listo(string etq)
{
    this -> etiq_prc = etq;
}

/**
 * @brief Destroy the Proceso_listo::Proceso_listo object
 * 
 */
Proceso_listo::~Proceso_listo()
{
    cout<<"object destroy"<<endl;
}

string Proceso_listo::get_etiqueta(){
    return etiq_prc;
};
int Proceso_listo::get_bt(){
    return bt;
};
int Proceso_listo::get_at(){
    return at;
};
int Proceso_listo::get_quew(){
    return quew;
};
int Proceso_listo::get_prior(){
    return prior;
};

void Proceso_listo::set_etiqueta(string etiw){
    etiq_prc = etiw;
}
void Proceso_listo::set_bt(int bbb){
    bt=bbb;
};
void Proceso_listo::set_at(int att){
    at=att;
};
void Proceso_listo::set_quew(int qqw){
    quew=qqw;
};
void Proceso_listo::set_prior(int pprr){
    prior=pprr;
};










//============================================

// funciones auxiliares

/**
 * @brief f
 * muestra atributos de un proceso
 * 
 */
void Proceso_listo::mostrar_proceso(){

    cout<<get_etiqueta() + " " + to_string(get_bt()) + " " + to_string(get_at()) + " " + to_string(get_quew()) + " " + to_string(get_prior()) <<endl;

    
};

bool Proceso_listo::operator>(const Proceso_listo& otro)const{
    return prior > otro.prior;  // criterio de comparación
}

bool Proceso_listo::operator<(const Proceso_listo& otro)const{
    return prior > otro.prior;  // criterio de comparación
}








