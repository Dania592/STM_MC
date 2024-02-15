#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10

int fibo(int x, int y);
int fibo_suite[TAB_SIZE]={0};
void fibo_asm();

int current_x;
int current_y;
int res;

int main (void){
	
	fibo_suite[0] = 0;
	fibo_suite[1] = 1;
	int x;
	int y;

	// test suite fibonacci version C
	for(int i = 2; i < 10; i++){
		x = i-2;
		y = i-1;
		current_x = fibo_suite[x];
		current_y = fibo_suite[y];
		fibo_asm();
		fibo_suite[i] = res;
	}
	
	
	//Infinite loop
	while(1){
		
	}
	
	return 0;
}

int fibo(int x, int y){ 
	int fn_2 = fibo_suite[x];
	int fn_1 = fibo_suite[y];
	return fn_1 + fn_2;
}

void fibo_asm(){

		asm("LDR R1, =current_x "); // fn-2
		asm("LDR R1, [R1]");

		asm("LDR R2, =current_y "); // fn-1
		asm("LDR R2, [R2]");

		asm("ADD R2, R2, R1"); // Fn-1 + Fn-2
		
		asm("LDR R6, =res"); // i+2
		asm("STR R2, [R6]");
	
	
}
