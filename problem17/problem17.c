#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//I solved this problem by creating a sting for each number and then counting
//all the letters in that string. In retrospect creating the string was not
//necessary as I could have counted letters without creating a stirng. However,
//creating the string and being able to print it out prooved helpfull when 
//debugging.

int get_digits(int num){
	int number = num;
	int digits = 0;
	while(number != 0){
		number /= 10;
		digits++;
	}
	return(digits);
}

int count_letters(char * string){
	int count = 0;
	int i;
	for(i = 0; i < strlen(string); i++){
		if(string[i] != ' '){
			count++;
		}
	}
	return(count);
}

void get_decimal(int num, char * string){
	switch(num){
		case 0:
			strcpy(string,"\0");
			break;
		case 1:
			strcpy(string,"one ");
			break;
		case 2:
			strcpy(string,"two ");
			break;
		case 3:
			strcpy(string,"three ");
			break;
		case 4:
			strcpy(string,"four ");
			break;
		case 5:
			strcpy(string,"five ");
			break;
		case 6:
			strcpy(string,"six ");
			break;
		case 7:
			strcpy(string,"seven ");
			break;
		case 8:
			strcpy(string,"eight ");
			break;
		case 9:
			strcpy(string,"nine ");
			break;
		case 10:
			strcpy(string,"ten ");
			break;
		case 11:
			strcpy(string,"eleven ");
			break;
		case 12:
			strcpy(string,"twelve ");
			break;
		case 13:
			strcpy(string,"thirteen ");
			break;
		case 14:
			strcpy(string,"fourteen ");
			break;
		case 15:
			strcpy(string,"fifteen ");
			break;
		case 16:
			strcpy(string,"sixteen ");
			break;
		case 17:
			strcpy(string,"seventeen ");
			break;
		case 18:
			strcpy(string,"eighteen ");
			break;
		case 19:
			strcpy(string,"nineteen ");
			break;
	}
	return;
}

void get_tens(int num, char * string){
	switch(num){
		case 2:
			strcpy(string,"twenty ");
			break;
		case 3:
			strcpy(string,"thirty ");
			break;
		case 4:
			strcpy(string,"forty ");
			break;
		case 5:
			strcpy(string,"fifty ");
			break;
		case 6:
			strcpy(string,"sixty ");
			break;
		case 7:
			strcpy(string,"seventy ");
			break;
		case 8:
			strcpy(string,"eighty ");
			break;
		case 9:
			strcpy(string,"ninety ");
			break;
	}
	return;
}

void num_to_string(int num, char * string){
	char temp_string[100];
	temp_string[0] = '\0';
	int digits = get_digits(num);
	int use_and= 0;
	
	if(digits == 4){
		strcat(string,"one thousand");
		return;
	}
	if(digits == 3){
		int third_digit = num / 100;
		get_decimal(third_digit,temp_string);
		strcat(string,temp_string);
		strcat(string,"hundred ");
		digits--;
		if( ((num/10) % 10) != 0 ||  num%10 != 0){
			use_and = 1;	
		}
	}
	if(digits == 2){
		if(use_and){
			strcat(string,"and ");
		}	
		int second_digit = (num/10) % 10;
		if(second_digit < 2){
			if(second_digit == 1){
				get_decimal(num%100,temp_string);
			}
			if(second_digit == 0){
				get_decimal(num%10,temp_string);
			}
			strcat(string,temp_string);
			return;
		}
		get_tens(second_digit,temp_string);
		strcat(string,temp_string);
		digits--;
	}
	
	if(digits == 1){
		int first_digit = num%10;
		get_decimal(first_digit,temp_string);
		strcat(string,temp_string);
	}
	return;
}

int main(){
	int sum = 0;
	int i;
	for(i = 1; i <= 1000; i++){
		char * num_string = malloc(1024*sizeof(char));
		num_string[0] = '\0';
		num_to_string(i, num_string);
		sum += count_letters(num_string);
		free(num_string);
	}
	printf("%d\n",sum);
}
