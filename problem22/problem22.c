#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//This problem was solved by adding each name in names.txt to an array of 
//c strings. The array was then sorted using qsort and the name score of each
//element was calculated and added together. 
//
//I made two assumptions in this problem for code simplicity. First, the 
//strings array in cstring_vector is set to 6000 elements. Naturally checking 
//if we are going over this boundary needs to be done, and a new, bigger 
//strings array needs to be allocated. Second, the temp buffer to hold the 
//strings while reading them in fromfile is set to 100 bytes. Like before
//a check needs to be done if we are reading past the buffer.

typedef struct cstring_vector{
	char * strings[6000];
	int size;
} cstring_vector_t;

cstring_vector_push(cstring_vector_t * vec, char * string){
	vec->strings[vec->size] = malloc(strlen(string) * sizeof(char));
	strcpy(vec->strings[vec->size],string);
	vec->size++;
}

static int cmpstringp(const void *p1, const void *p2){
	return strcmp(* (char * const *) p1, * (char * const *) p2);
}

cstring_vector_sort(cstring_vector_t * vec){
	qsort(vec->strings, vec->size, sizeof(char * ), cmpstringp);
}

int string_value(char * string){
	int sum = 0;
	int i;
	for(i = 0; i < strlen(string); i++){
		sum += string[i] - 64;
	}
	return(sum);
}

int main(){
	cstring_vector_t names;
	names.size = 0;
	char buffer[100];
	int buffer_it = 0;
	FILE * file;
	file = fopen("names.txt", "r");
	if(!file){
		printf("Error opening file\n");
	}
	char c;
	int inside_string = 0;
	while(( c = fgetc(file)) != EOF){
		if(c == '"' && !inside_string){
			inside_string = 1;
			buffer_it = 0;
		}
		else if( c == '"' && inside_string){
			buffer[buffer_it] = '\0';
			cstring_vector_push(&names,buffer);
			inside_string = 0;
		}	
		else if(inside_string){
			buffer[buffer_it] = c;
			buffer_it++;
		}
	}
	cstring_vector_sort(&names);
	unsigned int sum = 0;
	int i;
	for(i = 0; i < names.size; i++){
		sum += string_value(names.strings[i]) * (i + 1);
	}
	printf("%d\n",sum);
}
