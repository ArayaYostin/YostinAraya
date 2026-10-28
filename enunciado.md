# Tareas atrasadas

Luego de tener su caja de mandarinas lista para la feria, perfectamente equilibrada, como todo debe ser, se tropezó y la gran mayoría de las mandarinas quedó inutilizable.

Después de esto volvió a su casa triste y se acordó de que por andar con las mandarinas tiene tareas de la u atrasadas.

Para poder organizarse, un compañero que le gusta hacer códigos para cualquier cosa, le prestó un programa que hizo, `tareas.c`. Este programa anota los minutos que le va a tomar hacer cada tarea pendiente de cada ramo y el día de la semana de la entrega.

Usted hace unos casos de prueba que entregan los resultados esperados, pero de todas maneras, quiere verificar por su cuenta el código para no llevarse más sorpresas, por lo que decide revisarlo con valgrind.

## Entrada

La primera línea contiene la cantidad de ramos $1 \leq R \leq 10$.

Le siguen $R$ líneas, una por ramo. Cada una parte con la cantidad de tareas pendientes de ese ramo, $0 \leq K \leq 10$, seguida de $K$ pares de enteros: los minutos que toma la tarea (entre 1 y 300) y el día en que se entrega (1 lunes - 7 domingo). 

Si un ramo tiene $K = 0$, no tiene tareas pendientes.

## Salida

Imprime:

1. Una línea por ramo: `Ramo i: M minutos`, con los minutos que suman sus tareas.
2. `Ramo mas atrasado: i`: el ramo con más minutos de tareas. Si hay empate, el de menor número.
3. `Total de tareas: T`: la cantidad de tareas pendientes entre todos los ramos.
4. `Dia mas pesado: d (M minutos)`: el día con más minutos de tareas por entregar y cuántos son. Si hay empate, el primero de la semana.

## Qué hacer

El programa tiene **4 errores de memoria**.

1. Compruebe con `probar.sh` que el programa entrega la salida esperada en los tres casos.
2. Revise el programa con valgrind. La línea para hacerlo está comentada en `probar.sh`.
3. Corrija un error a la vez y vuelva a ejecutar valgrind después de cada corrección. **Por cada error, complete en el `README.md`**:
    - Tipo de error que reporta valgrind
    - Línea del código donde está
    - Corrección.
4. Cree el caso de prueba `testCases/case_04.in`, con su respuesta en `case_04.ans`, en el que **el ramo más atrasado sea el último y el día más pesado sea el domingo**. En el `README.md`, explique cómo se llega a esa respuesta, de manera similar al ejemplo de abajo.

El código estará libre de errores cuando valgrind diga que no hay ningún error para los 4 casos y que todos los bloques fueron liberados, junto con una salida correcta.

## Entrega

Suba a AULA un `.zip` con `tareas.c` corregido, el `README.md` completo y los archivos `case_04.in` y `case_04.ans`.

**Extra (+20 puntos para un ticket de salida):** suba la carpeta del ticket al repositorio de GitHub que creó en el laboratorio pasado y ponga el link en el `README.md`. Sólo válido si el repositorio fue creado el miércoles pasado.

## Ejemplo

### Entrada
```
3
2 90 3 45 1
3 60 3 30 5 20 2
1 120 4
```
### Salida
```
Ramo 1: 135 minutos
Ramo 2: 110 minutos
Ramo 3: 120 minutos
Ramo mas atrasado: 1
Total de tareas: 6
Dia mas pesado: 3 (150 minutos)
```
### Explicación
```
Ramo 1: 90 (miercoles) + 45 (lunes)                 = 135 minutos
Ramo 2: 60 (miercoles) + 30 (viernes) + 20 (martes) = 110 minutos
Ramo 3: 120 (jueves)                                = 120 minutos
El miercoles se entregan 90 + 60 = 150 minutos de tareas
```
