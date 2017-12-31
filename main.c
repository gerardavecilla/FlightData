#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	typedef struct acars_struct{
		char flight[7] ;
		char dest[5] ;
		char origin[5] ;
		int dateTimeStamp ;
		struct acars_struct* next ;
	} AcarsStruct ;
	
	FILE* inFile = NULL;
	inFile = fopen("acars.bin", "rb");
		if(inFile == NULL){
			return -1;
		}
		
	AcarsStruct* head;
	AcarsStruct* tail;
	AcarsStruct* temp;
	
	temp = (AcarsStruct*) malloc(sizeof(AcarsStruct));
	fread(temp, sizeof(AcarsStruct) - sizeof(AcarsStruct*), 1, inFile);
	temp->next = NULL;
	head = temp;
	tail = head;
	time_t t = head->dateTimeStamp;
	printf("%s, %s, %s, %s\n", head->flight, head->origin, head->dest, ctime(&t));
	
	while(!feof(inFile)){
		temp = (AcarsStruct*) malloc(sizeof(AcarsStruct));
		fread(temp, sizeof(AcarsStruct) - sizeof(AcarsStruct*) , 1, inFile);
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
		time_t t = tail->dateTimeStamp;
		printf("%s,  %s,  %s,  %s\n", tail->flight, tail->origin, tail->dest, ctime(&t));
	}
	return 0;
}
