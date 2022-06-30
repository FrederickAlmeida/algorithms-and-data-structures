#include <iostream>
#include <string>

using std::cin;
using std::cout;

void Sorting(int* number_list, int list_size) {
	int smallest_value, temp;

	for (int i = 0; i < list_size; i++) {
		smallest_value = number_list[i];
		temp = i;
		
		for (int j = i; j < list_size; j++) {
			if (smallest_value > number_list[j]) {
				smallest_value = number_list[j];
				temp = j;
			};
		}
		number_list[temp] = number_list[i];
		number_list[i] = smallest_value;
	}
}

int main() {
	int numbers_list[5];
	cout << "Enter 5 numbers to be ordered in crescent order: ";
	
	for (int i = 0; i < 5; i++)
		cin >> numbers_list[i];

	int size = sizeof(numbers_list) / sizeof(numbers_list[0]);

	Sorting(numbers_list, size);

	for (int i = 0; i < size; i++)
		cout << numbers_list[i] << " ";

	return 0;
}
