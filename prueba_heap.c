#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "heap.h"

/*
 * NOMBRE: Matias Tebele | PADRON: 95372
 * NOMBRE: Lucas Perea | PADRON: 95368
 */

/******************************************************************
 *                		FUNCIONES AUXILIARES
 ******************************************************************/

/* Función auxiliar para imprimir si estuvo OK o no. */
void print_test(char* name, bool result)
{
    printf("* %s: %s\n", name, result? "OK" : "ERROR");
}

int cmp_max(const void *s1, const void *s2)
{
	if (*(int*)s1 < *(int*)s2) return -1;
	if (*(int*)s1 > *(int*)s2) return 1;
	return 0;
}

/******************************************************************
 *						PRUEBAS UNITARIAS
 ******************************************************************/

void prueba_heap_vacio()
{
	printf("-- INICIO PRUEBAS HEAP VACIO --\n");
	heap_t *heap = heap_crear(NULL);
	print_test("El heap fue creado", heap);

	print_test("La cantidad de elementos es 0", heap_cantidad(heap) == 0);
	print_test("Heap esta vacio", heap_esta_vacio(heap));
	print_test("Heap desencolar es NULL", !heap_desencolar(heap));
	print_test("Ver máximo es NULL", !heap_ver_max(heap));
	
	heap_destruir(heap, NULL);
	printf("El heap fue destruido.\n");
}

void prueba_heap_pocos_elementos()
{
	printf("-- INICIO PRUEBAS HEAP POCOS ELEM --\n");
	heap_t *heap = heap_crear(cmp_max);
	print_test("El heap fue creado", heap);

	char *dato1 = "hola";
	char *dato2 = "chau";
	char *dato3 = "blanco";
	char *dato4 = "negro"; 
	
	print_test("Encolo dato1", heap_encolar(heap, dato1));
	print_test("Ver máximo es dato1", heap_ver_max(heap) == dato1);
	print_test("Heap cantidad es 1", heap_cantidad(heap) == 1);
	print_test("Encolo dato2", heap_encolar(heap, dato2));
	print_test("Ver máximo es dato1", heap_ver_max(heap) == dato1);
	print_test("Heap cantidad es 2", heap_cantidad(heap) == 2);
	print_test("Encolo dato3", heap_encolar(heap, dato3));
	print_test("Ver máximo es dato1", heap_ver_max(heap) == dato1);
	print_test("Heap cantidad es 3", heap_cantidad(heap) == 3);
	print_test("Encolo dato4", heap_encolar(heap, dato4));
	print_test("Ver máximo es dato4", heap_ver_max(heap) == dato4);
	print_test("Heap cantidad es 4", heap_cantidad(heap) == 4);
	print_test("Heap no esta vacio", !heap_esta_vacio(heap));

	heap_destruir(heap, NULL);
	printf("El heap fue destruido.\n");
}

void prueba_heap_insertar()
{
	printf("-- INICIO PRUEBAS HEAP INSERTAR --\n");
	heap_t *heap = heap_crear(cmp_max);
	print_test("El heap fue creado", heap);

	char *dato1 = "1";
	char *dato2 = "2";
	char *dato3 = "3";
	char *dato4 = "4"; 
	char *dato5 = "5";
	char *dato6 = "6";
	char *dato7 = "7";
	char *dato8 = "8";	
	
	print_test("Encolo dato3", heap_encolar(heap, dato3));
	print_test("Ver máximo es dato3", heap_ver_max(heap) == dato3);
	print_test("La cantidad de elementos es 1", heap_cantidad(heap) == 1);
	
	print_test("Encolo dato1", heap_encolar(heap, dato1));
	print_test("Ver máximo es dato3", heap_ver_max(heap) == dato3);
	print_test("La cantidad de elementos es 2", heap_cantidad(heap) == 2);
	
	print_test("Encolo dato5", heap_encolar(heap, dato5));
	print_test("Ver máximo es dato5", heap_ver_max(heap) == dato5);
	print_test("La cantidad de elementos es 3", heap_cantidad(heap) == 3);
	
	print_test("Encolo dato2", heap_encolar(heap, dato2));
	print_test("Ver máximo es dato5", heap_ver_max(heap) == dato5);
	print_test("La cantidad de elementos es 4", heap_cantidad(heap) == 4);
	
	print_test("Encolo dato6", heap_encolar(heap, dato6));
	print_test("Ver máximo es dato6", heap_ver_max(heap) == dato6);
	print_test("La cantidad de elementos es 5", heap_cantidad(heap) == 5);
	
	print_test("Encolo dato8", heap_encolar(heap, dato8));
	print_test("Ver máximo es dato8", heap_ver_max(heap) == dato8);
	print_test("La cantidad de elementos es 6", heap_cantidad(heap) == 6);
	
	print_test("Encolo dato7", heap_encolar(heap, dato7));
	print_test("Ver máximo es dato8", heap_ver_max(heap) == dato8);
	print_test("La cantidad de elementos es 7", heap_cantidad(heap) == 7);
	
	print_test("Encolo dato4", heap_encolar(heap, dato4));
	print_test("Ver máximo es dato8", heap_ver_max(heap) == dato8);
	print_test("La cantidad de elementos es 8", heap_cantidad(heap) == 8);

	heap_destruir(heap, NULL);
	printf("El heap fue destruido.\n");
}

