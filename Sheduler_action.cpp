
/**
 * @file Sheduler_action.cpp
 * @author federico.barbetti@correounivalle.edu.co
 * @brief Se implementan las funciones de la clase
 * @version 0.1
 * @date 2025-10-19
 * 
 * @copyright GNU-GPL
 * 
 */
#include "Sheduler_action.h"

Sheduler_action::Sheduler_action()
{

}

Sheduler_action::Sheduler_action(Proceso_listo *pp)
{
    listado_inicial.push_back(pp);

    gantt_diagram.push_back(pp->get_etiqueta());

}


Sheduler_action::~Sheduler_action()
{

}


void Sheduler_action::set_listado(string ubicacion_txt){
    
    ifstream lector_recolector(ubicacion_txt);          //objeto stream de lectura
    
    char simbolo_leido;                             //contenedor de cada simbolo leido
    
    std::string receptor_1, receptor_2, receptor_3, receptor_4, receptor_5;    //receptor de cadenas
    
    std::string linea_leida = "";                         //contenedor de linea leida
    
    int posicion_lectura, burst_time, arrival_time, custom_queue, assing_priority = 0;                                  //contenedor de posicion de lectura
    
    if (lector_recolector.is_open())
    {
        do
        {
            posicion_lectura=lector_recolector.tellg();         //posicion de lectura
            
            simbolo_leido=lector_recolector.get();              //actual caracter leido
            
            getline(lector_recolector, linea_leida, '\n');      //buffer lector, string receptor, limite
    
            if (!lector_recolector.fail()) 
            {
    
                if ( simbolo_leido != '#' || simbolo_leido=='\n')  // condicional
                {
                    lector_recolector.seekg(posicion_lectura, ifstream::beg);   //rectificacion de posicion de lectura inicial
                    
                    if(!linea_leida.empty() && simbolo_leido!='\0') //condicional
                    {

                        getline(lector_recolector, receptor_1,' ');
                        getline(lector_recolector, receptor_2,' ');
                        getline(lector_recolector, receptor_3,' ');
                        getline(lector_recolector, receptor_4,' ');
                        getline(lector_recolector, receptor_5,'\n');
                        
                        //creando objetos

                        Proceso_listo *pp;
                        pp = new Proceso_listo();
                        
                        if (receptor_1 != "")
                        {
                            receptor_1.pop_back();
                            pp->set_etiqueta(receptor_1);
                            burst_time = stoi(receptor_2);
                            pp->set_bt(burst_time);
                            arrival_time = stoi(receptor_3);
                            pp->set_at(arrival_time);
                            custom_queue = stoi(receptor_4);
                            pp->set_quew(custom_queue);
                            assing_priority = stoi(receptor_5);
                            pp->set_prior(assing_priority);

                        }

                        listado_inicial.push_back(pp); // adicionando objetos
                        
                    }
                
                }
                    
            }
            
        } while (!lector_recolector.fail());
        
    }
    lector_recolector.close();

};

void Sheduler_action::set_gantt_diagram(Proceso_listo *prc){

    int auxiliar = 0;

    while (prc->get_bt()>0)
    {
        gantt_diagram.push_back(prc->get_etiqueta());
        auxiliar = prc->get_bt();
        auxiliar --;
        prc->set_bt(auxiliar);
    }
    
};


void Sheduler_action::set_waiting_time(int dato_computado){

    waiting_time = dato_computado;

};

// desde aqui falta

void Sheduler_action::set_response_time(int rtt){

    response_time = rtt;

}

void Sheduler_action::set_tiempo_completado(int tcc){

    tiempo_completado = tcc;
}

void Sheduler_action::set_turnArounTime(int ta){

    turnArounTime = ta;
}

void Sheduler_action::set_priority(int pri){
    
    priority_p = pri;

}


vector<Proceso_listo*> Sheduler_action::get_listado(){

    for (auto elemt : listado_inicial)  // verificacion con las etiquetas
    {
        elemt->mostrar_proceso();
    }
    return listado_inicial;
};


vector<string> Sheduler_action::get_gantt_diagram(){

    int auxiliar = 0; // auxiliar para mostrar
    
    for (auto str : gantt_diagram) // mostrar internamente 
    {
        cout<<"Posicion [" + to_string(auxiliar) +  "] " + str<<endl;
                auxiliar++;
    }
    
    return gantt_diagram;
};


int Sheduler_action::get_waiting_time(){

    return waiting_time;

};


int Sheduler_action::get_response_time(){

    return response_time;

};

int Sheduler_action::get_tiempo_completado(){

    return tiempo_completado;
};

int Sheduler_action::get_turnArounTime(){

    return turnArounTime;
};

int Sheduler_action::get_priority_P(){

    return priority_p;
};


// funciones auxiliares



