#include <stdio.h>

void numberOfJudges(int *number);
void scoreFromJudge(int elements, double *pointer);
void loadScores(double array[], int elements);
void getMaxMinAndAverage(double array[], double *max,
                         double *min, double *avarage, int elements);
void printFinalResult(double max, double min, double avarage);

int main(void) {

  int judges = 0;
  double arr[judges], max = 0, min = 0, avarage = 0, *pointer;
  pointer = &arr[0];

  printf("Program information\nThe program reads in the number of ");
  printf("judges and the score from each judge.\nThen it calculates ");
  printf("the average score without regard to the lowest and\nhighest");
  printf(" judge score. Finally it prints the results (the highest,");
  printf(" the\nlowest and the final average score).\n\n");

  numberOfJudges(&judges);
  scoreFromJudge(judges, pointer);
  loadScores(arr, judges);
  getMaxMinAndAverage(arr, &max, &min, &avarage, judges);
  printFinalResult(max, min, avarage);

  return 0;

}
void numberOfJudges(int *elements) {
  while (11<=*elements||(*elements<=2)) {
    printf("Number of judges (min 3 and max 10 judges)? ");
    scanf("%d",elements);
  }
  printf("\n");
}

void scoreFromJudge(int elements, double *pointer) {
  for (int i = 0; i < elements; i++) {
    printf("Score from judge %d? ", i+1);
    scanf("%lf", pointer+i);
  }
}

void loadScores(double array[], int elements) {
  printf("Loaded scores:\n");
  for (int i = 0; i < elements; i++) {
    printf("Judge %d: %.2lf\n", i+1, array[i]);
  }
  printf("\n");
}
void getMaxMinAndAverage(double array[], double *max,
                         double *min, double *avarage, int elements) {

  double sum = 0;

  for (int i = 0; i < elements; i++) {
    if (array[i]>*max) {
      *max = array[i];
    }
  }
  for (int i = 0; i < elements; i++) {
    if (array[i]<*min) {
      *min = array[i];
    }
  }
  for (int i = 0; i < elements; i++) {
    sum = sum + array[i];
  }
  *avarage = sum/elements;
}
void printFinalResult(double max, double min, double avarage) {
  printf("Final result:\n");
  printf("Highest judge score: %lf\nLowest judge score: %lf\nFinal"
  "avarage score: %lf\n",max,min,avarage);
}
