#include <iostream>
#include <string>

using namespace std;

int main() {
    float nota1, nota2, nota3, promedio;
    int asistencia, notasBajas = 0;
    char proyecto, plagio;
    string estadoAcademico = "Por definir";
    string obsDisciplinaria = "Sin observaciones";
    string obsRendimiento = "Normal";

    cout << "============ SISTEMA DE EVALUACION =============\n";
    cout << "Ingrese la nota 1: ";
    cin >> nota1;
    cout << "Ingrese la nota 2: ";
    cin >> nota2;
    cout << "Ingrese la nota 3: ";
    cin >> nota3;
    cout << "Porcentaje de asistencia: ";
    cin >> asistencia;
    cout << "¿Entrego el proyecto final? (s/n): ";
    cin >> proyecto;
    cout << "¿Cometio plagio? (s/n): ";
    cin >> plagio;

    promedio = (nota1 + nota2 + nota3) / 3.0;

    if (nota1 < 4) notasBajas++;
    if (nota2 < 4) notasBajas++;
    if (nota3 < 4) notasBajas++;

    if ((nota1 == 10 || nota2 == 10 || nota3 == 10) && notasBajas >= 2) {
        obsRendimiento = "Rendimiento irregular: Obtuvo 10, pero dos componentes bajo 4.";
    }

    if (plagio == 's' || plagio == 'S') {
        estadoAcademico = "REPROBADO";
        obsDisciplinaria = "Sancion grave por plagio.";
    }
    else if (asistencia < 70) {
        estadoAcademico = "REPROBADO";
        obsDisciplinaria = "Reprobado por inasistencia (menor a 70%).";
    }
    else {
        if (promedio < 5) {
            estadoAcademico = "REPROBADO";
            obsDisciplinaria = "Promedio insuficiente (menor a 5).";
        }
        else if (promedio >= 5 && promedio < 7) {
            estadoAcademico = "RECUPERACION";
        }
        else {
            if (proyecto == 'n' || proyecto == 'N') {
                estadoAcademico = "RECUPERACION";
                obsDisciplinaria = "No entrego proyecto final. Maximo va a recuperacion.";
            }
            else {
                if (nota1 >= 9 && nota2 >= 9 && nota3 >= 9 && asistencia >= 95) {
                    estadoAcademico = "APROBADO CON FELICITACION";
                    obsRendimiento = "Rendimiento excelente en todo el periodo.";
                } else {
                    estadoAcademico = "APROBADO";
                }
            }
        }
    }
    cout << "\n============= REPORTE SISTEMA ACADEMICO ==============\n";
    cout << "Promedio: " << promedio << "\n";
    cout << "Estado Academico: " << estadoAcademico << "\n";
    cout << "Observacion Disciplinaria: " << obsDisciplinaria << "\n";
    cout << "Observacion de Rendimiento: " << obsRendimiento << "\n";

    return 0;
}

