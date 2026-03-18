Proceso PlanificadorViaje
    Definir numEstudiantes, tipoTransporte, dias, paganTransporte Como Entero
    Definir costoHospedajeDia, precioPasaje, costoTransporte, costoHospedaje, costoAlimentacion Como Real
    Definir descuento, totalGeneral, totalEstudiante Como Real
    Definir alimentacion, descInstitucional, coordinador Como Caracter
    Definir recomendacion Como Cadena
    
    Escribir "Ingrese el numero total de estudiantes: "
    Leer numEstudiantes
    Escribir "Seleccione tipo de transporte 1: Basico, 2: Premium: "
    Leer tipoTransporte
    Escribir "Ingrese el numero de dias del viaje: "
    Leer dias
    Escribir "Ingrese el costo de hospedaje por dia por persona: "
    Leer costoHospedajeDia
    Escribir "Incluye alimentacion (s/n): "
    Leer alimentacion
    Escribir "Tienen descuento institucional aprobado (s/n): "
    Leer descInstitucional
    Escribir "Uno de los viajeros es coordinador (s/n): "
    Leer coordinador
    
    costoTransporte <- 0
    costoHospedaje <- 0
    costoAlimentacion <- 0
    descuento <- 0
    
    paganTransporte <- numEstudiantes
    Si coordinador = "s" O coordinador = "S" Entonces
        paganTransporte <- numEstudiantes - 1 
    FinSi
    
    Si tipoTransporte = 1 Entonces
        precioPasaje <- 30.00
    Sino
        precioPasaje <- 50.00
    FinSi
    
    Si numEstudiantes > 20 Entonces
        precioPasaje <- precioPasaje - 5.00 
    FinSi
    costoTransporte <- paganTransporte * precioPasaje

    costoHospedaje <- numEstudiantes * dias * costoHospedajeDia
    Si dias > 3 Entonces
        costoHospedaje <- costoHospedaje * 0.90 
    FinSi
    
    Si alimentacion = "s" O alimentacion = "S" Entonces
        costoAlimentacion <- numEstudiantes * dias * 15.00
    FinSi
    
    totalGeneral <- costoTransporte + costoHospedaje + costoAlimentacion
    
    Si (descInstitucional = "s" O descInstitucional = "S") Y totalGeneral > 1000 Entonces
        descuento <- totalGeneral * 0.05
        totalGeneral <- totalGeneral - descuento
    FinSi
    
    totalEstudiante <- totalGeneral / numEstudiantes
    Si totalEstudiante > 150.00 Entonces
        recomendacion <- "Viaje no recomendable (presupuesto muy alto por persona)."
    Sino
        recomendacion <- "Viaje recomendable y dentro del presupuesto."
    FinSi
    
    Escribir "================ PRESUPUESTO DEL VIAJE ================"
    Escribir "Costo de transporte: $", costoTransporte
    Escribir "Costo de hospedaje: $", costoHospedaje
    Escribir "Costo de alimentacion: $", costoAlimentacion
    Escribir "Descuento aplicado: $", descuento
    Escribir "Total General: $", totalGeneral
    Escribir "Total por estudiante: $", totalEstudiante
    Escribir "Recomendacion: ", recomendacion
	Escribir "======================================================="
FinProceso
