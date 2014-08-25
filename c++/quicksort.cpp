#include <iostream>
#include <string>

extern "C"
{
#include <stdio.h>
#include <stdlib.h>
}
using namespace std;

//swap characters
void swap(char *in, int idx1, int idx2)
{
    char temp = in[idx2];
    in[idx2] = in[idx1];
    in[idx1] = temp;
}

//Put everything < pivot on left, the right side no need to touch as [left..partition..right]
//Stores storeIndex to know how many was moved, and where pivot should end up.
int partition(char *in, int begin, int end)
{
    int pIndex = (begin + end) / 2;
    char pivot = in[pIndex];          
    swap(in, pIndex, end);              //Move pivot to the end so it doesnt get in the way 

    int storeIndex = begin;

    for (int i = begin; i < end; i++)
    {
        if  (in[i] <= pivot)
        {
            swap(in, i, storeIndex);
            storeIndex++;
        }

    }
    swap(in, storeIndex, end);

    return storeIndex;
}

//1. If begin < end is terminating condition, (array of 1 left)
//2. quicksort [start...p-1], [p+1...end] recursively until no more
void quicksort(char *in, int begin, int end)
{
    if(begin < end)
    {
        int p = partition(in, begin, end);
        quicksort(in, begin, p - 1);
        quicksort(in, p + 1, end);
    }

    return;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "invald args" << endl;
		return 1;
	}

    char *str1 = (char *)malloc(sizeof(strlen(argv[1]) + 1));
    str1 = argv[1];

    std::cout << str1 << std::endl;

    quicksort(str1, 0, strlen(str1)-1);

    std::cout << str1 << std::endl;

    return 0;
}
