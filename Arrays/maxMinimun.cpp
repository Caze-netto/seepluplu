#include <iostream>

int maxValue(const int array[], int size);
int minValue(const int array[], int size);

int main(){
	int size = 10;
	int* array = new int[10];

	for (int i = 0; i < size; i++) {
		array[i] = i * i + 2;
	}

	std::cout << maxValue(array, size) << std::endl;
	std::cout << minValue(array, size) << std::endl;

	return 0;
}

int maxValue(const int array[], int size){
	int max = 0;

	for(int i = 0; i < size; i++){
		if(array[i] > max){
			max = array[i];
		}
	}

	return max;
}

int minValue(const int array[], int size){
	int min = 100000;

	for(int i = 0; i < size; i++){
		if(array[i] < min){
			min = array[i];
		}
	}

	return min;
}