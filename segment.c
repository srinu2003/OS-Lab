#include <stdio.h>
int main() {
  int a[100][100], b[1000], i, j, n, x, base, size, seg, off;
  printf("Enter The Segment Count: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter The %d Size: ", i + 1);
    scanf("%d", &size);
    a[i][0] = size;
    printf("Enter The Base Address\n");
    scanf("%d", &base);
    a[i][i] = base;
    for (j = 0; j < size; j++) {
      x = 0;
      scanf("%d", &x);
      b[base] = x;
      base++;
      b[base] = x;
    }
  }
  printf("Enter The Segment No And OffSet Value: ");
  scanf("%d %d", &seg, &off);
  if (off < a[seg][0]) {
    int abs = a[seg][1] + off;
    printf("The OffSet is less than: %d", a[seg][0]);
    printf("\n %d + %d = %d\n", a[seg][1], off, abs);
    printf("The Element %d Is At %d\n", b[abs + 1], abs);
  } else {
    printf("Error in Locating");
  }
}