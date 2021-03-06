// ConsoleApplication32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include <iostream>
#include <array>

using namespace std;
using namespace chrono;

void insert_sort(int array[], int n)
{
	int i, j;
	int temp;
	for (i = 1; i<n; i++)
	{
		temp = array[i];
		for (j = i; j>0 && array [j - 1]>temp; j--)
		{
			array[j] = array[j - 1];
		}
		array[j] = temp;
	}
}

void selction_sort(int array[], int n)
{
	int temp;
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

void bubble_sort(int array[], int n)
{
    int i, j;
	int temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
        if (array[j] > array[j + 1])
        {
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
}

void Merge(int sourceArray[], int tempArray[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArray[i] > sourceArray[j])
			tempArray[k++] = sourceArray[j++];
		else
			tempArray[k++] = sourceArray[i++];
	}
	while (i != midIndex + 1)
		tempArray[k++] = sourceArray[i++];
	while (j != endIndex + 1)
		tempArray[k++] = sourceArray[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArray[i] = tempArray[i];
}
void MergeSort(int sourceArray[], int tempArray[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;
		MergeSort(sourceArray, tempArray, startIndex, midIndex);
		MergeSort(sourceArray, tempArray, midIndex + 1, endIndex);
		Merge(sourceArray, tempArray, startIndex, midIndex, endIndex);
	}
}
int main()
{

	auto first = high_resolution_clock::now();

	void insert_sort();
	void selction_sort();
	void bubble_sort();

	auto end = high_resolution_clock::now();
	duration<double> elapsed = first - end;

	cout << "Seconds: " << elapsed.count() << "\n";
	cout << "\n";
	return 0;
}

