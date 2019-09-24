#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int num_test;
    scanf("%d", &num_test);
    int results_array[num_test];
    for(int i = 0; i<num_test; i++){
        
        int min_hours = 1000000000;
        int num_students, num_picks;
        scanf("%d %d", &num_students, &num_picks);
        
        
        int skills_array[10000];
        int less_or_equal[10000];
        
        for(int i = 0; i<10000; i++){
            skills_array[i] = 0;
            less_or_equal[i] = 0;
        }
        
        
        
        for(int j = 0; j<num_students; j++){
            int skill;
            scanf("%d", &skill);
            skills_array[skill-1]++;

        }
        
        less_or_equal[0] = skills_array[0];
        
        for(int j = 1; j<10000; j++){
            less_or_equal[j] = skills_array[j]+less_or_equal[j-1];
        }
        
        for(int j = 0; j<10000; j++){
            int num_left = num_picks;
            if(less_or_equal[j] >= num_picks){
                int num_kids = j;
                int num_hours = 0;
                while(num_left - skills_array[num_kids] > 0){
                    num_left -= skills_array[num_kids];
                    num_hours += skills_array[num_kids]*(j-num_kids);
                    num_kids--;
                }
                
                num_hours += num_left*(j-num_kids);
                
                if(num_hours < min_hours){
                    min_hours = num_hours;
                }
                
            }
            
            else{
                continue;
            }
        }
        
        
        results_array[i] = min_hours;
        
    }
    
    for(int i = 0; i<num_test; i++){
        printf("Case #%d: %d\n", i+1, results_array[i]);
    }
    
    return 0;
    
}