void prueba_heap_borrar_cantidad()
{
	printf("-- INICIO PRUEBAS HEAP BORRAR Y CANTIDAD --\n");
	heap_t *heap = heap_crear(cmp_max);
	print_test("El heap fue creado", heap);
	
	char *dato1 = "1";
	char *dato2 = "2";
	char *dato3 = "3";
	char *dato4 = "4";
	char *dato5 = "5";
	char *dato6 = "6";
	
	/*Prueba de un elemento*/
	print_test("Cantidad de heap es 0", heap_cantidad(heap) == 0);
	print_test("Guardo dato1", heap_encolar(heap, dato1));
	print_test("Cantidad de heap es 1", heap_cantidad(heap) == 1);
	print_test("Desencolar devuelve dato1", heap_desencolar(heap) == dato1);
	print_test("Cantidad de heap es 0", heap_cantidad(heap) == 0);
	
	/*Prueba de dos elementos*/
	print_test("Guardo dato1", heap_encolar(heap, dato1));
	print_test("Guardo dato2", heap_encolar(heap, dato2));
	print_test("Cantidad de heap es 2", heap_cantidad(heap) == 2);
	print_test("Desencolar devuelve dato2", heap_desencolar(heap) == dato2);
	print_test("Cantidad de heap es 1", heap_cantidad(heap) == 1);
	print_test("Desencolar devuelve dato1", heap_desencolar(heap) == dato1);
	print_test("Cantidad de heap es 0", heap_cantidad(heap) == 0);
	
	/*Prueba de dos elementos, encolando invertido*/
	print_test("Guardo dato2", heap_encolar(heap, dato2));
	print_test("Guardo dato1", heap_encolar(heap, dato1));
	print_test("Cantidad de heap es 2", heap_cantidad(heap) == 2);
	print_test("Desencolar devuelve dato2", heap_desencolar(heap) == dato2);
	print_test("Cantidad de heap es 1", heap_cantidad(heap) == 1);
	print_test("Desencolar devuelve dato1", heap_desencolar(heap) == dato1);
	print_test("Cantidad de heap es 0", heap_cantidad(heap) == 0);
	
	/*Prueba de tres elementos*/
	print_test("Guardo dato1", heap_encolar(heap, dato1));
	print_test("Guardo dato3", heap_encolar(heap, dato3));
	print_test("Guardo dato2", heap_encolar(heap, dato2));
	print_test("Cantidad de heap es 3", heap_cantidad(heap) == 3);
	print_test("Desencolar devuelve dato3", heap_desencolar(heap) == dato3);
	print_test("Cantidad de heap es 2", heap_cantidad(heap) == 2);
	print_test("Desencolar devuelve dato2", heap_desencolar(heap) == dato2);
	print_test("Cantidad de heap es 1", heap_cantidad(heap) == 1);
	print_test("Desencolar devuelve dato1", heap_desencolar(heap) == dato1);
	print_test("Cantidad de heap es 0", heap_cantidad(heap) == 0);
	
	/*Prueba de seis elementos, intercalando*/
	print_test("Guardo dato3", heap_encolar(heap, dato3));
	print_test("Cantidad de heap es 1", heap_cantidad(heap) == 1);
	print_test("Ver máximo es dato3", heap_ver_max(heap) == dato3);
	
	print_test("Guardo dato1", heap_encolar(heap, dato1));
	print_test("Cantidad de heap es 2", heap_cantidad(heap) == 2);
	print_test("Ver máximo es dato3", heap_ver_max(heap) == dato3);
	
	print_test("Desencolar devuelve dato3", heap_desencolar(heap) == dato3);
	print_test("Cantidad de heap es 1", heap_cantidad(heap) == 1);
	print_test("Ver máximo es dato1", heap_ver_max(heap) == dato1);
	
	print_test("Guardo dato4", heap_encolar(heap, dato4));
	print_test("Cantidad de heap es 2", heap_cantidad(heap) == 2);
	print_test("Ver máximo es dato4", heap_ver_max(heap) == dato4);
	
	print_test("Guardo dato6", heap_encolar(heap, dato6));
	print_test("Cantidad de heap es 3", heap_cantidad(heap) == 3);
	print_test("Ver máximo es dato6", heap_ver_max(heap) == dato6);
	
	print_test("Desencolar devuelve dato6", heap_desencolar(heap) == dato6);
	print_test("Cantidad de heap es 2", heap_cantidad(heap) == 2);
	print_test("Ver máximo es dato4", heap_ver_max(heap) == dato4);
	
	print_test("Desencolar devuelve dato4", heap_desencolar(heap) == dato4);
	print_test("Cantidad de heap es 1", heap_cantidad(heap) == 1);
	print_test("Ver máximo es dato1", heap_ver_max(heap) == dato1);
	
	print_test("Guardo dato5", heap_encolar(heap, dato5));
	print_test("Cantidad de heap es 2", heap_cantidad(heap) == 2);
	print_test("Ver máximo es dato5", heap_ver_max(heap) == dato5);
	
	print_test("Guardo dato2", heap_encolar(heap, dato2));
	print_test("Cantidad de heap es 3", heap_cantidad(heap) == 3);
	print_test("Ver máximo es dato5", heap_ver_max(heap) == dato5);
	
	print_test("Desencolar devuelve dato5", heap_desencolar(heap) == dato5);
	print_test("Cantidad de heap es 2", heap_cantidad(heap) == 2);
	print_test("Ver máximo es dato2", heap_ver_max(heap) == dato2);
	
	print_test("Desencolar devuelve dato2", heap_desencolar(heap) == dato2);
	print_test("Cantidad de heap es 1", heap_cantidad(heap) == 1);
	print_test("Ver máximo es dato1", heap_ver_max(heap) == dato1);
	
	print_test("Desencolar devuelve dato1", heap_desencolar(heap) == dato1);
	print_test("Cantidad de heap es 0", heap_cantidad(heap) == 0);
	print_test("Ver máximo es NULL", !heap_ver_max(heap));
	print_test("Heap desencolar es NULL", !heap_desencolar(heap));
	print_test("Heap esta vacio", heap_esta_vacio(heap));
	
	heap_destruir(heap, NULL);
	printf("El heap fue destruido.\n");
}

