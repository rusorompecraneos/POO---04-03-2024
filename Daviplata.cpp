#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>

using namespace std;

class Daviplata {

    private:
    int opcion,contadorIntentos = 3;
    float saldoCuenta = 0, valor = 0, bolsillo = 0, valorBolsillo, valorRetiro;
    string clavesRegistradas[10] = {"1234","0000","9090", "6666"};
    string usuariosRegistrados[10] = {"3242101297","3166421209","3044398114"};
    string clave , usuario;
    list <string> movimientosTipo;
    list <float> movimientosValor;
    

    public:
    Daviplata(){};


    float getSaldoCuenta1(){
        return saldoCuenta;
    }
    
    float getValor(){
        return valor;
    }

    float getValorBolsillo(){
        return bolsillo;
    }
    
    float getValorRetiro(){
        return valorRetiro;
    }

    bool accesoAplicacion(){

        while( contadorIntentos > 0){
            
            cout << "Ingrese su usuario: " << endl;
            cin >> usuario;

            cout << "Ingrese su clave: " << endl;
            cin >> clave;
            
            for (int i = 0; i < 10; i++){
                
                if (clave == clavesRegistradas[i] && usuario == usuariosRegistrados[i]){
                    return true;
                }                

            }
            contadorIntentos--;

        }
    
     cout << "Clave o usuario incorrectos" << endl;
            cout << "Ingrese un usuario y clave validos" << endl;
            cout << "Tiene " << contadorIntentos << " intentos mas" << endl;
            return false;
    }


    string recarga(){

        int numeroCuenta, cedula, opcionBanco;
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
                cin >> numeroCuenta;
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
                cout << "Bienvenido a recagar con efectivo\n" << endl;
                cout << "Dirigase al corresponsal mas cercano,\n" << endl;
                cout << "los podra encontrar en el siguiente link\n: " << endl;
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
                    cin >> opcionBanco;
                    if(opcionBanco > 0 && opcionBanco < 6){
                        opcionBanco -= 1;
                        cout << "Ingrese el numero de cuenta para su banco: " << endl;
                        cin >> numeroCuenta;
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
                    cout << "Ingrese el valor que desea recargar  " << endl;
                    cin >> valor;
                    if(valor <= 0){
                        cout << "Por favor ingrese un valor valido" << endl;
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

    
    void sacarPlata (){

        srand(time(NULL));

        int opcion1, aleatorio;
        aleatorio = 100000+rand()%(999999+1-100000);

        cout << "Opciones para retirar " << endl;
        cout << "1. Para cajero bancolombia" << endl;
        cout << "2. Para punto fisico (Corresponsales y puntos nequi)" << endl;
        cout << "3. Para conocer los lugares de retiro " << endl;   
        cin >> opcion1;
    
        if (opcion1 == 1 || opcion1 == 2){
            cout << "De donde desea que saga la plata? " << endl;
            cout << "1. Disponible " << endl << "2. Bolsillo " << endl;
            cin >> opcion;
            if (opcion == 1){
                cout << "Cuanto desea sacar? " << endl;
                cin >> valorRetiro;
                while(valorRetiro > saldoCuenta){
                    cout << "Ingrese un valor valido" << endl;
                    cin >> valorRetiro;
                    if (valorRetiro <= saldoCuenta){
                        break;
                    }
                }
                saldoCuenta -= valorRetiro;
                cout << "Su codigo para retirar es: " << aleatorio << endl;

            }
            if (opcion == 2){
                cout << "¿Cuanto desea retirar de su cuenta?" << endl;
                cin >> valorRetiro;
                while(valorRetiro > bolsillo){
                    cout << "Ingrese un valor valido por favor " << endl;
                    cin >> valorRetiro;
                    if (valorRetiro <= bolsillo){
                        break;
                    }
                }
                bolsillo -= valorRetiro;
                cout << "El codigo para retirar es: " << aleatorio << endl;
                cout << "su nuevo saldo en bolsillo es " << bolsillo << endl;
            }

        }
        else if (opcion1 == 3){   
            cout << "Dirijase a la siguiente direccion para gestionar su solicitud" << endl;
            cout << "https://www.bancolombia.com/puntos-de-atencion/buscar-en-mapa";
        }
    
    }

    void bolsillo(){
        
        string nombreBolsillo;

        cout << "Crea tu primer bolsillo " << endl;

        cout << "Nombre del bolsillo " << endl;
        cin >> nombreBolsillo;

        while (true)
        {   
            cout << "¿Cuanto deseas almacenar en tu bolsillo?: " << nombreBolsillo << endl;
            cout << "1. para salir" << endl;
            cin >> valorBolsillo;
            
            if(valorBolsillo > saldoCuenta || valorBolsillo < 0 ){
                cout << "Ingrese un valor valido" << endl;
                ;
            }
            else if(valor == 1){
                break;
            }
            else if (valorBolsillo < saldoCuenta ){
                bolsillo = valorBolsillo;
                saldoCuenta -= valorBolsillo;
                break;
            }
        }

    }
    
    
    

    void imprimirMovimientoTipo(){

        for(const auto & Tipo: movimientosTipo){
            cout << Tipo << " " ;
        }
    }

    void agregarMovimientoTipo(string tipo) {
        

        movimientosTipo.push_back(tipo);

        
        if (movimientosTipo.size() > 3) {
            movimientosTipo.pop_front();
        }
    }

    

        };
        


