#include <iostream>

void printArray(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << " " << std::endl;
	}
}

void bubbleSort(int numArray[], int arrSize)
{
	int temp;

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

int main()
{
	int numbers[] = { 5, 3, 1, 4, 9, 7 };

	bubbleSort(numbers, 6);

	return 0;
}