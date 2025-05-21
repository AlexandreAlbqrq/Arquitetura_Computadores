// Somar_c_Saturtion.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "conio.h"
#define sz 300

void add_uchar_saturation(unsigned char* first, unsigned char* second, unsigned char* destination, int size) {
    for (int i = 0; i < size; i++) {
        first[i] = i;
        second[i] = i+1;
        destination[i] = first[i] + second[i];
        if (first[i] >=128 && second[i] >= 128) {
            destination[i] = 255;
        }
        
    }
}

int main(){
    unsigned char first[sz];
    unsigned char second[sz];
    unsigned char destination[sz];

    add_uchar_saturation(first, second, destination, sz);
    
    for (int i = 0; i < sz; i++) {
        printf("%d ", destination[i]);
    }
}