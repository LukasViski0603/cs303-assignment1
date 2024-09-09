#include "functions.h"
#include <fstream>
#include <iostream>
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

// Puts all integers from file into array
void readFromFile(int arr[], int& size, const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Error: file couldn't open." << endl;
		return;
	}
	size = 0;
	while (file >> arr[size] && size < MAX_SIZE) {
		size++;
	}
	file.close();
}

// Searches for value in array and returns index
int checkIndex(int arr[], int size, int value) {
	for (int i = 0; i < size; ++i)
		if (arr[i] == value) {
			return i;
		}
	return -1;
}

// Changes value at given index in array
void modifyValue(int arr[], int size, int index, int newValue, int& oldValue) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("\nError: Index out of bounds!");
	}
	oldValue = arr[index];
	arr[index] = newValue;
}

// Adds new value to END of array
bool addNumber(int arr[], int& size, int newValue) {
	if (size >= MAX_SIZE) {
		throw std::overflow_error("\nError: Array is full!");
	}
	arr[size] = newValue;
	size++;
	return true;
}

// Removes value or sets it to zero at given index
bool removeOrZero(int arr[], int& size, int index, bool remove) {
	if (index < 0 || index >= size) {
		return false;				// Invalid index.
	}
	
	if (remove) {
		for (int i = index; i < size - 1; i++) {
			arr[i] = arr[i + 1];	// Shift elements left.
		}
		size--;						// Decrease size
	} else { 
		arr[index] = 0; 
	}

	return true; 
}

