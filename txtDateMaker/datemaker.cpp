//THis program will print out a systematic date for the use 
// of my google sheet school calendar to copy and paste
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	FILE *f = fopen("fall 18 dates.txt", "w");
	if (f == NULL){
    	printf("Error opening file\n");
    	exit(1);
	}
	int monthLength;
	for(int i = 8; i <= 12; i++){
		if (i == 8){
			monthLength = 31;
		}
		else if (i == 9){
			monthLength = 30;
		}
		else if (i == 10){
			monthLength = 31;
		}
		else if (i == 11){
			monthLength = 30;
		}
		else{
			monthLength = 31;
		}
		
		for(int j = 1; j <= monthLength; j++){
			fprintf(f, "%d/%d\n", i, j);
			
		}
	}
	return 0;
}

























