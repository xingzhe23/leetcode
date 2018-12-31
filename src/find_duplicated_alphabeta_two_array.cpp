
#include "find_duplicated_alphabeta_two_array.h"
#include <iostream>

using namespace std;

inline int Ascii2Index(char c) {
    if( c >= 'A' && c <= 'Z') {
        return c-'A';
    } else if(c >= 'a' && c <= 'z') {
        return c-'a'+26;
    }
    return 100;
}

inline char Index2Char(int index) {
    if(index >= 0 && index <= 25) {
        return index + 'A';
    } else if(index >=26 && index < 52) {
        return index + 'a' - 26;
    }
    return '&';
}

void FindDuplicatedAlphaBetaTwoArray::test(char* a1, int m, char* a2, int n)
{
    int bitmap[52] = {0};
    for(int i = 0; i < m; i++) {
        int index = Ascii2Index(*(a1+i));
        if(index < 52) {
            bitmap[index] |= 0x01;
        }
    }

    for(int i =0; i < n; i++) {
        int index = Ascii2Index(*(a2+i));
        if(index < 52) {
            bitmap[index] |= 0x10;
        }
    }

    std::cout << "duplicate char: ";
    for(int i = 0; i < 52; i++) {     
        if(bitmap[i] == 0x11) {
            std::cout << Index2Char(i) << " ";
        }
    }

    std::cout << std::endl;
}




