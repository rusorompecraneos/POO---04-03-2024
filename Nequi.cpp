#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>

using namespace std;

class Nequi {
private:
    int numeroIntentos = 3;
    float saldoCuenta = 0, valor = 0, colchon = 0, bolsillo = 0, valorBolsillo, valorMeta, valorRetiro;
    vector<string> clavesRegistradas = {"1234", "4567", "7890"};
    vector<string> usuariosRegistrados = {"3214459100", "3214459300", "3214459200"};
    string clave, usuario;
    list<string> movimientosTipo;
    list<float> movimientosValor;

public:
    Nequi() = default;

    float getSaldoCuenta() { return saldoCuenta; }
    float getValor() { return valor; }
    float getValorColchon() { return colchon; }
    float getValorMeta() { return valorMeta; }
    float getValorBolsillo() { return bolsillo; }
    float getValorRetiro() { return valorRetiro; }

    bool accesoApp() {
        while (numeroIntentos > 0) {
            cout << "Ingrese su usuario: " << endl;
            cin >> usuario;
            cout << "Ingrese su clave: " << endl;
            cin >> clave;

            for (size_t i = 0; i < clavesRegistradas.size(); i++) {
                if (clave == clavesRegistradas[i] && usuario == usuariosRegistrados[i]) {
                    return true;
                }
            }
            numeroIntentos--;
            cout << "Clave o usuario incorrectos" << endl;
            cout << "Ingrese un usuario y clave validos" << endl;
            cout << "Tiene " << numeroIntentos << " intentos mas" << endl;
        }
        return false;
    }

    void colchon() {
        
    }
    string recarga() {
        
    int numCuenta, cedula, opBanco, opcion;
        string listaBancos[5] = {"1. AVVILLAS","2. BBVA","3. Colpatria","4. Davivienda","5. Itau"}, codigoRegalo;

        cout << "ingrese la opcion que desea para recargar: " << endl;
        cout << "1. Plata al toque" << endl;
        cout << "2. Con efectivo" << endl;
        cout << "3. Desde otro banco" << endl;
        cout << "4. Codigo de regalo" << endl;
        cout << "0. para retroceder" << endl;
        cin >> opcion;
        while (true)
        {              
            if(opcion == 1){
                cout << "Bienvenido a Plata al toque" << endl;
                cout << "Ingrese el numero de cuenta bancolombia: " << endl;
                cin >> numCuenta;
                cout << "Ingrese su numero de cedula: " << endl;
                cin >> cedula;
                while (true)
                {
                    cout << "Ingrese el valor a recargar: " << endl;
                    cin >> valor;
                    if(valor <= 0){
                        cout << "Ingrese un valor valido" << endl;
                    }
                    else{
                        saldoCuenta += valor;
                        return "Recarga realizada con exito";
                    }

                }
            }
            if(opcion == 2){
                cout << "Bienvenido a recagar con efectivo" << endl;
                cout << "Dirigase al corresponsal mas cercano" << endl;
                cout << "los podra encontrar en el siguiente link: " << endl;
                cout << "https://www.bancolombia.com/puntos-de-atencion/buscar-en-mapa" << endl;
                while (true)
                {
                    cout << "Ingrese el valor a recargar: " << endl;
                    cin >> valor;
                    if(valor <= 0){
                        cout << "Ingrese un valor valido" << endl;
                    }
                    else{
                        saldoCuenta += valor;
                        return "Recarga realizada con exito";
                    }

                }

            }
            if(opcion == 3){
                
                cout << "Bienvenido a recarga desde otro banco" << endl;
                cout << "Eliga el banco que desea: " << endl;
                for (int i = 0; i < 5; i++)
                {
                    cout << listaBancos[i] << endl;
                }
                while (true){
                    cin >> opBanco;
                    if(opBanco > 0 && opBanco < 6){
                        opBanco -= 1;
                        cout << "Ingrese el numero de cuenta para su banco: " << endl;
                        cin >> numCuenta;
                        cout << "Ingrese su numero de cedula: " << endl;
                        cin >> cedula;
                        while (true)
                        {
                            cout << "Ingrese el valor a recargar: " << endl;
                            cin >> valor;
                            if(valor <= 0){
                                cout << "Ingrese un valor valido" << endl;
                            }
                            else{
                                saldoCuenta += valor;
                                return "Recarga realizada con exito";
                            }

                        }
                    }
                    else{
                        cout << "Ingrese una opcion valida " << endl;
                        break;
                    }
                }

            }
            if(opcion == 4){
                cout << "Bienvenido a codigo de regalo" << endl;
                cout << "Ingrese el codigo de regalo" << endl;
                cin >> codigoRegalo;
                while (true)
                {
                    cout << "Ingrese el valor a recargar: " << endl;
                    cin >> valor;
                    if(valor <= 0){
                        cout << "Ingrese un valor valido" << endl;
                    }
                    else{
                        saldoCuenta += valor;
                        return "Recarga realizada con exito";
                    }

                }
                
            }
            if(opcion == 0){

                return "";
                
            }
            else{
                cout << "ingrese una opcion valida" << endl;
            }
        }


        return "";
    }
        

    void meta() {
        string nombreMeta, valorMeta;
        float valorCuota;
        int dia, mes, anio,cuotas;

        cout << "Crea tu meta" << endl;

        cout << "Ingresa el nombre de la meta:" << endl;
        cin >> nombreMeta;

        cout << "Ingresa el valor de tu meta: " << endl;
        cin >> valorMeta;

        cout << "Cuando quieres lograrlo? " << endl;
        cout << "El dia: ";
        cin >> dia;
        cout << "El mes: ";
        cin >> mes;
        cout << "El año: ";
        cin >> anio;
        cout << "A cuantas cuotas desea la meta?" << endl;
        cin >> cuotas;
        valorCuota = valorMeta / cuotas;
        cout << "Las cuotas serian de " << valorCuota << endl;
        while (true){
            cout << "Desea descontar del disponible? 1. si / 2.no";
            cin >> opcion;
            if(opcion == 1){
                
                if(valorCuota > saldoCuenta){
                    cout << "Es imposible descontar del disponible " << endl;
                    break;
                }
                else if(valorCuota < saldoCuenta){
                    cout << "Se descontaron " << valorCuota << "del disponible " << endl;
                    break;
                }
            }
            if(opcion == 2){
                cout << "Tu bolsillo ha sido creado" << endl;
            }
            else{
                cout << "Por favor ingrese una opcion valida " << endl;
                break;
            }
        }
    }

    void bolsillo() {
        
    }

    void sacarPlata() {
        
    }

    void agregarMovimientoTipo(string tipo) {
        movimientosTipo.push_back(tipo);
        if (movimientosTipo.size() > 3) {
            movimientosTipo.pop_front();
        }
    }

    void agregarMovimientoValor(float monto) {
        movimientosValor.push_back(monto);
        if (movimientosValor.size() > 3) {
            movimientosValor.pop_front();
        }
    }
};

