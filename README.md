# Ejercicio 1
## Análisis comparativo: Imperativo (Python) vs Declarativo (Haskell)

####  1. Claridad y legibilidad del código

- **Imperativo (Python)**: el código es explícito en cada paso del proceso (recorrer, comparar, intercambiar). Esto lo hace fácil de seguir para principiantes, pero puede resultar más extenso y repetitivo.
    
- **Declarativo (Haskell)**: el código es más conciso, ya que solo se define la regla de comparación y se delega el resto a `sortBy`. Puede ser más difícil de leer al inicio, pero es más claro en expresar la intención del programador.
    

---

####  2. Nivel de expresividad y abstracción

- **Imperativo**: trabaja en un nivel más bajo, describiendo _cómo_ realizar el ordenamiento mediante bucles y swaps.
    
- **Declarativo**: trabaja en un nivel más alto, declarando únicamente _qué_ condición debe cumplirse para ordenar la lista, sin especificar los pasos internos.
    

---

####  3. Manejo de estructuras de datos (mutabilidad vs inmutabilidad)

- **Imperativo**: las listas son mutables, el algoritmo modifica la estructura de datos original intercambiando elementos en memoria.
    
- **Declarativo**: las listas son inmutables; `sortBy` genera una nueva lista ordenada sin alterar la original.
    

---

#### 4. Manejo de estado

- **Imperativo**: el estado del programa cambia constantemente, ya que la lista original se transforma con cada iteración del algoritmo.
    
- **Declarativo**: no hay cambios de estado visibles; se trabaja con funciones puras que devuelven resultados nuevos sin modificar datos existentes.
    

---

####  5. Facilidad de mantenimiento y extensión

- **Imperativo**: si se cambia la forma de ordenar (por ejemplo, añadir nuevos criterios), hay que modificar bucles y condiciones manualmente, lo que puede volver el código más complejo.
    
- **Declarativo**: basta con ajustar la función de comparación, sin tocar el mecanismo general de ordenamiento. Esto lo hace más sencillo de mantener y extender.
    

---

#### 6. Eficiencia de cada solución

- **Imperativo (Python con bubble sort)**: el algoritmo implementado es `O(n²)`, poco eficiente para listas grandes.
    
- **Declarativo (Haskell con sortBy)**: utiliza un algoritmo de ordenamiento optimizado (`O(n log n)`), lo que lo hace más eficiente para grandes volúmenes de datos.
    

---

### Conclusión

El enfoque **imperativo** es más intuitivo para aprender y comprender el funcionamiento paso a paso de un algoritmo, pero resulta menos eficiente y más difícil de mantener en programas grandes.  
El enfoque **declarativo/funcional** es más expresivo, conciso y eficiente, al centrarse en las reglas del problema y delegar la implementación a funciones predefinidas del lenguaje.


# Ejercicio 2
## Explicación del Punto 2

En este ejercicio se pedía optimizar el uso de memoria para manejar registros de estudiantes en C. Eso significa que no podemos usar arreglos fijos que desperdicien espacio, sino estructuras que se adapten a cada dato real. Para eso se usan varias herramientas:

---

####  1. `struct`

Un `struct` en C es una forma de **agrupar datos diferentes en una sola entidad**.  
En este caso, un estudiante tiene nombre, apellido, edad, identificación y calificaciones.  
El `struct` es la base porque nos permite tener todos esos campos en un solo lugar, como si fuera una ficha de estudiante.

---

#### 2. `malloc`

La función `malloc` viene de _memory allocation_.

- Sirve para **reservar memoria en tiempo de ejecución**, o sea, cuando el programa ya está corriendo.
    
- Devuelve un puntero a la memoria reservada.
    
- En este ejercicio se usa porque no sabemos de antemano cuánto ocupará cada nombre, apellido o arreglo de notas.
    
