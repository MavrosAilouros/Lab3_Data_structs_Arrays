/*
*  Ejercicio 1 – Sum of the diagonals of a square matrix
*  ------------------------------------------------
*  Compile: gcc -Wall Ejercicio1.c -o ej1
*/

 #include <stdio.h>
 #include <stdlib.h>      /* strtol, EXIT_FAILURE       */
 #include <string.h>      /* fgets, strtok, strcspn     */
 #include <limits.h>      /* INT_MIN, INT_MAX           */
 
 #define MAX_N   10       /* Upper matrix size limit - change this number to increase matrix size limit */
 #define ROWBUF 256       /* buffer for rows */
 
 int main(void)
 {
     int  N;              /* matrix size (N × N) */
     char line[64];
 
     /* ----------Read and validate N ---------- */
     for (;;) {
         printf("Introduce el tamaño de la matriz cuadrada (1-%d): ", MAX_N);
 
         if (!fgets(line, sizeof line, stdin))        /* EOF / error */
             return EXIT_FAILURE;
 
         line[strcspn(line, "\n")] = '\0';            /* trim \n */
 
         char *end;
         long val = strtol(line, &end, 10);
 
         if (*end != '\0')
             fprintf(stderr, "Entrada inválida. Debes escribir un número entero.\n");
         else if (val <= 0 || val > MAX_N)
             fprintf(stderr, "El tamaño debe estar entre 1 y %d.\n", MAX_N);
         else { N = (int)val; break; }                /* valid N */
     }
 
     /* --------- Declare VLA after N is valid --------- */
     int matrix[N][N];
 
     puts("\nGuía de entrada: escribe cada fila en una sola línea. \n"
          "\n1. Incluye exactamente los números enteros y de la matriz.\n"
           "\n2. Separados por espacios.\n"
           "\n3. Presiona <Enter> para introducir los numeros.\n");
 
     /* ---------- Read the matrix row by row ---------- */
     char   row[ROWBUF];
     char  *token, *end;
     long   v;
 
     for (int i = 0; i < N; /* i++ only when the row is correct */) {
 
         printf("Fila %d (escribe %d enteros separados por espacios):\n",
                i + 1, N);
 
         if (!fgets(row, sizeof row, stdin)) {
             fprintf(stderr, "Error de lectura.\n");
             return EXIT_FAILURE;
         }
 
         int j = 0;
         token = strtok(row, " \t\r\n");
 
         while (token && j < N) {
             v = strtol(token, &end, 10);
 
             if (*end != '\0' || v < INT_MIN || v > INT_MAX) {
                 j = -1;        /* Marks Invalid row */
                 break;
             }
             matrix[i][j++] = (int)v;
             token = strtok(NULL, " \t\r\n");
         }
 
         if (j == N && token == NULL)      /* Correct row */
             ++i;                          /* Moves on to the next row */
         else
             fprintf(stderr,
                     "Entrada inválida. Debes escribir EXACTAMENTE %d números enteros válidos en una sola línea.\n", N);
     }
 
     /* ---------- Sum the diagonals ---------- */
     long maindiag = 0, secdiag = 0;
 
     for (int i = 0; i < N; ++i) {
         maindiag += matrix[i][i];
         secdiag  += matrix[i][N - 1 - i];
     }
 
     /* ---------- Display results ---------- */
     printf("\nSuma de la diagonal principal: %ld\n", maindiag);
     printf("Suma de la diagonal secundaria: %ld\n", secdiag);
     printf("Suma de ambas diagonales: %ld\n", maindiag + secdiag);
 
     return 0;
 }
 