#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

void stackHeapExample();
int numberInput();
void makeCatMeow(int n);

int main(){
	//stackHeapExample();
	makeCatMeow(numberInput());


	_CrtDumpMemoryLeaks();
	return 0;
}

void stackHeapExample() {
	int *ptr = malloc(sizeof(int)); // Heap Pointer
	int x = 10; // Stack Variable
	int *numPtr = &x; // Pointer to stack memory
	if (!ptr) {
		printf("Allocation Failed\n");
		return 1;
	}
	*ptr = 10; // Heap definition
	printf("Value stored: %d\n", *ptr);
	free(ptr); // Must free heap
} // Stack memory which includes numPtr, gets freed after code block/function scope ends

// TODO: Catch empty inputs/"enter only" inputs
int numberInput() {
	char input[20] = "";
	int num = 0;
	printf("Please enter a number: ");
	while (1) {
		scanf_s("%19s", input, (unsigned)_countof(input));
		num = atoi(input);
		if (num <= 0) {
			printf("\nThe value should be positive or numeric!\n");
		}
		else {
			return num;
		}
	}
}

void makeCatMeow(int n) {
	printf("\n-----MEOW SIMULATOR 5000-----\n");
	int num = 1;
	while (n > 0) {
		printf("%d: Meow\n", num);
		--n;
		++num;
	}
}