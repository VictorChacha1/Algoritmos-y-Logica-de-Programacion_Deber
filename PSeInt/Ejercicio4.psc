Proceso FacturacionCopiadora
    Definir hojas Como Entero
    Definir color, nocturno, anillado, rol Como Caracter
    Definir precioHoja, subtotal, descuento, recargo, valorAnillado, total Como Real
    
    Escribir "Ingrese la cantidad de hojas a imprimir:"
    Leer hojas
    Escribir "Es a color (s/n):"
    Leer color
    Escribir "Indique su rol (E = Estudiante, D = Docente, O = Otro):"
    Leer rol
    Escribir "Es en horario nocturno (s/n):"
    Leer nocturno
    Escribir "Lleva anillado (s/n):"
    Leer anillado
    
    precioHoja <- 0
    subtotal <- 0
    descuento <- 0
    recargo <- 0
    valorAnillado <- 0
    total <- 0
    
    Si hojas <= 20 Entonces
        Si color = "s" O color = "S" Entonces
            precioHoja <- 0.20
        Sino
            precioHoja <- 0.10
        FinSi
    Sino
        Si hojas >= 21 Y hojas <= 100 Entonces
            Si color = "s" O color = "S" Entonces
                precioHoja <- 0.15
            Sino
                precioHoja <- 0.08
            FinSi
        Sino
            Si color = "s" O color = "S" Entonces
                precioHoja <- 0.10
            Sino
                precioHoja <- 0.05
            FinSi
        FinSi
    FinSi
    
    subtotal <- hojas * precioHoja
    
    Si rol = "D" O rol = "d" Entonces
        descuento <- subtotal * 0.05 
    Sino
        Si (rol = "E" O rol = "e") Y hojas > 50 Entonces
            descuento <- subtotal * 0.08 
        Sino
            descuento <- 0 
        FinSi
    FinSi
    
    Si nocturno = "s" O nocturno = "S" Entonces
        recargo <- subtotal * 0.10 
    FinSi
    
    Si anillado = "s" O anillado = "S" Entonces
        Si hojas > 50 Entonces
            valorAnillado <- 1.00 
        Sino
            valorAnillado <- 2.00 
        FinSi
    FinSi
    
    total <- subtotal - descuento + recargo + valorAnillado
    
    Escribir "============== FACTURA =============="
    Escribir "Subtotal impresion: ", subtotal
    Escribir "Descuento aplicado: ", descuento
    Escribir "Recargo nocturno: ", recargo
    Escribir "Valor de anillado: ", valorAnillado
    Escribir "TOTAL A PAGAR: ", total
	Escribir "====================================="
FinProceso
