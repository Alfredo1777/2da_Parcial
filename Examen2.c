#include <stdio.h>
#include <stdlib.h>

int l[9];


void examen(int *l, int n){
    for(int i=0; i < n; i++){
        int min = i;

        for(int j=i+1; j<n; j++){
            if(l[j] < l[min]){
                min = j;
            }
        }
        if(min != i){
            int key = l[min];
            l[min] = l[i];
            l[i] = key;
        }
    }
}
void pantalla(int *l, int n){
	for(int i = 0; i < n-1; i++)
		printf("%d, ", l[i]);
	printf("%d", l[n-1]);
	printf("\n");
}

void leer_archivo(){
	FILE* archivo;
	char c, texto[20];
	int j=0, i=0;

	archivo = fopen("numeros.txt","rt");
	do{
		c = fgetc(archivo);
		if (c == ',') {
			l[j] = atoi(texto);
			j++;
			for (int z = 0; z<i; z++)
				texto[z]=0;
			i=0;
			continue;
		}
		texto[i] = c;
		i++;
	}while(c!= EOF);
}
int main(){
    int n = 9;
    leer_archivo();
    printf("Valoresv1: ");
    pantalla(l, n);
    examen(l, n);
    printf("Valoresv2: ");
    pantalla(l, n);
    printf("\n");
}
