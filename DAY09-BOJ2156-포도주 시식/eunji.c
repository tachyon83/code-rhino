#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b,c) ((a>b?a:b)>c?(a>b?a:b):c)
int main(){
	int **arr;

	int n,i,x;
	scanf("%d", &n);
	arr = (int **)calloc((n+1),sizeof(int*));
	for (i = 0; i <= n; i++) {
		arr[i] = (int*)calloc(3, sizeof(int));
	}

	for (i = 1; i <= n; i++) {
		scanf("%d", &x);
		arr[i][0] = MAX(arr[i - 1][0], arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] = arr[i - 1][0] + x;
		arr[i][2] = arr[i - 1][1] + x;
	}
	printf("%d", MAX(arr[n][0], arr[n][1], arr[n][2]));
}
