#include<stdio.h>
#include"Funcoes.h"
#include"Struct.h"

int main(int argc, char** argv[]) {
  
  int uidTag[7], int uidLength;
  char tempUidTag[7];
  
  int arraySize = 0;
  
  printf("\nDigite o tamanho da lista de Tags: ");
  scanf("%i", &arraySize);
  
  Tag *tags = calloc(arraySize, sizeof(Tag));
  
  for(int i = 0; i < arraySize; i++) {
    
    printf("\nDigite a UID da Tag: ");
    scanf("%s", &tempUidTag);
    
    for(int j = 0; j < 7; j++) {
      uidTag[i] = (int) tempUidTag[i];
    }
    
    printf("\nDigite o peso da Tag: ");
    scanf("%i", &uidLength);
    
    includeTag(uidTag, uidLength);
  }
  
}
