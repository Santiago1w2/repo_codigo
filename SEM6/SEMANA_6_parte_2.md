# Semana 6 (parte 2) — Árbol binario de búsqueda

## Slide 1

Árbol binario de búsqueda
Semana 6
Wilder Nina Choquehuayta
wnina@utec.edu.pe

14 de septiembre de 2026

## Slide 2

    Objetivos de la sesión

 ▶ La estructura del nodo
 ▶ Buscar, Mínimo, Máximo
 ▶ Insertar
 ▶ Sucesor y Predecesor
 ▶ Eliminar — el más delicado de todos
 ▶ Recorrido-Inorder

## Slide 3

    Motivación

La clase pasada quedó en teoría
Vimos el TDA completo y su complejidad O(h) — pero nunca vimos cómo
se implementa cada operación realmente.

¡Piénsalo!
De las 7 operaciones del TDA, ¿cuál crees que va a ser la más simple de
implementar? ¿Y la más delicada?

Spoiler
Buscar es casi trivial. Eliminar — por los casos que hay que manejar —
es, de lejos, la más delicada. Hoy construimos las 7, en ese orden de
dificultad creciente.

## Slide 5

    El nodo

Campos
Cada nodo x guarda:
 ▶ x.clave: el valor almacenado.
 ▶ x.izq, x.der : punteros a los hijos (nulos si no existen).
 ▶ x.padre: puntero al padre (nulo si x es la raíz).

¡Piénsalo!
En la lista doblemente enlazada, guardar el puntero al anterior nos ahorraba
O(n) al eliminar. ¿Qué nos va a ahorrar x.padre aquí?

Respuesta
Subir desde cualquier nodo sin tener que volver a bajar desde la raíz —
esencial para Sucesor y Eliminar.

## Slide 7

    Buscar

Algoritmo 2: Buscar(x, k)
si x = nulo o k = x.clave entonces
    devolver x
si k < x.clave entonces
    devolver Buscar(x.izq, k)
devolver Buscar(x.der , k)

  Exactamente la traducción directa de la propiedad BST: compara, y sigue por el
            lado correcto. O(h): baja, a lo más, un camino completo.

## Slide 8

    Mínimo y Máximo

Algoritmo 5: Mínimo(x)
mientras x.izq ̸= nulo hacer
   x ← x.izq
devolver x

¡Piénsalo!
¿Por qué basta con ir siempre a la izquierda, sin comparar ningún valor?

Respuesta
Por la propiedad BST, todo lo que está a la izquierda de un nodo es menor
— el nodo más a la izquierda no tiene nada menor que él. Máximo es
simétrico, yendo siempre a la derecha.

## Slide 10

    Insertar

Algoritmo 6: Insertar(T , k)
y ← nulo, x ← T .raiz
mientras x ̸= nulo hacer
   y ←x
   si k < x.clave entonces
       x ← x.izq
   en otro caso
       x ← x.der

z ← nuevo nodo con clave k, z.padre ← y
si y = nulo entonces
    T .raiz ← z
si no, si k < y .clave entonces
    y .izq ← z
en otro caso
Wilder Nina ←
    y .der     z

## Slide 11

    Insertar: la idea

¡Piénsalo!
El ciclo while se parece mucho a Buscar. ¿Qué está buscando en
realidad, si k no está todavía en el árbol?

Respuesta
Busca el lugar donde debería estar: el ciclo termina justo cuando cae en un
puntero nulo — ahí es donde cuelga el nodo nuevo, como hijo de y (el
último nodo visitado).

## Slide 12

    Insertando, paso a paso

                                                   8

                                    3                           10

                           1                  6

                                                       7

 Insertando 7: 8 → izquierda (7 < 8); 3 → derecha (7 > 3); 6 → derecha (7 > 6);
            nulo → aquí cuelga el nuevo nodo, como hijo derecho de 6.

## Slide 14

    Sucesor

Algoritmo 7: Sucesor(x)
si x.der ̸= nulo entonces
    devolver Mínimo(x.der )
y ← x.padre
mientras y ̸= nulo y x = y .der hacer
   x ←y
   y ← y .padre
devolver y

## Slide 15

    Sucesor: dos casos

¡Piénsalo!
Si x tiene hijo derecho, ¿dónde está su sucesor? Y si no tiene hijo derecho,
¿cómo lo encuentras sin volver a bajar desde la raíz?

Caso 1: hay hijo derecho
El sucesor es el mínimo de ese subárbol derecho — el siguiente valor mayor
siempre está ahí.

Caso 2: no hay hijo derecho
Sube por los punteros padre mientras vengas de un hijo derecho; el primer
ancestro del que vengas por la izquierda (o la raíz misma) es el sucesor.

 Predecesor es exactamente simétrico: izquierda en vez de derecha, en todos los
                                  pasos.

