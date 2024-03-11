#include <iostream>
#include "../Persona.cpp"

using namespace std;

class Inicio{
    public: 
    inicio(){}:
    void init();
};
    void Inicio::init(){
        Persona persona1;
        persona1.pedirDatos();
        persona1.mostrarDatos();
        persona1.calcularIMC();
        persona1.esMayorDeEdad();
        cout << "¿Es mayor de edad?" << (persona.mayorEdad() ? "Si" : "No") << endl;
}
    
int main{
    
}

