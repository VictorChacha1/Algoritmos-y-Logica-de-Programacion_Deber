#include <iostream>
#include <string>

using namespace std;

int main() {
    float promedio;
    int materiasPerdidas, asistencia, nivelAyuda;
    char ingresosBajos, proyectos;
    string tipoAyuda, razonAcademica, razonEconomica, observacionFinal;

    cout << "--- SISTEMA DE BECAS UNIVERSITARIAS ---\n";
    cout << "Ingrese el promedio academico: ";
    cin >> promedio;
    cout << "Ingrese porcentaje de asistencia: ";
    cin >> asistencia;
    cout << "Ingrese numero de materias perdidas: ";
    cin >> materiasPerdidas;
    cout << "¿Tiene ingresos familiares bajos? (s/n): ";
    cin >> ingresosBajos;
    cout << "¿Participa en proyectos? (s/n): ";
    cin >> proyectos;

    nivelAyuda = 0;
    razonAcademica = "No evaluado";
    razonEconomica = "No aplica";
    observacionFinal = "Ninguna";

    if (promedio < 7) {
        nivelAyuda = 0;
        razonAcademica = "Promedio menor a 7";
    }
    else if (asistencia < 80) {
        nivelAyuda = 0;
        razonAcademica = "Asistencia menor al 80%";
    }
    else {
        if (promedio >= 9 && asistencia >= 90 && materiasPerdidas == 0) {
            nivelAyuda = 3;
            razonAcademica = "Excelencia academica, sin materias perdidas";
        }
        else if (promedio >= 8 && asistencia >= 85) {
            nivelAyuda = 2;
            razonAcademica = "Buen promedio y asistencia";
        }
        else {
            nivelAyuda = 0;
            razonAcademica = "Promedio regular, sin beneficio base";
        }
    }
    if ((proyectos == 's' || proyectos == 'S') && (ingresosBajos == 's' || ingresosBajos == 'S')) {
        razonEconomica = "Participa en proyectos y tiene ingresos bajos";

        if (nivelAyuda == 0 && promedio >= 7 && asistencia >= 80) {
            nivelAyuda = 1;
            observacionFinal = "Sube a ayuda de materiales por perfil economico";
        }
        else if (nivelAyuda == 1) {
            nivelAyuda = 2;
            observacionFinal = "Sube a beca parcial por perfil economico";
        }
        else if (nivelAyuda == 2) {
            if (materiasPerdidas == 0) {
                nivelAyuda = 3;
                observacionFinal = "Sube a beca completa por perfil economico";
            } else {
                observacionFinal = "No puede subir a beca completa porque perdio materias";
            }
        }
    } else {
        razonEconomica = "No cumple requisitos de ingresos y proyectos juntos";
        observacionFinal = "Mantiene su beneficio base";
    }

    if (nivelAyuda == 3 && materiasPerdidas > 1) {
        nivelAyuda = 2;
        observacionFinal = "Se reduce a beca parcial por tener mas de 1 materia perdida";
    }

    if (nivelAyuda == 0) tipoAyuda = "Sin beneficio";
    else if (nivelAyuda == 1) tipoAyuda = "Solo ayuda de materiales";
    else if (nivelAyuda == 2) tipoAyuda = "Beca parcial";
    else if (nivelAyuda == 3) tipoAyuda = "Beca completa";

    cout << "\n=========== RESULTADO DE BECAS ============\n";
    cout << "Tipo de ayuda: " << tipoAyuda << "\n";
    cout << "Razon academica: " << razonAcademica << "\n";
    cout << "Razon economica: " << razonEconomica << "\n";
    cout << "Observacion: " << observacionFinal << "\n";

    return 0;
}

