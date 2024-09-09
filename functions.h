#pragma once
#include <string>
#include <stdexcept>

const int MAX_SIZE = 100; 

// Read data from file into array
void readFromFile(int arr[], int& size, const std::string& filename);

// Check if integer exists in array; return index if int exists
int checkIndex(int arr[], int size, int value);

// Modify value of int when called via index; return new value AND old value back to user
void modifyValue(int arr[], int size, int index, int newValue, int& oldValue);

// Add new integer to end of array
bool addNumber(int arr[], int& size, int newValue);

// Replace value at given index with 0 or remove it
bool removeOrZero(int arr[], int& size, int index, bool remove);