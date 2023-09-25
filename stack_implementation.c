#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
void push(int64_t const stack_size, int64_t stack[stack_size], int64_t const x);
void pop(int64_t const stack_size, int64_t stack[stack_size]);
int64_t *mkstack(int64_t *stack_size);
int64_t stack_top = -1;

int main(void){
	int64_t *stack = NULL;
	int64_t stack_size;
	int64_t select;
	int64_t x;
	stack = mkstack(&stack_size);
	do{
		puts("------------------------------------------------");
		printf("To push to stack, press '1'\n" 
						"To pop stack, press '2'\n"
						"To print stack, press '3'\n"		
						"To print current index, press '57' \n"
						"To exit, press anything else\n");
		scanf("%ld", &select);
		switch(select){
			case 1: 
				printf("Enter number to insert on stack: ");
				scanf("%ld", &x);
				push(stack_size, &stack[0], x);
				break;
			case 2:
				pop(stack_size, &stack[0]);
				break;
			case 3:
				for (int64_t i = 0; i <= stack_top; ++i){
					printf("S[%ld] = %ld\n", i, stack[i]);
				}
				break;
			case 57: 
				printf("stack_top = %ld\n", stack_top);
				break;
			default:
				puts("Exitting program");
		}

	}while(select == 3 || select == 2 || select == 1 || select == 57);


	free(stack);
return EXIT_SUCCESS;
}
void push(int64_t const stack_size, int64_t stack[stack_size], int64_t const x){
	int64_t max_stack_top_value = stack_size - 1;
	if (stack_top >= max_stack_top_value){
		printf("cannot push value to the stack (stack overflow)\n");
	}
	else{
		++stack_top;
		stack[stack_top] = x;
	}
}
void pop(int64_t const stack_size, int64_t stack[stack_size]){
	if (stack_top < 0){
		printf("cannot pop() current value (stack underflow)\n");
	}
	else {
		--stack_top;
		printf("Pop() was successful\n");
	}
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