int Sheduler_action::calcula_waiting_time(Proceso_listo *indagado){

    int ultima_vez = 0;
    int *ph = &ultima_vez;
    int total_wt = 0;
    int *tt = &total_wt;


    if (gantt_diagram.empty()==false)//hay datos
    {

        for (int i =0; i < gantt_diagram.size(); i++)
        {
            if (gantt_diagram[i]!=indagado->get_etiqueta())
            {
                total_wt ++; // suma cada vez que no es igual
            }
            else
            {
                ultima_vez = i;//ultima posicion que si es igual
            }
            
        }
        
    }
    else{

        cout<<" no hay datos a procesar ... FAVOR VERIFICAR...gracias "<<endl;
    }

    total_wt -= (gantt_diagram.size()-ultima_vez-1); // se eliminan la suma de las posiciones posteriores a la ultima conindidencia

    cout<<"El total del Waiting Time es: " + to_string(total_wt)<<endl;

    return total_wt;
    

};    


int Sheduler_action::calcula_response_time(Proceso_listo *indagado){

    int response_time_p = 0;
    int *tt = &response_time_p;

    if (gantt_diagram.empty()==false)
    {
        for (int i =0; i < gantt_diagram.size(); i++)
        {
            if (gantt_diagram[i]==indagado->get_etiqueta())
            {
                response_time_p=i;
                break;
            }
            
        }
        
    }
    else{

        cout<<" no hay datos a procesar ... FAVOR VERIFICAR...gracias "<<endl;
    }

    cout<<"El response Time es: " + to_string(response_time_p)<<endl;

    return response_time_p;
    
    

};    



int Sheduler_action::calcula_tiempo_completado(Proceso_listo *indagado){

    int tiempo_completado = 0;
    int *tt = &tiempo_completado;


    if (gantt_diagram.empty()==false)//hay datos
    {

        for (int i =0; i < gantt_diagram.size(); i++)
        {
            if (gantt_diagram[i]==indagado->get_etiqueta())
            {
                tiempo_completado =i; //tomara la ultima coincidencia
            }
        }
        
    }
    else{

        cout<<" no hay datos a procesar ... FAVOR VERIFICAR...gracias "<<endl;
    }

    tiempo_completado +=1; // se suma 1 por logica

    cout<<"El tiempo de completado  es: " + to_string(tiempo_completado)<<endl;

    return tiempo_completado;
    

};    


int Sheduler_action::calcula_turnAroundTime(Proceso_listo *indagado){

    int tiempo_completado = 0;
    int *tt = &tiempo_completado;
    int turn_around = 0;
    int *trn = &turn_around;


    if (gantt_diagram.empty()==false)//hay datos
    {

        for (int i =0; i < gantt_diagram.size(); i++)
        {
            if (gantt_diagram[i]==indagado->get_etiqueta())
            {
                tiempo_completado =i; //tomara la ultima coincidencia
            }
        }
        
    }
    else{

        cout<<" no hay datos a procesar ... FAVOR VERIFICAR...gracias "<<endl;
    }

    turn_around = (tiempo_completado + 1) - indagado->get_at(); // se suma 1 por logica

    cout<<"El turnArounTime  es: " + to_string(turn_around)<<endl;

    return turn_around;
    

};    











int Sheduler_action::calcula_wt_alternativo(string indagado, vector<string>vec){

    int ultima_vez = 0;
    int *ph = &ultima_vez;
    int total_wt = 0;
    int *tt = &total_wt;

    if (vec.empty()==false)
    {
        for (int i =0; i < vec.size(); i++)
        {
            if (vec[i]!=indagado)
            {
                total_wt ++;
            }
            else
            {
                ultima_vez = i;                
            }            
            
        }
        
    }
    else{

        cout<<" no hay datos a procesar ... FAVOR VERIFICAR...gracias "<<endl;
    }

    total_wt -= (vec.size()-ultima_vez-1);

    cout<<"El total del Waiting Time es: " + to_string(total_wt)<<endl;

    return total_wt;
    

};    


int Sheduler_action::response_time_alternativo(string indagado, vector<string>vec){

    int response_time_p = 0;
    int *tt = &response_time_p;

    if (vec.empty()==false)
    {
        for (int i =0; i < vec.size(); i++)
        {
            if (vec[i]==indagado)
            {
                response_time_p=i;
                break;
            }
            
        }
        
    }
    else{

        cout<<" no hay datos a procesar ... FAVOR VERIFICAR...gracias "<<endl;
    }

    cout<<"El response Time es: " + to_string(response_time_p)<<endl;

    return response_time_p;
    

};    



int Sheduler_action::calcula_tiempoCompletado_alternativo(string indagado, vector<string>vec){

    int tiempo_completado = 0;
    int *tt = &tiempo_completado;

    if (vec.empty()==false)
    {
        for (int i =0; i < vec.size(); i++)
        {
            if (vec[i]==indagado)
            {
                tiempo_completado = i;
            }
            
        }
        
    }
    else{

        cout<<" no hay datos a procesar ... FAVOR VERIFICAR...gracias "<<endl;
    }

    tiempo_completado +=1; // se adiciona 1 por logica

    cout<<"El tiempo de completado es: " + to_string(tiempo_completado)<<endl;

    return tiempo_completado;
    

};    



int Sheduler_action::suma_label(const string& etiqueta_p) {

    int total_suma_ascii = 0;

    for (char c : etiqueta_p) {

        total_suma_ascii += static_cast<unsigned char>(c);  // se usa unsigned para evitar valores negativos
    }

    cout<<"La suma de " + etiqueta_p + " es: "  + to_string(total_suma_ascii)<<endl;

    return total_suma_ascii;
}   



