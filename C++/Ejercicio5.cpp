#include <iostream>

using namespace std;

int main() {
    int saldoUsuario = 500;
    int b20 = 10, b10 = 10, b5 = 10, b1 = 10;
    int totalCajero = (b20 * 20) + (b10 * 10) + (b5 * 5) + b1;

    int monto, faltante;
    int e20 = 0, e10 = 0, e5 = 0, e1 = 0;

    cout << "=== CAJERO AUTOMATICO ===\n";
    cout << "Su saldo actual es: " << saldoUsuario << "\n";
    cout << "Ingrese el monto a retirar: ";
    cin >> monto;

    if (monto <= 0) {
        cout << "El monto debe ser positivo \n";
    }
    else if (monto > saldoUsuario) {
        cout << "Saldo insuficiente en su cuenta \n";
    }
    else if (monto > totalCajero) {
        cout << "El cajero no tiene suficiente efectivo total \n";
    }
    else {
        faltante = monto;

        e20 = faltante / 20;
        if (e20 > b20) e20 = b20;
        faltante = faltante - (e20 * 20);

        e10 = faltante / 10;
        if (e10 > b10) e10 = b10;
        faltante = faltante - (e10 * 10);

        e5 = faltante / 5;
        if (e5 > b5) e5 = b5;
        faltante = faltante - (e5 * 5);

        e1 = faltante / 1;
        if (e1 > b1) e1 = b1;
        faltante = faltante - (e1 * 1);

        if (faltante == 0) {
            saldoUsuario -= monto;
            totalCajero -= monto;

            cout << "\n=== TRANSACCION CAJERO ===\n";
            cout << "Billetes entregados:\n";
            cout << "Billetes de $20: " << e20 << "\n";
            cout << "Billetes de $10: " << e10 << "\n";
            cout << "Billetes de $5:  " << e5 << "\n";
            cout << "Billetes de $1:  " << e1 << "\n";
            cout << "Su saldo restante: $" << saldoUsuario << "\n";
            cout << "Efectivo restante en cajero: " << totalCajero << "\n";
        } else {
            cout << "\nEl cajero no dispone de la denominacion exacta para este monto\n";
        }
    }

    return 0;
}
