#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;
    bool activa;
    int intentosFallidos;
    int mesesInactivo;

public:
    CuentaBancaria(string nombre, double saldoInicial) {
        titular = nombre;
        saldo = saldoInicial;
        activa = true;
        intentosFallidos = 0;
        mesesInactivo = 0;
    }

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

    void consultarSaldo() {
        cout << "Titular: " << titular << "\nSaldo: " << saldo << "\nEstado: " << (activa ? "Activa" : "Bloqueada") << "\n";
    }
};

int main() {
    string nombre;
    double saldoInicial;
    int opcion;

    cout << "Ingrese el nombre del titular: ";
    getline(cin, nombre);
    cout << "Ingrese el saldo inicial: ";
    cin >> saldoInicial;
    CuentaBancaria cuenta(nombre, saldoInicial);

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
