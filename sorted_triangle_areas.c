#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

/* Helper: compute squared area using Heron's formula.
   We use squared area to avoid sqrt() calls in the comparator. */
double area_squared(triangle *t) {
    double s = (t->a + t->b + t->c) / 2.0;
    return s * (s - t->a) * (s - t->b) * (s - t->c);
}

/* qsort comparator: returns negative if t1 < t2, positive if t1 > t2 */
int compare(const void *x, const void *y) {
    triangle *t1 = (triangle *)x;
    triangle *t2 = (triangle *)y;
    
    double a1 = area_squared(t1);
    double a2 = area_squared(t2);
    
    if (a1 < a2) return -1;
    if (a1 > a2) return 1;
    return 0;
}

void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    qsort(tr, n, sizeof(triangle), compare);
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}