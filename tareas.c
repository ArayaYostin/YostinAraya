#include <stdio.h>
#include <stdlib.h>

//Funcion que suma los minutos de las k tareas de un ramo
int sumarMinutos(int *ramo, int k){
    int minutos = 0;
    for(int i = 0; i < k; i++){
        minutos += ramo[i];
    }
    return minutos;
}

//Funcion que cuenta cuantas tareas hay en total entre los r ramos
int contarTareas(int *cantidad, int r){
    int total = 0;
    for(int i = 0; i <= r; i++){
        total += cantidad[i];
    }
    return total;
}

//Funcion que busca el dia con mas minutos de tareas por entregar (si hay empate, el primero)
int diaMasPesado(int *porDia){
    int dia = 1;
    for(int d = 2; d <= 7; d++){
        if(porDia[d] > porDia[dia]){
            dia = d;
        }
    }
    return dia;
}

//Programa para organizar las tareas atrasadas de la u
int main(){
    int r;
    scanf("%d", &r);

    //porDia es un arreglo con los minutos de las tareas que se entregan en cada día (1-7)
    int *porDia = malloc(7 * sizeof(int));
    for(int d = 1; d <= 7; d++){
        porDia[d] = 0;
    }

    //tareas[i][j] son los minutos que toma la tarea j del ramo i
    int **tareas = malloc(r * sizeof(int *));
    int *cantidad = malloc(r * sizeof(int));
    for(int i = 0; i < r; i++){
        scanf("%d", &cantidad[i]);                      //Cantidad de tareas del ramo i
        tareas[i] = malloc(cantidad[i] * sizeof(int));
        for(int j = 0; j < cantidad[i]; j++){
            int entrega;
            scanf("%d %d", &tareas[i][j], &entrega);    //Minutos y dia de entrega de tarea j
            porDia[entrega] += tareas[i][j];
        }
    }

    int *minutos = malloc(r * sizeof(int));
    for(int i = 0; i < r; i++){
        if(cantidad[i] > 0){
            minutos[i] = sumarMinutos(tareas[i], cantidad[i]);
        }
    }

    int masAtrasado = 0;
    for(int i = 0; i < r; i++){
        printf("Ramo %d: %d minutos\n", i + 1, minutos[i]);
        if(minutos[i] > minutos[masAtrasado]){
            masAtrasado = i;
        }
    }
    printf("Ramo mas atrasado: %d\n", masAtrasado + 1);
    printf("Total de tareas: %d\n", contarTareas(cantidad, r));

    int dia = diaMasPesado(porDia);
    printf("Dia mas pesado: %d (%d minutos)\n", dia, porDia[dia]);

    free(minutos);
    free(cantidad);
    free(porDia);
    free(tareas);
    return 0;
}