## Slide 17

    Eliminar: tres casos

¡Piénsalo!
Antes de ver código: si el nodo z que quieres eliminar tiene 0, 1, o 2 hijos,
¿en qué se complica cada caso?

 Con 0 o 1 hijo, es fácil: el padre de z simplemente “adopta” a ese único hijo (o a
  nada). El problema real es con 2 hijos: no puedes simplemente conectar los dos
                              directamente al padre de z.

## Slide 18

    Caso 1 y 2: cero o un hijo

                              p                               p

                                                =⇒
                              z                               c

                                           c

  El padre de z pasa a apuntar directamente a c (el único hijo de z, o nulo si no
                   tenía ninguno) — z simplemente se “salta”.

## Slide 19

    El helper: Transplantar

Algoritmo 9: Transplantar(T , u, v )
// Reemplaza el subárbol de u por el de v
si u.padre = nulo entonces
    T .raiz ← v
si no, si u = u.padre.izq entonces
    u.padre.izq ← v
en otro caso
    u.padre.der ← v
si v ̸= nulo entonces
    v .padre ← u.padre

No mueve datos: solo reconecta punteros — exactamente lo que necesitábamos en
                             el caso de 0 o 1 hijo.

## Slide 20

    Caso 3: dos hijos

¡Piénsalo!
No puedes simplemente conectar ambos hijos de z al padre de z (¿a dónde
iría el segundo?). ¿Qué otro valor del árbol podría ocupar el lugar de z sin
romper la propiedad BST?

Respuesta: el sucesor de z
El Sucesor(z) — el mínimo del subárbol derecho — es el valor más
cercano a z por arriba. Ponerlo en el lugar de z mantiene el orden: nada a
la izquierda es mayor, nada a la derecha es menor.

  Y como es un mínimo, el sucesor nunca tiene hijo izquierdo — eliminarlo de su
            posición original cae en el Caso 1 o 2, que ya resolvimos.

## Slide 21

    Eliminar

Algoritmo 10: Eliminar(T , z)
si z.izq = nulo entonces
    Transplantar(T , z, z.der )
si no, si z.der = nulo entonces
    Transplantar(T , z, z.izq)
en otro caso
    y ← Mínimo(z.der )
    si y .padre ̸= z entonces
        Transplantar(T , y , y .der )
        y .der ← z.der , y .der .padre ← y
     Transplantar(T , z, y )
     y .izq ← z.izq, y .izq.padre ← y

## Slide 22

    Eliminar: leyendo el caso 3 con cuidado

¡Piénsalo!
¿Por qué el código distingue si y .padre = z (el sucesor es hijo directo de
z) del caso general?

Respuesta
Si y ya es el hijo derecho directo de z, no hace falta “sacarlo” de ningún
lado — simplemente se convierte en la nueva raíz del subárbol. Si y está
más abajo, primero hay que desconectarlo de su posición original
(Transplantar(T , y , y .der )) antes de moverlo.

## Slide 24

    Recorrido-Inorder

Algoritmo 12: Recorrido-Inorder(x)
si x ̸= nulo entonces
    Recorrido-Inorder(x.izq)
    visitar x
    Recorrido-Inorder(x.der )

Tres líneas, y por la propiedad BST (que vimos la clase pasada) esto siempre visita
  los elementos en orden creciente. Θ(n): visita cada nodo exactamente una vez.

## Slide 25

    Cierre de la sesión

 ▶ El nodo guarda clave, izq, der y padre — este último es lo que permite
   Sucesor y Eliminar sin volver a bajar desde la raíz.
 ▶ Buscar, Mínimo/Máximo e Insertar son variaciones directas de
   “sigue la propiedad BST hasta un puntero nulo”.
 ▶ Sucesor tiene dos casos: mínimo del subárbol derecho si existe, o
   subir hasta el primer ancestro del que vengas por la izquierda.
 ▶ Eliminar tiene tres casos (0, 1 o 2 hijos); el caso de 2 hijos se
   resuelve reemplazando z por su Sucesor — que, al ser un mínimo,
   siempre cae en el Caso 1 o 2 al eliminarlo de su lugar original.
 ▶ Recorrido-Inorder es recursivo y directo: izquierda, visitar,
   derecha.

## Slide 26

    Logros de la sesión

 ▶ Sabemos implementar las 7 operaciones del TDA BST con
   pseudocódigo real.
 ▶ Sabemos por qué guardar x.padre simplifica Sucesor y Eliminar.
 ▶ Sabemos manejar los 3 casos de Eliminar, incluyendo por qué el caso
   de 2 hijos se reduce a los otros dos vía el sucesor.

## Slide 27

                                        Gracias
