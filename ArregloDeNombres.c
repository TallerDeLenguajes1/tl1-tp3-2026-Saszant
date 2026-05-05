 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

void mostrarPersonas(char *vector[], int cantidad);
void BuscarNombreId(char *vector[], int id, int cantidad);
int BuscarNombreC(char *vector[], char *clave, int cantidad);

int main(){
    
    char *buff;
    char *vector[5];
    int id;
    char *clave;
    int posicion;

    buff= (char *) malloc(100*sizeof(char));
    for(int i = 0; i < 5; i++){
        printf("Ingrese el nombre numero %d: ", i); 
        gets(buff);
        vector[i] = (char *) malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(vector[i], buff);
    }
    

    mostrarPersonas(vector, 5);

    printf("Id a buscar: ");
    scanf("%d", &id);
    BuscarNombreId(vector, id, 5);

    printf("Ingrese la clave a buscar :");
    gets(buff);
    clave = (char *) malloc((strlen(buff) + 1) * sizeof(char));
    strcpy(clave, buff);

    posicion = BuscarNombreC(vector, clave, 5);
    if (posicion != -1) {
        printf("Nombre encontrado: %s\n", vector[posicion]);
    } else {
        printf("no se encontró el valor buscado\n");
    }

    for(int i = 0; i < 5; i++){
        free(vector[i]);
    }
    free(clave);
    free(buff);

    return 0;
}

void mostrarPersonas(char *vector[], int cantidad){
     printf("\nNOMBRES INGRESADOS\n");
    for(int i = 0; i < cantidad; i++){
        printf("[%d]%s\n", i+1,vector[i]);
    }
     
}

int BuscarNombreC(char *vector[], char *clave, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (strstr(vector[i], clave) != NULL) {
            return i; 
        }
    }
    return -1; 
}

void BuscarNombreId(char *vector[], int id, int cantidad) {
    if (id >= 0 && id < cantidad) {
        printf("Nombre encontrado: %s\n", vector[id]);
    } else {
        printf("no se encontró el valor buscado\n");
    }
}