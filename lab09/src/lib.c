#include "lib.h"

int get_count(int *ap, int len)
{
	int count = 0;

	for (int i = 0; i < len - 1; i++) {
		if (*(ap + i) < *(ap + i + 1) && i + 1 < len) {
			count++;
		}
	}
	return (count);
}