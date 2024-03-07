#include <iostream>
#include "./Salud.cpp"

using namespace std;

int main{
    
    class Inicio{

    Persona persona1;
        persona1.pedirDatos();
        persona1.mostrarDatos();
        persona1.calcularIMC();
        persona1.esMayorDeEdad();

        return  0;

    }
}


