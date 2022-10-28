#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "queue.h"
#include "stack.h"

#define MAX_STR_LEN 256

/*
 * This function prompts the user for input and stores a maximum of `n`
 * characters of the string they enter into `dest`.  Any trailing line ending
 * characters are removed from the input string.  Returns 1 if a string was
 * successfully read from the user or 0 otherwise.
 */
int get_user_str(char* dest, int n) {
  printf("\nEnter a string, and we'll check whether it's a palindrome:\n");
  if (fgets(dest, MAX_STR_LEN, stdin) != NULL) {
    /*
     * If a string was successfully read from the user, remove any trailing
     * line ending characters.  Here's some documentation on strcspn() to help
     * understand how this works:
     *
     * https://en.cppreference.com/w/c/string/byte/strcspn
     */
    dest[strcspn(dest, "\r\n")] = '\0';
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  char* in = malloc(MAX_STR_LEN * sizeof(char));
  
  while (get_user_str(in, MAX_STR_LEN)) {

  struct stack* stack = stack_create(); //creating stacks and queues
  struct queue* queue = queue_create();

  int count = 0;
  bool palindrome = 0; //bool to check if string is palindrome

  
  for(int i = 0; i < strlen(in); i++){
    if(isalpha(in[i]) != 0){
      stack_push(stack, &in[i]);
      queue_enqueue(queue, &in[i]);
      count++;
    }
  }


  for(int i = 0; i < count; i++){

    if(tolower(*(char*)queue_dequeue(queue)) != tolower(*(char*)stack_pop(stack))){ //check if pop is equal to dequeue
      palindrome = 1;
      break;
    }
  }

    if(palindrome == 0){
      printf("%s is a palindrome.\n", in);
    }
    else{
      printf("%s is not a palindrome.\n", in);
    }

    queue_free(queue);    //free memory of both queue and stack
    stack_free(stack);
     free(in);
    return 0;
  }

 
  
}
