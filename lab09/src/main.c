#include <stdlib.h>
#include <time.h>

#include "lib.h"

int main(int argc, char **argv) {

  int len = 6;
  int a[] = {5, 5, 5, 5, 5, 5};

  if (argc == 1) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; i++) {
      a[i] = rand() % 100;
    }
  } else {
    for (int i = 1; i < len + 1; i++) {
      a[i - 1] = (int)strtod(argv[i], 0);
    }
  }

  int *ap = &a[0];
  int res = get_count(ap, len);

  return (0);
}
