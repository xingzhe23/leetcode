
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "find_duplicated_alphabeta_two_array.h"
#include "MergeSort.h"

#include "LinkedListComponents.h"

int main(void )
{
    char* a1 = "afdfbaerofdkfjdkfhgbz";
    char* a2 = "afdkfnowruffhtzakfjkdhlgjlfj";

    FindDuplicatedAlphaBetaTwoArray::test(a1, strlen(a1), a2, strlen(a2));
    std::cout << "the end!!!!" << std::endl;


    int a [] = { 1, 43, 4, 78, 32, 455, 33};
    MergeSort::sort(a, sizeof(a)/sizeof(int));

    std::cout << "meregSort: ";
    for(int i = 0; i < sizeof(a)/sizeof(int);i++) {
        std::cout << " " << a[i]; 
    }


    LinkedListComponents::solution::test();

    std::cout << std::endl;

}

