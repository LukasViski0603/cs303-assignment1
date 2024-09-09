// This program manages an array of integers and allows users to find, modify, add, or remove values. 
// CS303 - Lukas Viskovic - Assignment 01 


#include "functions.h"
#include <iostream>

// To reduce rewriting of "std::" without the name collision risk of "using namespace std;"
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

int main() {

	int arr[MAX_SIZE];
	int size = 0;
	string filename = "A1input.txt";
	readFromFile(arr, size, filename);

	cout << "Read " << size << " numbers from the file." << endl;
	cout << "Array contents: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	char choice;
	do {
		cout << "\nMenu Options:" << endl;
		cout << "F - Find a number" << endl;
		cout << "M - Modify a value" << endl;
		cout << "A - Add a number" << endl;
		cout << "R - Remove or zero a value" << endl;
		cout << "P - Print the array" << endl;
		cout << "Q - Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		choice = toupper(choice);	// In case user input is lowercase. 

		switch (choice) {			// Process user choice

			case 'F': {
				int value = 0;
				cout << "Enter value." << endl;
				cin >> value;
				int index = checkIndex(arr, size, value);
				if (index != -1) {
					cout << "\nValue " << value << " found at index " << index << endl;
				} else {
					cout << "\nValue " << value << " not found in array." << endl; 
				}
				break; 
			}

			case 'M': {
				int newValue, index;
				int oldValue = 0;
				cout << "Enter index to modify:" << endl;
				cin >> index; 
				cout << "Enter new value:" << endl; 
				cin >> newValue;

				try {
					modifyValue(arr, size, index, newValue, oldValue);
					cout << "Value at index " << index << " changed from " << oldValue << " to " << newValue << endl;
				}
				catch (const std::out_of_range& e) {
					cout << e.what() << endl;
				}
				break;
			}

			case 'A': {
				int newValue;
				cout << "Enter the number to add: ";
				cin >> newValue;
				try {
					if (addNumber(arr, size, newValue)) {
						cout << "Number " << newValue << " added successfully." << endl;
					}
				}
				catch (const std::overflow_error& e) {
					cout << e.what() << endl;
				}
				break;
			}

			case 'R': {
				int index;
				char removeChoice;
				cout << "Enter the index to remove or zero: ";
				cin >> index;
				cout << "Remove (R) or Zero (Z) the value? ";
				cin >> removeChoice;
				removeChoice = toupper(removeChoice);

				bool remove = (removeChoice == 'R');
				if (removeOrZero(arr, size, index, remove)) {
					if (remove) {
						cout << "Value at index " << index << " removed successfully." << endl;
					}
					else {
						cout << "Value at index " << index << " set to zero successfully." << endl;
					}
				}
				else {
					cout << "Operation failed. Index might be out of bounds." << endl;
				}
				break;
			}
			
			case 'P': {
				cout << "Array contents: ";
				for (int i = 0; i < size; i++) {
					cout << arr[i] << " ";
				}
				cout << endl;
				break;
			}

			case 'Q': {
				cout << "Exiting program. Goodbye!" << endl;
				break;
			}

			default: {
				cout << "Invalid choice. Please try again." << endl;
			}
		} 
		// End of Switch Statement

	} while (choice != 'Q');

	return 0;
}