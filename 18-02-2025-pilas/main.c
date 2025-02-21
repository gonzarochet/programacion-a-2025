#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{

    /*

    Pila pilita, aux1, aux2;
    inicpila(&pilita);
    inicpila(&aux1);
    inicpila(&aux2);

    apilar(&pilita,9);
    apilar(&pilita,6);
    apilar(&pilita,2);
    apilar(&pilita,10);
    apilar(&pilita,5);

    int top = tope(&pilita);

    printf("El tope de la pilita es %d", top);

    mostrar(&pilita);


    apilar(&aux1, desapilar(&pilita));
    apilar(&aux1, desapilar(&pilita));
    apilar(&aux1, desapilar(&pilita));

    apilar(&aux2, desapilar(&pilita));
    apilar(&aux2, desapilar(&pilita));

    printf("\n PILITA: \n");
    mostrar(&pilita);

    printf("\n AUX 1: \n");
    mostrar(&aux1);

    printf("\n AUX 2: \n");
    mostrar(&aux2);



    //mostrar(&pilita);

    */

    //menuOpciones();
    //ejercicio1();


    return 0;
}



void menuOpciones(){

    printf("<<<Ingrese el numero del ejercicio>>>\n\n");
    printf("1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos a la pila AUX1 y los dos restantes a la pila AUX2. \n\n");
    printf("2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO \n\n");
    printf("3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.\n");
    printf("4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden. \n");
    /*printf("5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso. \n");
    printf("6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden. \n");
    printf("7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los restantes elementos en el mismo orden. \n");
    printf("8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa. \n");
    printf("9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado. \n");
    printf("10. Cargar las pilas A y B, y luego compararlas, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado. \n ");
    printf("11. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO. \n");
    printf("12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO. \n");
    printf("13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES. \n");
    printf("14. Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR. (NO contar los elementos) \n");
    printf("15. GUIA 2 - Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.  \n");
    */
}


void ejercicio1(){

    Pila pilita, aux1, aux2;
    inicpila(&pilita);
    inicpila(&aux1);
    inicpila(&aux2);

    apilar(&pilita,9);
    apilar(&pilita,6);
    apilar(&pilita,2);
    apilar(&pilita,10);
    apilar(&pilita,5);

    int top = tope(&pilita);

    printf("El tope de la pilita es %d", top);

    mostrar(&pilita);


    apilar(&aux1, desapilar(&pilita));
    apilar(&aux1, desapilar(&pilita));
    apilar(&aux1, desapilar(&pilita));

    apilar(&aux2, desapilar(&pilita));
    apilar(&aux2, desapilar(&pilita));

    printf("\n PILITA: \n");
    mostrar(&pilita);

    printf("\n AUX 1: \n");
    mostrar(&aux1);

    printf("\n AUX 2: \n");
    mostrar(&aux2);


}






