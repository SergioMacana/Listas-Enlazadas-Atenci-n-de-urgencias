#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Consultorio{
  private: 
  class Paciente{
    public:
    string nombre;
    string edad;
    string genero;
    Paciente* siguiente;
  };
  
  public:
  Paciente* raiz;
    Consultorio();
    ~Consultorio();
    void AgregarPaciente(string nombre, string edad, string genero);
    void EliminarPaciente(string nombre);
    void AtenderPacientes();
    void MostrarPacientes();
};

Consultorio::Consultorio(){
  raiz = NULL;
}

Consultorio::~Consultorio(){
  Paciente* recorrido=raiz;
  Paciente* borrar;
  while(recorrido!=NULL){
    borrar=recorrido;
    recorrido=recorrido->siguiente;
    delete borrar;
  }
}
void Consultorio::AgregarPaciente(string nombre, string edad, string genero){
  Paciente* nuevo=new Paciente();
  nuevo->nombre=nombre;
  nuevo->edad=edad;
  nuevo->genero=genero;
  nuevo->siguiente=NULL;

  if(raiz==NULL){
    raiz=nuevo;
} else {
    Paciente* recorrido=raiz;
    while(recorrido->siguiente!=NULL){
      recorrido=recorrido->siguiente;
      }
  recorrido->siguiente=nuevo;
  
  }
}  
void Consultorio::EliminarPaciente(string nombre){
  if(raiz!=NULL){
    if(raiz->nombre==nombre){
      Paciente* borrar=raiz;
      raiz=raiz->siguiente;
      delete borrar;
    
    } else {
      Paciente* recorrido=raiz;
      Paciente* anterior=NULL;
      while(recorrido!=NULL && recorrido->nombre!=nombre){
        anterior=recorrido;
        recorrido=recorrido->siguiente;
  }
      if (recorrido!=NULL){
        anterior->siguiente=recorrido->siguiente;
        delete recorrido;
      }
  }
}
}


void Consultorio::AtenderPacientes(){
  if(raiz!=NULL){
    cout<<"El paciente ha sido atendido. ";
    Paciente* borrar = raiz;
    raiz = raiz->siguiente;
    delete borrar;
  }
}

void Consultorio::MostrarPacientes(){
  Paciente* recorrido=raiz;
  cout << "Lista de pacientes: ";
  while(recorrido!=NULL){
    cout <<"\nPaciente: "<< recorrido->nombre << " Edad: " << recorrido->edad << " Genero: " << recorrido->genero << "\n ";
    recorrido = recorrido->siguiente;

  }
}

int main(){
  Consultorio* consultorio = new Consultorio();
  string nombre;
  string edad;
  string genero;
  int opcion;
  bool seguir=true;
cout<<"\n///////////////////////////////Atención de Urgencias////////////////////////////\n ";
  cout<<"\n/////////////////////////Por Sara Carvajal y Sergio Macana./////////////////////////\n ";
while (seguir){
      cout<<"\n1. Agregar Paciente a sala de espera";
      cout<<"\n2. Atender Paciente.";
      cout<<"\n3. Borrar Paciente.";
      cout<<"\n4. Mostrar Pacientes";
      cout<<"\n5. Salir del programa. ";
      cout<<"\n\nIngrese una opción: ";
      cin>>opcion;
      cin.ignore();
    
    switch (opcion){
      case 1: 
        
        cout<<"\nIngrese el nombre del paciente: "<<endl;
        getline(cin, nombre);
        cout<<"\nIngrese la edad del paciente: "<<endl;
        getline(cin, edad);
        cout<<"\nIngrese el genero del paciente: "<<endl;
        getline(cin, genero);
        consultorio->AgregarPaciente(nombre, edad, genero );
        cin.ignore();
       break;
      case 2:
        if(consultorio->raiz!=NULL){
        consultorio->AtenderPacientes();
      } else {
        cout<<"\nNo hay pacientes en la sala de espera.";
      }
      break;
      case 3:
        cout<<"\nIngrese el nombre del paciente a eliminar: ";
        cin>>nombre;
        consultorio->EliminarPaciente(nombre);
        break;
      case 4:
        consultorio->MostrarPacientes();
        break;
      case 5:
        cout<<"\nSaliendo del programa...";
        seguir=false;
        break;
      default:
        cout<<"\nOpción inválida.";
    }
  }
  delete consultorio;
}