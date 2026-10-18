# Semana 5 — Diccionarios

## Slide 1

Diccionarios
Semana 5
Wilder Nina Choquehuayta
wnina@utec.edu.pe

7 de septiembre de 2026

## Slide 2

    ¿Qué aprenderemos hoy?

 ▶ El TDA Diccionario
 ▶ ¿Qué tan rápido podemos hacerlo con lo que ya sabemos?
 ▶ Tablas de direccionamiento directo
 ▶ Funciones hash y el problema de las colisiones
 ▶ Encadenamiento y direccionamiento abierto
 ▶ Factor de carga y complejidad esperada
 ▶ Diseñando una buena función hash

## Slide 4

    El TDA Diccionario

Definición
Un diccionario (map) guarda pares (clave, valor), donde cada clave aparece
a lo más una vez. Soporta:
 ▶ insertar(clave, valor)
 ▶ buscar(clave): devuelve el valor asociado (o indica que no existe).
 ▶ eliminar(clave)

Ejemplos de uso
Contar cuántas veces aparece cada palabra en un texto; guardar el nombre
de usuario asociado a cada ID; una caché de resultados ya calculados.

## Slide 6

    Repaso: nuestras herramientas actuales

¡Piénsalo!
Con arreglos y listas enlazadas (lo que ya conocemos), ¿qué complejidad
logramos para insertar/buscar/ eliminar por clave?

## Slide 7

    Repaso: nuestras herramientas actuales

                               Buscar              Insertar             Eliminar

     Arreglo/lista, sin or-    O(n)                O(1)                 O(n)
     denar
     Arreglo ordenado          O(lg n)             O(n)                 O(n)

   Ninguna opción logra las tres en O(1) o incluso O(lg n) simultáneamente —
    ordenar ayuda a buscar, pero encarece insertar/eliminar (hay que desplazar),
    exactamente el mismo dilema que ya vimos con arreglos vs. listas enlazadas.

La meta de hoy
Lograr las tres operaciones en O(1) esperado — no en el peor caso, pero sí en la
inmensa mayoría de los casos reales.

## Slide 9

    El caso ideal: acceso directo

Si las claves fueran enteros pequeños
Supongamos que las claves son enteros en {0, 1, . . . , m−1}. Entonces basta
un arreglo T [0..m−1]: guardar el valor de la clave k directamente en T [k].

Complejidad
insertar, buscar y eliminar son O(1) exactos — indexar un arreglo.

   Esto se llama una tabla de direccionamiento directo. ¿Cuál es el problema?

## Slide 10

    El problema: el universo de claves es enorme

¡Piénsalo!
Si las claves son, por ejemplo, códigos de estudiante de 9 dígitos (109
valores posibles), pero en la práctica solo tienes n = 200 estudiantes, ¿qué
pasa si reservas un arreglo del tamaño de todo el universo de claves?

Respuesta
Se desperdicia una cantidad enorme de memoria (un arreglo de 109
posiciones para guardar 200 valores) — y ni hablar si las claves son strings
(nombres, palabras), donde ni siquiera hay un orden natural de indexación
directa.

## Slide 12

    La idea: comprimir el universo

Función hash
Una función hash h mapea el universo (grande) de claves posibles U a un
rango (chico) de índices de tabla:

                             h : U −→ {0, 1, . . . , m − 1}.

Guardamos la clave k en la posición T [h(k)], con m ≪ |U|.

Ahora la tabla mide m (proporcional a cuántas claves realmente usamos), no |U|.

## Slide 13

    El problema de las colisiones

¡Piénsalo!
Si |U| > m (el universo tiene más elementos que la tabla), ¿es posible que h
sea inyectiva (que nunca dos claves distintas caigan en la misma posición)?

Respuesta: no, nunca
Por el principio del palomar: si metes más de m claves posibles en m
casillas, al menos dos deben compartir casilla. Una colisión ocurre cuando
h(k1 ) = h(k2 ) con k1 ̸= k2 .

 Las colisiones son inevitables en general — lo que podemos controlar es qué tan
                   seguido ocurren, y qué hacer cuando ocurren.

## Slide 14

    Visualizando una colisión

                             0                            clave A

                             1
                                               h(A) = h(B)

                             2                            clave B

                             3

                             4

 Dos claves distintas, A y B, se hashean a la misma posición — necesitamos una
                  estrategia para que ambas convivan en la tabla.

## Slide 16

    Estrategia 1: encadenamiento separado

Chaining
Cada posición T [i] de la tabla guarda, no un solo valor, sino una lista enla-
zada con todas las claves que hashean a i.

¿Por qué nos conviene justo ahora?
Ya sabemos implementar listas enlazadas (clase pasada) — insertar en un
bucket es un push_front, buscar recorre la lista de ese bucket. La próxima
clase la implementamos así.

## Slide 17

    Visualizando el encadenamiento

                             0                     B          A

                             1

                             2
                                                   C

                             3

 Las claves A y B colisionaron en la posición 0: ambas viven en la lista enlazada de
                      ese bucket. La posición 3 solo tiene a C .

## Slide 18

    Estrategia 2: direccionamiento abierto

Open addressing
En vez de listas, todo vive dentro del arreglo T : si la posición h(k) ya está
ocupada, se prueba otra posición siguiendo una secuencia fija (probing ), hasta
encontrar una libre.

Variantes (solo para que las reconozcas)
Sondeo lineal: probar h(k) + 1, h(k) + 2, . . . Sondeo cuadrático: probar
h(k) + 12 , h(k) + 22 , . . . Hashing doble: usar una segunda función hash
para el tamaño del salto.

  No lo implementaremos en este curso (nos quedamos con encadenamiento, más
simple de razonar) — pero std::unordered_map y tablas hash de otros lenguajes
               a veces usan variantes de direccionamiento abierto.

