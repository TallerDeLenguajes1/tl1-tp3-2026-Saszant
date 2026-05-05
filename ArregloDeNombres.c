 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

void mostrarPersonas(char *vector[], int cantidad);
void BuscarNombre(char *vector[], int id, int cantidad);

int main(){

    char *buff;
    char *nombre;
    char *vector[5];
    int id;

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
    BuscarNombre(vector, id, 5);


    for(int i = 0; i < 5; i++){
        free(vector[i]);
    }
    free(buff);

    return 0;
}

void mostrarPersonas(char *vector[], int cantidad){
     printf("\nNOMBRES INGRESADOS\n");
    for(int i = 0; i < cantidad; i++){
        printf("[%d]%s\n", i+1,vector[i]);
    }
     
}

void BuscarNombre(char *vector[], int id, int cantidad) {
    if (id >= 0 && id < cantidad) {
        printf("Nombre encontrado: %s\n", vector[id]);
    } else {
        printf("no se encontró el valor buscado\n");
    }
}