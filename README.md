# Validador de expresiones matemáticas en C++

Este proyecto académico implementa una **pila (stack) desde cero** utilizando
listas enlazadas en C++.  
La pila se aplica para validar expresiones matemáticas simples ingresadas
por el usuario.

## Funcionalidades
- Verifica el correcto balance de:
  - Paréntesis `()`
  - Corchetes `[]`
  - Llaves `{}`  
- Valida que los números utilizados sean de **un solo dígito (0–9)**
- No utiliza la STL (`std::stack`) con fines didácticos

## Tecnologías
- Lenguaje: C++
- Paradigma: Programación orientada a objetos
- Estructura de datos: Pila implementada con lista enlazada

## Propósito académico
Este proyecto fue desarrollado con fines educativos para reforzar el
funcionamiento interno de las pilas y su aplicación en problemas reales.

## Limitaciones
- No evalúa el resultado de la expresión
- No permite números de más de un dígito
- No valida la correcta secuencia de operadores

## Autor
Andrés Aguirre

- Soporte para números de varios dígitos
- Evaluación completa de la expresión
- Uso de `std::stack` como comparación
