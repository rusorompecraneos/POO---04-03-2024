#include <iostream>
#include <string>

using namespace std;

class Persona
{
// Atributos pblicos
private:
    string tipoDoc;
    int documento;
    string nombre;
    string apellido;
    int peso, estatura, edad;
    string sexo;

    public:
    Persona() {} // Constructor vacío

    // Hacemos todos los set
    void settipoDoc(string tipoDoc){
        this -> tipoDoc = tipoDoc;
    }
    void setdocumento(int documento){
        this -> documento = documento;
    }
    void setnombre(string nombre){
        this -> nombre = nombre;
    }
    void setapellido(string apellido){
        this -> apellido = apellido;
    }
    void setpeso(int peso){
        this -> peso = peso;
    }
    void setestatura(int estatura){
        this -> estatura = estatura;
    }
    void setedad(int edad){
        this -> edad = edad; 
    }
    void setsexo(string sexo){
        this -> sexo = sexo;
    }

    // Hacemos todos los get.
    string gettipoDoc(){
        return tipoDoc;
    }
    int getdocumento(){
        return documento;
    }
    string getnombre(){
        return nombre;
    }
    string getapellido(){
        return apellido;
    }
    int getpeso(){
        return peso;
    }
    int getestatura(){
        return estatura;
    }
    int getedad(){
        return edad;
    }
    string getsexo(){
        return sexo;
    }
    
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

class Empleado : Persona{
    Persona user1;

    // Atributos de la sub-clase.
    public:
    string cargo;
    string departamento;
    int valorHora;
    float horasTrabajadas;

    // Metodos de la sub-clase.
    public:
    void Empleado :: pedirDatos(){
        cout << "Ingrese su cargo " << endl;
        cin >> cargo;
        cout << "Ingrese su departamento " << endl;
        cin >> departamento;
        cout << "Ingrese el valor por hora " << endl;
        cin >> valorHora;
        cout << "Ingrese las horas trabajadas " << endl;
        cin >> horasTrabajadas;
    }

     void Empleado :: mostrarDatos(){
        cout << "Su tipo de documento es " << user1.gettipoDoc() << endl;
        cout << "Su documento es " << user1.getdocumento() << endl;
        cout << "Su nombre es " << user1.getnombre() << endl;
        cout << "Su apellido es " << user1.getapellido() << endl;
        cout << "Su peso es " << user1.getpeso() << endl;
        cout << "Su estatura es " << user1.getestatura() << endl;
        cout << "Su edad es " << user1.getedad() << endl;
        cout << "Su sexo es " << user1.getsexo() << endl;
        cout << "Su cargo es " << cargo << endl;
        cout << "Su departamento es " << departamento << endl;
        cout << "El valor por sus horas trabajadas son " << valorHora << endl;
        cout << "Sus horas trabajadas son " << horasTrabajadas <<  endl; 
     }

     void CalcularHonorarios(){
        double honorarios = (valorHora*horasTrabajadas);
        double reitica = (honorarios* 0.966)/100;
        double honorariosReales = honorarios - reitica;
     }

};


int main()
{   Persona persona1;
    persona1.pedirDatos();
    persona1.mostrarDatos();
    persona1.calcularIMC();
    persona1.esMayorDeEdad();

    return 0;
}
