#include <iostream>

template <typename T>
void printArray(T arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << " " << std::endl;
	}
}

template <typename T>
void bubbleSort(T numArray[], int arrSize)
{
	T temp;

	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (numArray[j] > numArray[j + 1])
			{
				temp = numArray[j];
				numArray[j] = numArray[j + 1];
				numArray[j + 1] = temp;
			}
		}
	}

	printArray(numArray, arrSize);
}

template <typename T>
void insertionSort(T arr[], int arrSize)
{
	T j, key;

	//For each value in array
	for (int i = 1; i < arrSize; i++)
	{
		//Set key to value at the current index
		key = arr[i];
		//Set j to be the previous index
		j = i - 1;

		//While j is greater than or equal to 0 and the value at j is greater than the key
		while (j >= 0 && arr[j] > key)
		{
			//Set value at the index of j + 1 to be the value at the index of j
			arr[j + 1] = arr[j];
			//Decrement j
			j--;
		}
		//Set value at the index of j + 1 to be the key
		arr[j + 1] = key;
	}

	printArray(arr, arrSize);
}

int main()
{
	int numbers[] = { 5, 3, 1, 4, 9, 7 };

	int altNumbers[] = { 45, 12, 3, 20, 66, 18, 7 };

	bubbleSort(numbers, 6);

	insertionSort(altNumbers, 7);

	return 0;
}