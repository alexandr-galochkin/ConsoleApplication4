#include "Sort.h"
#include <iostream>
using namespace std;
int partitioning(int a[], int leftEdge, int rightEdge, int referenceObj) {
	int counter = rightEdge;
	for (int* i = a + leftEdge; i <= a + rightEdge; i++) {
		if (* i > a[referenceObj]) {
			counter--;
		}
	}
	if (counter != referenceObj) {
		swap(a[counter], a[referenceObj]);
	}
	int referenceItem = a[counter];
	int* currentRight = a + rightEdge;
	int* currentLeft = a + leftEdge;
	while (currentLeft < a + counter) {
		if (*currentLeft > referenceItem) {
			while ((* currentRight > referenceItem) && (currentRight > a + counter)){
				currentRight--;
			}
			swap(*currentLeft, *currentRight);
		}
		currentLeft++;
	}
	return counter;
}

int bubble(int a[], int leftEdge, int rightEdge) {
	int numberOfSwap = 0;
	for (int * i = a + rightEdge; i > a + leftEdge; i--) {
		for (int * j = a + leftEdge; j < i; j++) {
			if (*j > *(j + 1)) {
				swap(*j, *(j + 1));
				numberOfSwap++;
			}
		}
	}
	return numberOfSwap;
}

int quicksort(int a[], int leftEdge, int rightEdge, int(*funcForReference)(int *, int, int)) {
	int numberOfSwap = 0;
	if (rightEdge <= leftEdge) {
		return numberOfSwap;
	}
	if (rightEdge - leftEdge < 100) {
		numberOfSwap =  bubble(a, leftEdge, rightEdge);
		return numberOfSwap;
	}
	int referenceObj = funcForReference(a, leftEdge, rightEdge);
	if (rightEdge - leftEdge == 1) {
		int* pointer = a;
		if (*(pointer + leftEdge) > *(pointer + rightEdge)) {
			swap(*(pointer + leftEdge), *(pointer + rightEdge));
			numberOfSwap++;
		}
		return numberOfSwap;
	}
	referenceObj = partitioning(a, leftEdge, rightEdge, referenceObj);
	if (referenceObj - leftEdge > 0) {
		numberOfSwap+= quicksort(a, leftEdge, referenceObj, funcForReference);
	}
	if (rightEdge - referenceObj > 2) {
		numberOfSwap += quicksort(a, referenceObj + 1, rightEdge, funcForReference);
	}
	return numberOfSwap;
}