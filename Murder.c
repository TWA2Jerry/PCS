#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    
    int num_test;
    scanf("%d",&num_test);
    int * a = (int*)malloc(num_test*sizeof(int));
    for(int m = 0; m<num_test;m++){
        a[m] = 0;
    }
    getc(stdin);
    char line[256];
    
    for(int i = 0; i<num_test; i++){
        
        
        int j = 0;
        int palindrome = 0;
        /*If the line is a palindrome, palindrome is remains 0*/
        while((line[j] = getc(stdin)) != '\n' && j<256){
            
            j++;
            
        }
        
        if(j <= 1){
            palindrome = 0;
            
        }
        
        else{
            int fwrd_itr = 0; int back_itr = j-1;
            while(fwrd_itr <= back_itr){
                while(isalpha(line[fwrd_itr]) == 0){
                    fwrd_itr++;
			if(fwrd_itr > 150){
				break;

			}
                    
                }
                
                while(isalpha(line[back_itr]) == 0){
                    back_itr--;

			if(back_itr <0){
				break;
			}
                    
                }
                
                if(fwrd_itr <= back_itr){
                    if(line[fwrd_itr] != line[back_itr] && line[fwrd_itr] - 32 != line[back_itr] && line[fwrd_itr] != line[back_itr] - 32){
                        palindrome = 1;
                    }
                }
                
                fwrd_itr++;
                back_itr--;
                
                
            }
        }
        
        if(palindrome == 0){
            a[i] = 1;
            
        }
        else{
            a[i] = 0;
        }
        
        
    }
    
    for(int i = 0; i<num_test;i++){
        if(a[i] == 1){
            printf("True\n");
        }
        
        else{
            printf("False\n");
            
        }
        
    }
    
    return 0;
    
    
    
    
    
}