## Slide 20

    Factor de carga

Definición
Con encadenamiento, el factor de carga es
                                                n
                                           α=     ,
                                                m
donde n es el número de claves guardadas y m el número de posiciones
(buckets) de la tabla — es decir, el promedio de claves por bucket.

¡Piénsalo!
Si buscas una clave y su bucket tiene, en promedio, α elementos, ¿qué tan
larga es la lista que hay que recorrer en el peor caso de ese bucket?

## Slide 21

    Tiempo esperado: Θ(1 + α)

Bajo hashing uniforme simple
Suponiendo que h distribuye las claves de forma pareja entre los m buckets
(cada clave, independientemente, es igual de probable de caer en cualquier
bucket): el número esperado de claves en un bucket dado es α = n/m.

Conclusión
Buscar una clave cuesta Θ(1) (calcular h(k)) más recorrer, en promedio,
Θ(α) elementos del bucket:
                                Θ(1 + α).

La clave para lograr O(1)
Si mantenemos m proporcional a n (por ejemplo, duplicando m cuando α
se vuelve grande — exactamente como el crecimiento amortizado de vector
y de la cola circular), α = O(1) siempre, y entonces Θ(1 + α) = Θ(1).

## Slide 22

    ¿Y si la función hash es mala?

¡Piénsalo!
Si h(k) = 0 para toda clave k (una función hash pésima, pero válida), ¿qué
le pasa a la complejidad, sin importar qué tan grande sea m?

Respuesta
Todas las claves caen en el mismo bucket: se degrada a una sola lista
enlazada de n elementos — Θ(n) por operación, el peor caso posible. El
Θ(1 + α) esperado depende de que h reparta las claves de forma pareja.

## Slide 24

    Método de la división

h(k) = k mód m
Para claves enteras: el resto de dividir k entre m. Simple y rápido.

¡Piénsalo!
Si m = 210 (una potencia de 2) y las claves son, por ejemplo, direcciones de
memoria (casi siempre pares, o múltiplos de 4 u 8), ¿qué le pasa a la
distribución de h(k)?

Respuesta: se concentra mal
k mód 210 solo depende de los últimos 10 bits de k — si esos bits tienen un
patrón (por ejemplo, siempre pares), muchas claves distintas comparten los
mismos residuos. Recomendación: elegir m primo, alejado de potencias de
2.

## Slide 25

    Ejemplo trabajado: construyendo la tabla

m = 7 (primo), claves {23, 45, 12, 37, 7, 20}
Calculando h(k) = k mód 7 para cada una:

          h(23)=2, h(45)=3, h(12)=5, h(37)=2, h(7)=0, h(20)=6.
                               0                7

                               1

                               2                23              37
                                                     colisión
                               3                45

                               4

                               5                12

## Slide 26

    Método de la multiplicación

h(k) = ⌊m · (kA mód 1)⌋
                                                               √
Con A una constante irracional bien elegida (por ejemplo, A ≈ ( 5 − 1)/2,
la razón áurea). kA mód 1 es la parte fraccionaria de kA.

    Ventaja: el valor de m no es tan delicado como en el método de la división
    (funciona razonablemente para casi cualquier m, incluyendo potencias de 2,
                   cómodas para la aritmética de computadora).

## Slide 27

    Hashing de strings

El problema
Nuestras funciones hash asumen una clave numérica. ¿Cómo hasheamos un
string (un nombre, una palabra)?

Idea: tratarlo como un número en base B
Para s = s0 s1 . . . sL−1 (códigos ASCII/Unicode), definir
                                      L−1
                                      X
                           val(s) =         si · B i   (mód M),
                                      i=0

con B una base (por ejemplo 131 o 257, mayor que el alfabeto) y M grande.
Luego aplicamos h(val(s)) = val(s) mód m como antes.

## Slide 28

    Propiedades de una buena función hash

 ▶ Determinística: la misma clave siempre produce el mismo índice.
 ▶ Rápida de calcular: O(1) respecto al tamaño de la clave (o lineal en
   su longitud, para strings).
 ▶ Distribución uniforme: claves distintas deben repartirse parejo entre
   los m buckets, sin importar patrones que pueda tener el conjunto real
   de claves usadas.

## Slide 29

    Aplicaciones

 ▶ dict de Python, unordered_map de C++, HashMap de Java: todos
   son tablas hash.
 ▶ Conteo de frecuencias: ¿cuántas veces aparece cada palabra en un
   texto?
 ▶ Detección de duplicados: ¿hay dos elementos iguales en un arreglo?
 ▶ Caché: guardar resultados ya calculados, indexados por sus argumentos
   de entrada.
 ▶ Índices de bases de datos, tablas de símbolos de compiladores, y
   muchísimo más.

## Slide 30

    Resumen de la sesión

 ▶ Un diccionario necesita insertar/ buscar/eliminar rápido por
   clave — ninguna estructura vista hasta ahora logra las tres a la vez.
 ▶ Una función hash h : U → {0, . . . , m−1} comprime un universo
   grande de claves a una tabla chica.
 ▶ Las colisiones son inevitables (principio del palomar); se resuelven con
   encadenamiento (listas por bucket) o direccionamiento abierto
   (probing ).
 ▶ Con hashing uniforme simple y factor de carga α = n/m acotado
   (creciendo la tabla cuando hace falta), toda operación es
   Θ(1 + α) = Θ(1) esperado.
 ▶ Próxima clase: implementamos una tabla hash con encadenamiento,
   usando las listas enlazadas que ya construimos.

## Slide 31

                                        Gracias
