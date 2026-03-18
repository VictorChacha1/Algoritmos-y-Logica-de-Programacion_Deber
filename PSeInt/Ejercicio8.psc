Proceso EvaluacionEstudiante
    Definir nota1, nota2, nota3, promedio Como Real
    Definir asistencia Como Real
    Definir notasBajas Como Entero
    Definir proyecto, plagio Como Caracter
    Definir estadoAcademico, obsDisciplinaria, obsRendimiento Como Cadena
    
    Escribir "Ingrese la nota 1 de 0 a 10: "
    Leer nota1
    Escribir "Ingrese la nota 2 de 0 a 10: "
    Leer nota2
    Escribir "Ingrese la nota 3 de 0 a 10: "
    Leer nota3
    Escribir "Ingrese porcentaje de asistencia: "
    Leer asistencia
    Escribir "Entrego el proyecto final (s/n): "
    Leer proyecto
    Escribir "Cometio plagio (s/n): "
    Leer plagio
    
    estadoAcademico <- "Por definir"
    obsDisciplinaria <- "Sin observaciones"
    obsRendimiento <- "Normal"
    
    promedio <- (nota1 + nota2 + nota3) / 3
    
    notasBajas <- 0
    
    Si nota1 < 4 Entonces
        notasBajas <- notasBajas + 1
    FinSi
    
    Si nota2 < 4 Entonces
        notasBajas <- notasBajas + 1
    FinSi
    
    Si nota3 < 4 Entonces
        notasBajas <- notasBajas + 1
    FinSi
    
    Si (nota1 = 10 O nota2 = 10 O nota3 = 10) Y notasBajas >= 2 Entonces
        obsRendimiento <- "Rendimiento irregular: Tiene un 10 pero dos notas muy bajas."
    FinSi

    Si plagio = "s" O plagio = "S" Entonces
        estadoAcademico <- "REPROBADO"
        obsDisciplinaria <- "Sancion grave por plagio."
    Sino
        Si asistencia < 70 Entonces
            estadoAcademico <- "REPROBADO"
            obsDisciplinaria <- "Reprobado por inasistencia (menor al 70%)."
        Sino
            Si promedio < 5 Entonces
                estadoAcademico <- "REPROBADO"
                obsDisciplinaria <- "Promedio insuficiente."
            Sino
                Si promedio >= 5 Y promedio < 7 Entonces
                    estadoAcademico <- "RECUPERACION"
                Sino
                    Si proyecto = "n" O proyecto = "N" Entonces
                        estadoAcademico <- "RECUPERACION"
                        obsDisciplinaria <- "Pierde aprobacion directa por no entregar proyecto."
                    Sino
                        Si nota1 >= 9 Y nota2 >= 9 Y nota3 >= 9 Y asistencia >= 95 Entonces
                            estadoAcademico <- "APROBADO CON FELICITACION"
                            obsRendimiento <- "Rendimiento excelente."
                        Sino
                            estadoAcademico <- "APROBADO"
                        FinSi
                    FinSi
                FinSi
            FinSi
        FinSi
    FinSi
    
    Escribir "=============== REPORTE ACADEMICO ==============="
    Escribir "Promedio: ", promedio
    Escribir "Estado Academico: ", estadoAcademico
    Escribir "Observacion Disciplinaria: ", obsDisciplinaria
    Escribir "Observacion de Rendimiento: ", obsRendimiento
	Escribir "================================================="
FinProceso
