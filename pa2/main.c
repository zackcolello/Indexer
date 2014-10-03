/*
 *main.c
 */

#include	<string.h>
#include	"sorted-list.h"
#include	<stdlib.h>
#include	<stdio.h>

int compareInts(void *p1, void *p2)
{
	printf("p1 is %d and p2 is %d \n", p1, p2);

	int i1 = *(int*)p1;
	int i2 = *(int*)p2;

	printf("about to return from compareInts\n");
	return i1 - i2;
}

int compareDoubles(void *p1, void *p2)
{
	double d1 = *(double*)p1;
	double d2 = *(double*)p2;

	return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}

int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}

//Destructor functions
void destroyBasicTypeAlloc(void *p){
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for allocated memory (malloc,calloc,etc.)
	free(p);
}

void destroyBasicTypeNoAlloc(void *p) {
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for memory that has not been allocated (e.g., "int x = 5;SLInsert(mylist,&x);SLRemove(mylist,&x);")
	return;
}


void buildList(SortedListPtr list, int listSize){

	int randNum;
	int i;
	srand(time(NULL));

	void* i1 =(int*)malloc(sizeof(int));
	
	
	for (i = 0; i < listSize; i++){
		i1 = rand() % 50;
		SLInsert(list, i1);
	}

}

int main()
{
	SortedListPtr list = (SLCreate(compareInts, destroyBasicTypeNoAlloc));
	
	//SLInsert(list, (void*)5); //cast as int to make compiler happy

	//printf("%d\n", (int)list->head->data);

	buildList(list, 10);


//	void *data = malloc(sizeof(list->head->data));
	//data = list->head->data;

	//printf("%d\n", *((int*)data));

	return 0;

}