void prueba_heap_volumen(size_t largo) 
{
	printf("-- INICIO PRUEBAS HEAP DE VOLUMEN --\n");
	
	heap_t *heap = heap_crear(cmp_max);
	print_test("El heap fue creado", heap);

	int* valores[largo];	
	srand(time(NULL));

	/* Inserta 'largo' datos en el heap*/
	bool ok = true;
	for (int i = 0; i < largo; i++) {
		valores[i] = malloc(sizeof(int));
		int rand_dato = rand() % (largo * 2);
		
		*valores[i] = rand_dato;
		ok = heap_encolar(heap, valores[i]);
		if (!ok) break;
	}

	print_test("Prueba heap almacenar muchos elementos", ok);
	print_test("Prueba heap la cantidad de elementos es correcta", heap_cantidad(heap) == largo);

	for (int i = 0; i < largo; i++) {
		void *max = heap_ver_max(heap);
		void *dato = heap_desencolar(heap);
		ok = dato == max;
		free(dato);
		if (!ok) break;
	}

	print_test("Prueba heap desencolar muchos elementos", ok);
	print_test("Prueba heap la cantidad de elementos es correcta", heap_cantidad(heap) == 0);

	heap_destruir(heap, free);
	printf("El heap fue destruido.\n");
}

void prueba_heapsort(size_t largo)
{
	printf("-- INICIO PRUEBAS HEAPSORT --\n");
	
	int** datos = malloc(largo * sizeof(int*));	
	srand(time(NULL));
	
	/* Carga el vector con datos random */
	for (int i = 0; i < largo; i++) {
		datos[i] = malloc(sizeof(int));
		*datos[i] = rand() % largo;
	}

	/* Heapsort */
	heap_sort((void**)datos, largo, cmp_max);	
	
	/* Compara el dato actual con el siguiente */
	bool ok = true;
	for (int i = 0; i < largo-1; i++) {		
		int cmp = cmp_max(datos[i], datos[i+1]);
		ok = (cmp <= 0);
		if (!ok) break;
	}
	
	/* Libera los datos del vector */
	for (int i = 0; i < largo; i++)
		free(datos[i]);

	free(datos);
	print_test("Prueba heapsort", ok);
}
/******************************************************************
 *						PROGRAMA PRINCIPAL
 ******************************************************************/

int main()
{
	prueba_heap_vacio();
	prueba_heap_pocos_elementos();
	prueba_heap_insertar();
	prueba_heap_borrar_cantidad();
	prueba_heap_volumen(10000);
	prueba_heapsort(10000);
	return 0;
}
