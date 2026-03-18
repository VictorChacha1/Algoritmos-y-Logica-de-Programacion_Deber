#include <iostream>
#include <string>

using namespace std;

int main() {
    float lado1, lado2, lado3, altura, angulo, area;
    string validez, tipoLados, tipoAngulos, mensajeConsistencia;

    cout << "=== TRIANGULO ===\n";
    cout << "Ingrese el lado 1: ";
    cin >> lado1;
    cout << "Ingrese el lado 2: ";
    cin >> lado2;
    cout << "Ingrese el lado 3: ";
    cin >> lado3;
    cout << "Ingrese la altura: ";
    cin >> altura;
    cout << "Ingrese el angulo principal: ";
    cin >> angulo;

    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1)) {
        validez = "Triangulo Valido";

        if (lado1 == lado2 && lado2 == lado3) {
            tipoLados = "Equilatero";
        }
        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            tipoLados = "Isosceles";
        }
        else {
            tipoLados = "Escaleno";
        }

        if (angulo < 90) {
            tipoAngulos = "Acutangulo";
        }
        else if (angulo == 90) {
            tipoAngulos = "Rectangulo";
        }
        else {
            tipoAngulos = "Obtusangulo";
        }

        area = (lado1 * altura) / 2.0;

        if (altura > lado1 || altura > lado2 || altura > lado3) {
            mensajeConsistencia = "Advertencia: La altura es inconsistente";
        }
        else {
            mensajeConsistencia = "Altura consistente con los lados";
        }

        cout << "\n============== ANALISIS DEL TRIANGULO ===============\n";
        cout << "Validez: " << validez << "\n";
        cout << "Tipo por lados: " << tipoLados << "\n";
        cout << "Tipo por angulos: " << tipoAngulos << "\n";
        cout << "Area: " << area << "\n";
        cout << "Consistencia: " << mensajeConsistencia << "\n";

    } else {
        cout << "\n============== ANALISIS DEL TRIANGULO ===============\n";
        cout << "Validez: Los lados ingresados no forman un triangulo.\n";
        cout << "Ejecucion terminada.\n";
    }

    return 0;
}

