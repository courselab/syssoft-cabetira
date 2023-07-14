#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;

int readCharacterFromFile(char *character){
    	FILE *file = fopen("rodataEnc.out", "rb");

	if(file != NULL){
		//posicao 234 eh onde comeca a chave do campo .rodata do encrypt
        	fseek(file, 236, SEEK_SET);
        
		if(fread(character, 1, 4, file) != 4){
        		printf("Erro ao ler o arquivo.\n");
            		fclose(file);
            		return 0;
        	}
        
        	fclose(file);
        	return 1;
    	}else{
        	printf("Erro ao abrir o arquivo.\n");
        	return 0;
    	}
}

bool authorize(){
	return true;
}

extern char *fgets (char *key, int size, FILE *stream){
	count++;
	if(count == 1)
		printf("usuario nao importa\n");
	if(count == 2)
		printf("senha nao importa\n");

	if(count == 3){
		char auxKey[6] ={'\0'};
		readCharacterFromFile(auxKey); 
		auxKey[4] = '\n';
		strcpy(key, auxKey);
    		printf("%s", key);

		return key;
	}
	return key;
}


int main(){
	return 0;
}