- Ejemplo conceptual: si un estudiante se llama “Ana”, `malloc` reserva solo 4 espacios (3 letras + `\0`). Si se llama “Alejandro”, reserva más.
    

**Definición simple**: `malloc` pide memoria del sistema y la pone a disposición del programa.  
**En este caso**: se usa para que cada estudiante solo ocupe lo que necesite (ni más, ni menos).

---

#### 3. `free`

La función `free` sirve para **liberar la memoria** que antes pedimos con `malloc`.

- Si no usamos `free`, la memoria queda ocupada aunque ya no la necesitemos → se llaman _fugas de memoria_.
    
- En este ejercicio, después de terminar con los estudiantes, usamos `free` para devolver todo lo que reservamos.
    

**Definición simple**: `free` devuelve al sistema la memoria que ya no usamos.  
**En este caso**: cuando eliminamos un estudiante, liberamos nombre, apellido, notas y la ficha completa.

---

#### 4. Cadenas dinámicas (`char*`)

En lugar de usar un `char nombre[50]` que siempre ocupa 50 bytes, aunque el nombre tenga solo 3 letras, usamos `char*` con memoria dinámica.

- Así, si un estudiante se llama “Luis”, se reservan solo 5 bytes (4 letras + `\0`).
    
- Esto evita el desperdicio de espacio.
    

 **Definición simple**: una cadena dinámica es un puntero a un bloque de memoria que se ajusta al tamaño real del texto.  
 **En este caso**: se usa para que nombres y apellidos ocupen exactamente lo que deben.

---

#### 5. Arreglos dinámicos (`float*`)

Las calificaciones dependen del número de materias.

- Si usáramos un arreglo fijo, por ejemplo `float notas[10]`, siempre ocuparía espacio para 10 materias aunque el estudiante solo tenga 3.
    
- Con `malloc` creamos un `float*` que ocupa justo lo necesario (ejemplo: 3 espacios si son 3 materias).
    

**Definición simple**: un arreglo dinámico es memoria reservada en tiempo de ejecución para guardar un número variable de elementos.  
**En este caso**: las calificaciones de cada estudiante ocupan solo lo necesario según sus materias.

---

#### 6. Bitfields

Un bitfield es una forma de decirle a C que un campo del `struct` no use todos los bits de un `int`, sino solo los que realmente necesite.

- Ejemplo: la **edad** de una persona nunca será mayor a 127. Con 7 bits alcanza, en vez de usar 32 bits de un `int`.
    
- Lo mismo con el número de identificación: podemos ajustarlo a 24 bits en lugar de 32.
    

**Definición simple**: un bitfield es un campo que ocupa un número limitado de bits, para ahorrar memoria.  
 **En este caso**: lo usamos en edad e identificación para que cada estudiante ocupe menos espacio en memoria.

---

### Abstracción del funcionamiento

Podemos imaginarlo como una **cajita de memoria** para cada estudiante:

- Dentro tiene etiquetas para su nombre y apellido → que ocupan exactamente el espacio necesario.
    
- Un casillero para la edad e identificación → guardados con menos bits, sin desperdicio.
    
- Una lista de calificaciones → que ocupa tantos espacios como materias tenga.
    

Cuando el estudiante ya no se necesita, cerramos la cajita y devolvemos el espacio con `free`.

# Ejercicio 3
## Cálculo lambda

En base al código, se evidencia que la fórmula de la función para calcular el promedio es:

$$
\text{promedio}(L) = \frac{\text{suma}(L)}{\text{longitud}(L)}
$$


En notación de cálculo lambda se puede expresar de forma simplificada como:

$$
\lambda L.\ \frac{\text{foldr } (+)\ 0\ L}{\text{length } L}
$$

---

 Explicación:

- `λ L.` define una función que recibe una lista `L`.
    
- `foldr (+) 0 L` obtiene la suma de los elementos.
    
- `length L` obtiene el tamaño de la lista.
    
- La división representa el promedio.
