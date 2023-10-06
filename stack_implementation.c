#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
void push(int64_t const stack_size, int64_t stack[stack_size], int64_t const x);
void pop(int64_t const stack_size, int64_t stack[stack_size]);
bool stack_empty(int64_t const stack_size, int64_t stack[stack_size]);
int64_t *mkstack(int64_t *stack_size);
int64_t stack_top = -1;
enum {PUSH, POP, PRINT, IS_EMPTY, CURRENT_INDEX, EXIT};
int main(void){
	int64_t *stack = NULL;
	int64_t stack_size;
	int64_t select;
	int64_t x;
	stack = mkstack(&stack_size);
	do{
		puts("------------------------------------------------");
		printf("To push to stack, press '0'\n" 
						"To pop stack, press '1'\n"
						"To print stack, press '2'\n"		
						"To check if stack is empty, press '3'\n"
						"To print current index, press '4' \n"
						"To exit, press '5'\n");
		scanf("%ld", &select);
		switch(select){
			case PUSH: 
				printf("Enter number to insert on stack: ");
				scanf("%ld", &x);
				push(stack_size, &stack[0], x);
				break;
			case POP:
				pop(stack_size, &stack[0]);
				break;
			case PRINT:
				for (int64_t i = 0; i <= stack_top; ++i){
					printf("S[%ld] = %ld\n", i, stack[i]);
				}
				break;
			case IS_EMPTY:
				if (stack_empty(stack_size, &stack[0])){
					printf("Stack is emtpy\n");
				}
				else {
					printf("There are objects in the stack\n");
				}
				break;
			case CURRENT_INDEX: 
				printf("stack_top = %ld\n", stack_top);
				break;
			case EXIT:
				puts("Exitting program");
		}

	}while (select == PUSH		 ||
					select == POP			 ||
					select == PRINT		 ||
					select == IS_EMPTY ||
					select == CURRENT_INDEX);


	free(stack);
return EXIT_SUCCESS;
}
void push(int64_t const stack_size, int64_t stack[stack_size], int64_t const x){
	int64_t max_stack_top_value = stack_size - 1;
	if (stack_top >= max_stack_top_value){
		fprintf(stderr, "cannot push value to the stack (stack overflow)\n");
	}
	else{
		++stack_top;
		stack[stack_top] = x;
		printf("Val %ld inserted into the top of the stack\n", x);
	}
}
void pop(int64_t const stack_size, int64_t stack[stack_size]){
	if (stack_top < 0){
		fprintf(stderr, "cannot pop() current value (stack underflow)\n");
	}
	else {
		--stack_top;
		printf("Pop() was successful\n");
	}
}
bool stack_empty(int64_t const stack_size, int64_t stack[stack_size]){
	if (stack_top < 0)	return true;
	return false;
}

int64_t *mkstack(int64_t *stack_size){
	int clear_buffer;
	do{
		printf("Enter valid stack length size (between 1 and 1000): ");
		scanf("%ld", stack_size);
	}while (*stack_size < 1 || *stack_size > 1000);
	while( (clear_buffer = getchar()) != '\n' && clear_buffer != EOF);
	return malloc(sizeof(int64_t) * *stack_size);
}
