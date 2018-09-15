#include <stdio.h>
#include "Funcoes.h"

/**
 * Show the menu with the options for the user choose
 */
void showMainMenu() {
	printf("+--------------------+\n");
	printf("|***MENU PRINCIPAL***|\n");
	printf("+--------------------+\n");
	printf("| 1 - Cadastrar Tag  |\n");
	printf("| 2 - Deletar Tag    |\n");
	printf("+--------------------+\n");
	printf("| 3 - Iniciar        |\n");
	printf("+--------------------+\n");
	printf("| 0 - Sair           |\n");
	printf("+--------------------+\n");
}

/**
 * Read the option typed from the user
 */ 
void readMenuOption() {
	int option = -1;
	do {
		scanf("%i", &option);
	} while(isValidateOption(option) == 0);
	
	switch (option) {
		
		// Cadastrar Tag
		case 1:
			
			break;
			
		// Deletar Tag
		case 2:
			
			break;
			
		// Iniciar
		case 3:
			
			break;
			
		// Sair
		case 0:
			
			break;
		
		default:
			break;
	}
}

/**
 * Validate input of user
 * Return 1 if is valid, 0 otherwise
 */ 
int isValidateOption(int option) {
	if (i >= 0 && i <= 3) {
		return 1;
	} else {
		return 0;
	}
}
