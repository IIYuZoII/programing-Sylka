#include <stdlib.h>
#include <time.h>

int main() {
#define SIZE 10
#define MIN -10
#define MAX 100

  int array[SIZE][SIZE];

  srandom((unsigned int)time(NULL));
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      array[i][j] = MIN + random() % (MAX - MIN);
    }
  }

  int min_n = MAX;
  int max_n = MIN;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (array[i][j] < min_number) {
        min_number = array[i][j];
      }
      if (array[i][j] > max_number) {
        max_number = array[i][j];
      }
    }
  }

  float diff = (float)max_n / (float)min_n;

  return 0;
}
