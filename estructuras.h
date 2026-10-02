/**
 * @file estructuras.h
 * @brief Definición de las estructuras de datos fundamentales para el simulador de navegación.
 * 
 * Cumple con la consigna de incluir al menos 3 estructuras de datos distintas:
 * 1. Coordenada / Punto (Matriz)
 * 2. Cola (Queue) para la exploración BFS
 * 3. Pila (Stack) para la reconstrucción del camino
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <stdbool.h>

#define MAX_MAPA_SIZE 100

// ==========================================
// 1. ESTRUCTURA: POSICIÓN / PUNTO (MATRIZ)
// ==========================================
typedef struct {
    int x;
    int y;
} Punto;

// ==========================================
// 2. ESTRUCTURA: COLA (QUEUE) - PARA BFS
// ==========================================
// Utilizada por el algoritmo de búsqueda en anchura para almacenar las celdas a visitar.

typedef struct NodoCola {
    Punto dato;
    struct NodoCola* siguiente;
} NodoCola;

typedef struct {
    NodoCola* frente;
    NodoCola* final;
    int tamano;
} Cola;

// Prototipos de funciones para manejo de Cola
void inicializarCola(Cola* c);
bool colaVacia(const Cola* c);
bool encolar(Cola* c, Punto p);
Punto desencolar(Cola* c);
void liberarCola(Cola* c);

// ==========================================
// 3. ESTRUCTURA: PILA (STACK) - PARA CAMINO
// ==========================================
// Utilizada para invertir el camino hallado (desde destino hacia inicio) y mostrarlo en orden correct.

typedef struct NodoPila {
    Punto dato;
    struct NodoPila* siguiente;
} NodoPila;

typedef struct {
    NodoPila* tope;
    int tamano;
} Pila;

// Prototipos de funciones para manejo de Pila
void inicializarPila(Pila* p);
bool pilaVacia(const Pila* p);
bool apilar(Pila* p, Punto pt);
Punto desapilar(Pila* p);
void liberarPila(Pila* p);

// ==========================================
// FUNCIONES DE UTILIDAD AUXILIAR
// ==========================================
bool puntosIguales(Punto p1, Punto p2);

#endif // ESTRUCTURAS_H