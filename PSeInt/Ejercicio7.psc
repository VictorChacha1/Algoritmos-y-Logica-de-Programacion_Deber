Proceso ConsumoElectrico
    Definir lecturaAnterior, lecturaActual, consumo, consumoPorHabitante Como Real
    Definir habitantes Como Entero
    Definir costoBase, recargo, subsidio, total Como Real
    Definir tipoVivienda, artefactos, deuda Como Caracter
    Definir alerta1, alerta2 Como Cadena
    
    Escribir "Ingrese la lectura anterior (kWh): "
    Leer lecturaAnterior
    Escribir "Ingrese la lectura actual (kWh): "
    Leer lecturaActual
    
    Si lecturaActual < lecturaAnterior Entonces
        Escribir "Error: Dato invalido. La lectura actual no puede ser menor a la anterior."
    Sino
        Escribir "Tipo de vivienda S = Social, R = Regular: "
        Leer tipoVivienda
        Escribir "Numero de habitantes: "
        Leer habitantes
        Escribir "Tiene artefactos de alto consumo (s/n): "
        Leer artefactos
        Escribir "Tiene deuda anterior (s/n): "
        Leer deuda
        
        costoBase <- 0
        recargo <- 0
        subsidio <- 0
        total <- 0
        alerta1 <- "Consumo por habitante normal."
        alerta2 <- "Sin riesgo por artefactos."
        
        consumo <- lecturaActual - lecturaAnterior
        
        Si consumo <= 100 Entonces
            costoBase <- consumo * 0.10
        Sino
            Si consumo > 100 Y consumo <= 200 Entonces
                costoBase <- consumo * 0.15
            Sino
                costoBase <- consumo * 0.20 
            FinSi
        FinSi
        
        Si deuda = "s" O deuda = "S" Entonces
            recargo <- costoBase * 0.10 
        FinSi
        
        Si (tipoVivienda = "S" O tipoVivienda = "s") Y consumo <= 100 Entonces
            subsidio <- costoBase * 0.20 
        FinSi
        
        consumoPorHabitante <- consumo / habitantes
        Si consumoPorHabitante > 50 Entonces
            alerta1 <- "ALERTA: Consumo excesivo por habitante."
        FinSi
        
        Si (artefactos = "s" O artefactos = "S") Y consumo > 200 Entonces
            alerta2 <- "RIESGO: Posible sobrefacturacion por artefactos de alto consumo."
        FinSi
        
        total <- costoBase + recargo - subsidio
        
        Escribir "=========== FACTURA DE ELECTRICIDAD ==========="
        Escribir "Consumo total: ", consumo, " kWh"
        Escribir "Costo base: $", costoBase
        Escribir "Recargo por deuda: ", recargo
        Escribir "Subsidio aplicado: ", subsidio
        Escribir "TOTAL A PAGAR: ", total
        Escribir "============ MENSAJES PREVENTIVOS ============"
        Escribir alerta1
        Escribir alerta2
    FinSi
FinProceso
