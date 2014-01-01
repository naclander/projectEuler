#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//I solved this problem by finding all permutations of the TARGET string
//and then sorting the permutations. This is of course not the optimal way
//of solving this problem. 
//TODO: solve this problem using lexographic permutation function.

#define TARGET "0123456789"
char * STRINGS[400000000];

typedef struct cstring_vector{
	char * strings;
	int size;
} cstring_vector_t;

cstring_vector_push(cstring_vector_t * vec, char * string){
	STRINGS[vec->size] = malloc(strlen(string) * sizeof(char));
	strcpy(STRINGS[vec->size],string);
	vec->size++;
}

static int cmpstringp(const void *p1, const void *p2){
	return strcmp(* (char * const *) p1, * (char * const *) p2);
}

cstring_vector_sort(cstring_vector_t * vec){
	qsort(STRINGS, vec->size, sizeof(char * ), cmpstringp);
}

void swap(char * x, char * y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//permute function from GeeksForGeeks
void permute(char *a, int i, int n, cstring_vector_t * vec) {
	int j; 
	if (i == n){
		cstring_vector_push(vec,a);
	}
	else
	{
	for (j = i; j <= n; j++)
    	{
        	swap((a+i), (a+j));
        	permute(a, i+1, n,vec);
        	swap((a+i), (a+j)); 
      	}
   	}
}

int main(){
	cstring_vector_t permutations;
	permutations.size = 0;
	char s[] = TARGET;
	permute(s,0,strlen(s) - 1,&permutations);
	cstring_vector_sort(&permutations);
	printf("%s\n",STRINGS[999999]);
}
