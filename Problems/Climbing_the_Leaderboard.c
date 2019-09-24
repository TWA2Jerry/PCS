

int binary_search(int lower, int upper, int * scores, int target){

    int middle = (upper+lower)/2;

    if(scores[middle] == target){

        return middle;

    }

    else if(middle == lower){
        return middle;
    }

    else if(scores[middle] < target){
        return binary_search(lower, middle, scores, target);
    }

    else{
        return binary_search(middle, upper, scores, target);
    }

}

int* climbingLeaderboard(int scores_count, int* scores, int alice_count, int* alice, int* result_count) {

    int * results_array = (int*)malloc(alice_count*sizeof(int));
    int * scores_array = (int*) malloc(scores_count*sizeof(int));
    scores_array[0] = 1;
    for(int j = 1; j<scores_count; j++){
        if(scores[j] < scores[j-1]){
            scores_array[j] = scores_array[j-1]+1;
        }

        else{
            scores_array[j] = scores_array[j-1];
        }
    }

    for(int i = 0; i<alice_count; i++){
      int score_match = binary_search(0, scores_count, scores, alice[i]);
      if(alice[i] < scores[score_match]){
          results_array[i] = scores_array[score_match]+1;
      } 

      else{
          results_array[i] = scores_array[score_match];
      }

      
    }
    *result_count = alice_count;
    return results_array;

}
