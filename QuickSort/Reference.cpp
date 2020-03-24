#include "Reference.h"
#include <algorithm>
using namespace std;

int funcForRefMedian(int a[], int leftEdge, int rightEdge) {
	int *middle = a + (rightEdge - leftEdge) / 2 + leftEdge;
	int *left = a + leftEdge;
	int *right = a + rightEdge;
	int maximum = max(max(*left, *right), *middle);
	int minimum = min(min(*left, *right), *middle);
	int result = *middle + *left + *right - minimum - maximum;
	if (result == *middle) {
		return middle - a;
	}
	else if (result == *left) {
		return leftEdge;
	}
	return rightEdge;
}


int funcForReference(int a[], int leftEdge, int rightEdge) {
	return (rightEdge - leftEdge) / 2 + leftEdge;
}