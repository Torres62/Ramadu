#include <stdio.h>
#include <SPI.h>
#include <PN532_SPI.h>
#include "PN532.h"
#include "Funcoes.h"

PN532_SPI pn532spi(SPI, 10);
PN532 nfc(pn532spi);

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
	if (option >= 0 && option <= 3) {
		return 1;
	} else {
		return 0;
	}
}

int startReader(){
	nfc.begin();
	Reader reader;
	
	/* Get firmware version of the reader */
	reader.versiondata = nfc.getFirmwareVersion();	
	
	/* Check if a reader was found */
	if(! reader.versiondata){	
		Serial.print("Placa PN53x nao encontrada");
		return 0;
		while(1);	/* halt */
	}
	
	/* Print results */
	Serial.print("Chip PN5 encontrado ");
	Serial.println((reader.versiondata>>24) & 0xFF, HEX);
	Serial.print("Versao do firmware ");
	Serial.print((reader.versiondata>>16) & 0xFF, DEC);
	Serial.print('.');
	Serial.println((reader.versiondata>>8) & 0xFF, DEC);
	
	/* Set max number of retry attempts to read from a card
	This prevents us from waiting forever for a card */
	nfc.setPassiveActivationRetries(0xFF);
	
	/* Configure boar to read RFID tags */
	nfc.SAMConfig();
	
	Serial.println("Aguardando uma tag ISO14443A");
	
	return 1;
}

int readTag(){
	boolean success;
	Tag tag;
	tag.uid[] = {0,0,0,0,0,0,0};
	tag.uidLength = 0;
	int i = 0;
	
	success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A,&tag.uid[0],&tag.uidLength);
	
	if(success){
		Serial.println("Tag lida");
		Serial.print("Tamanho do UID: ");
		Serial.print(tag.uidLength, DEC);
		Serial.println(" bytes");
		Serial.print("Valor do UID: ");
		for(i = 0; i < tag.uidLength; i++){
			Serial.print("Ox");
			Serial.print(tag.uid[i], HEX);
		}
		
		Serial.println("");
		delay(1000);
		return 1;
	}else{
		Serial.println("Nenhuma tag lida");
		return 0;
	}
	
}
