#include <iostream>

using namespace std;

int main() {
    int hojas;
    char color, nocturno, anillado, rol;
    float precioHoja = 0, subtotal = 0, descuento = 0, recargo = 0, valorAnillado = 0, total = 0;

    cout << "--- COPIADORA UNIVERSITARIA ---\n";
    cout << "Ingrese la cantidad de hojas: ";
    cin >> hojas;
    cout << "Es a color (s/n): ";
    cin >> color;
    cout << "Indique su rol (E = Estudiante, D = Docente, O = Otro): ";
    cin >> rol;
    cout << "Es en horario nocturno (s/n): ";
    cin >> nocturno;
    cout << "Lleva anillado (s/n): ";
    cin >> anillado;

    if (hojas <= 20) {
        if (color == 's' || color == 'S') precioHoja = 0.20;
        else precioHoja = 0.10;
    }
    else if (hojas >= 21 && hojas <= 100) {
        if (color == 's' || color == 'S') precioHoja = 0.15;
        else precioHoja = 0.08;
    }
    else {
        if (color == 's' || color == 'S') precioHoja = 0.10;
        else precioHoja = 0.05;
    }

    subtotal = hojas * precioHoja;

    if (rol == 'D' || rol == 'd') {
        descuento = subtotal * 0.05;
    }
    else if ((rol == 'E' || rol == 'e') && hojas > 50) {
        descuento = subtotal * 0.08;
    }
    else {
        descuento = 0.0;
    }

    if (nocturno == 's' || nocturno == 'S') {
        recargo = subtotal * 0.10;
    }

    if (anillado == 's' || anillado == 'S') {
        if (hojas > 50) {
            valorAnillado = 1.00;
        } else {
            valorAnillado = 2.00;
        }
    }

    total = subtotal - descuento + recargo + valorAnillado;

    cout << "\n=== FACTURA DE COPIADORA===\n";
    cout << "Subtotal impresion: $" << subtotal << "\n";
    cout << "Descuento aplicado: -$" << descuento << "\n";
    cout << "Recargo nocturno: +$" << recargo << "\n";
    cout << "Valor de anillado: +$" << valorAnillado << "\n";
    cout << "TOTAL A PAGAR: $" << total << "\n";

    return 0;
}
