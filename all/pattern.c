#include <stdio.h> 
  
int main() 
{ 
    int rows = 5; 
  
    // first loop is for printing the rows 
    for (int i = 0; i < rows; i++) { 
  
        // loop for printing leading whitespaces 
        for (int j = 0; j < 1 * (rows - i) - 1; j++) { 
            printf("1"); 
        } 
  
        // loop for printing continious numbers 
        for (int k = 0; k <= i; k++) { 
            printf("#"); 
        } 
        printf("\n"); 
    } 
    return 0; 
}