#include "Reference.h"
#include <iostream>
#include "Sort.h"
#include <ctime>
#include <map>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(static_cast<unsigned int>(time(0)));
	int size = 0;
	int numberOfSwap = 0;
	int numberOfTest = 0;
	int numberOfSwapM = 0;
	while (size*numberOfTest == 0) {
		cout << "Введите два натуральных числа: количество элементов в массиве и количество тестов." << endl;
		cin >> size >> numberOfTest;
	}
	cout << "Количество перемещений элементов с выбором опорного элемента в центре:" << endl;
	int *a = new int[size];
	int *b = new int[size];
	int *arrForSwap = new int[numberOfTest];
	for (int j = 0; j < numberOfTest; j++) {
		int* k = b;
		for (int* i = a; i < a + size; i++, k++) {
			*i = rand();
			*k = *i;
		}
		int(*func)(int*, int, int);
		int(*funcM)(int*, int, int);
		func = &funcForReference;
		funcM = &funcForRefMedian;
		numberOfSwap = quicksort(a, 0, size - 1, func);
		numberOfSwapM = quicksort(b, 0, size - 1, funcM);
		arrForSwap[j] = numberOfSwapM;
		cout << numberOfSwap << endl;
	}
	cout << "Количество перемещений элементов с выбором опорного элемента медианного элемента относительно начального, среднего и последнего:" << endl;
	for (int j = 0; j < numberOfTest; j++) {
		cout << arrForSwap[j] << endl;
	}
	delete [] a;
	delete[] arrForSwap;
}
