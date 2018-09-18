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

bool startReader(bool result){
	nfc.begin();
	
	/* Get firmware version of the reader */
	uint32_t versiondata = nfc.getFirmwareVersion();	
	
	/* Check if a reader was found */
	if(! versiondata){	
		Serial.print("Placa PN53x nao encontrada");
		while(1);	/* halt */
	}
	
	/* Print results */
	Serial.print("Chip PN5 encontrado ");
	Serial.println((versiondata>>24) & 0xFF, HEX);
	Serial.print("Versao do firmware ");
	Serial.print((versiondata>>16) & 0xFF, DEC);
	Serial.print('.');
	Serial.println((versiondata>>8) & 0xFF, DEC);
	
	/* Set max number of retry attempts to read from a card
	This prevents us from waiting forever for a card */
	nfc.setPassiveActivationRetries(0xFF);
	
	/* Configure boar to read RFID tags */
	nfc.SAMConfig();
	
	Serial.println("Aguardando uma tag ISO14443A");
}
