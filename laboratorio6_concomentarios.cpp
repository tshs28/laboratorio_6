#include <iostream>
#include <string>
using namespace std;

// Clase que representa una cuenta bancaria
class CuentaBancaria {
private:
    string titular; // Nombre del titular de la cuenta
    double saldo; // Saldo actual de la cuenta
    bool activa; // Estado de la cuenta (activa o bloqueada)
    int intentosFallidos; // Contador de intentos fallidos de retiro
    int mesesInactivo; // Contador de meses sin uso (para simular inactividad)

public:
    // Constructor que inicializa la cuenta con nombre y saldo inicial
    CuentaBancaria(string nombre, double saldoInicial) {
        titular = nombre;
        saldo = saldoInicial;
        activa = true;
        intentosFallidos = 0;
        mesesInactivo = 0;
    }

    // Método para realizar un depósito en la cuenta
    void depositar(double monto) {
        if (!activa) {
            cout << "No se pueden hacer depósitos, la cuenta está bloqueada.\n";
            return;
        }
        if (monto <= 0) {
            cout << "No se pueden hacer transacciones con montos negativos o cero.\n";
            return;
        }
        saldo += monto;
        cout << "Depósito exitoso. Nuevo saldo: " << saldo << "\n";
    }

    // Método para realizar un retiro de la cuenta
    void retirar(double monto) {
        if (!activa) {
            cout << "No se pueden hacer retiros, la cuenta está bloqueada.\n";
            return;
        }
        if (monto <= 0) {
            cout << "No se pueden hacer transacciones con montos negativos o cero.\n";
            return;
        }
        if (monto > saldo) {
            intentosFallidos++;
            cout << "Saldo insuficiente. Intento fallido #" << intentosFallidos << "\n";
            if (intentosFallidos >= 3) {
                activa = false;
                cout << "La cuenta ha sido bloqueada por intentos fallidos.\n";
            }
            return;
        }
        saldo -= monto;
        cout << "Retiro exitoso. Nuevo saldo: " << saldo << "\n";
    }

    // Método para consultar el saldo y el estado de la cuenta
    void consultarSaldo() {
        cout << "Titular: " << titular << "\nSaldo: " << saldo << "\nEstado: " << (activa ? "Activa" : "Bloqueada") << "\n";
    }
};

int main() {
    string nombre;
    double saldoInicial;
    int opcion;

    // Se solicita el nombre y el saldo inicial al usuario
    cout << "Ingrese el nombre del titular: ";
    getline(cin, nombre);
    cout << "Ingrese el saldo inicial: ";
    cin >> saldoInicial;
    CuentaBancaria cuenta(nombre, saldoInicial);

    // Menú de opciones para interactuar con la cuenta
    do {
        cout << "--- Menú ---\n1. Depositar\n2. Retirar\n3. Consultar Saldo\n4. Salir\nSeleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
        case 1: {
            double monto;
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            cuenta.depositar(monto);
            break;
        }
        case 2: {
            double monto;
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            cuenta.retirar(monto);
            break;
        }
        case 3:
            cuenta.consultarSaldo();
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}

/*
Resumen de lo aprendido:
Este laboratorio me ayudó a reforzar el uso de clases en C++, aplicando atributos y métodos para simular una cuenta bancaria.
Además, comprendí mejor la importancia de las estructuras condicionales como if-else y switch-case para controlar el flujo del programa.

Comentarios personales:
Me pareció interesante ver cómo se pueden implementar reglas en un sistema bancario básico. Al principio, fue un reto decidir qué condiciones usar, pero al final logré integrarlas correctamente.
También aprendí lo importante que es validar la entrada del usuario para evitar errores en las transacciones. Creo que con más tiempo podría mejorar la interfaz y agregar más funcionalidades.
*/
