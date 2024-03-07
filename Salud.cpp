#include <iostream>
#include <string>

using namespace std;

class Persona
{
public:
    string tipoDoc;
    int documento;
    string nombre;
    string apellido;
    int peso;
    int estatura;
    int edad;
    string sexo;

    Persona() {} // Constructor vacío
    
    // Declaración de funciones
    void pedirDatos();
    void mostrarDatos();
    double calcularIMC();
    bool esMayorDeEdad();
};

void Persona::pedirDatos()
{
    cout << "Ingrese su tipo de documento: ";
    cin >> tipoDoc;
    cout << "Ingrese su numero de documento: ";
    cin >> documento;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su apellido: ";
    cin >> apellido;
    cout << "Ingrese su peso en kilogramos: ";
    cin >> peso;
    cout << "Ingrese su estatura en metros: ";
    cin >> estatura;
    cout << "Ingrese su edad en años: ";
    cin >> edad;
    cout << "Ingrese su sexo: ";
    cin >> sexo;
}
    Persona persona1;

void Persona::mostrarDatos()
{
    cout << "Su tipo de documento es: " << persona1.tipoDoc << endl;
    cout << "Su numero de documento es: " << persona1.documento << endl;
    cout << "Su nombre es: " << persona1.nombre << endl;
    cout << "Su apellido es: " << persona1.apellido << endl;
    cout << "Su peso en kilogramos es: " << persona1.peso << endl;
    cout << "Su estatura en metros es: " << persona1.estatura << endl;
    cout << "Su edad en años es: " << persona1.edad << endl;
    cout << "Su sexo es: " << persona1.sexo << endl;
}

double Persona::calcularIMC()
{
    double pesoActual = peso / (estatura * estatura);
    if (pesoActual < 20)
    {
        cout << "El peso esta por debajo de lo ideal" << endl;
    }
    else if (pesoActual >= 20 && pesoActual <= 25)
    {
        cout << "El peso es ideal" << endl;
    }
    else if (pesoActual > 25)
    {
        cout << "Usted tiene Sobrepeso" << endl;
    }
    return pesoActual;
}

bool Persona::esMayorDeEdad()
{
    if (edad >= 18)
    {
        cout << "Usted es mayor de edad" << endl;
        return true;
    }
    return false;
}

int main()
{   Persona persona1;
    persona1.pedirDatos();
    persona1.mostrarDatos();
    persona1.calcularIMC();
    persona1.esMayorDeEdad();

    return 0;
}
