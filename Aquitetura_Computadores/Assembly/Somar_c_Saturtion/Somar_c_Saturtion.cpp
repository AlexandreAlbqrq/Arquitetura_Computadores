// Somar_c_Saturtion.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "conio.h"
#define sz 64

void add_uchar_saturation(unsigned char* first, unsigned char* second, unsigned char* destination, int size) {
    for (int i = 0; i < size; i++) {
        /*first[i] = i;
        second[i] = i;*/
        destination[i] = first[i] + second[i];
        if (first[i] + second[i] >= 256) {
            destination[i] = 255;
        }
        else {
            destination[i] = first[i] + second[i];
        }
        
    }
}
/*
void add_uchar_saturation_asm(unsigned char* first, unsigned char* second, unsigned char* destination, int size) {
    _asm {
        mov
    }
}
*/
int main(){
    unsigned char first[sz] = { 3, 7, 12, 18, 21, 25, 29, 33, 38, 41, 45, 49, 53, 57, 61, 66, 70, 74, 78, 82, 86, 90, 94, 98, 102, 106, 110, 114,
                                118, 122, 126, 130, 135, 139, 143, 147, 151, 155, 159, 163, 167, 171, 175, 179, 183, 187, 191, 195, 199, 203, 207,
                                211, 215, 219, 223, 227, 231, 235, 239, 243, 247, 251, 255, 259 };
    unsigned char second[sz] = { 1, 5, 9, 13, 17, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63, 67, 71, 75, 79, 83, 87, 91, 95, 99, 103, 107, 111,
                                115, 119, 123, 127, 131, 136, 140, 144, 148, 152, 156, 160, 164, 168, 172, 176, 180, 184, 188, 192, 196, 200, 204,
                                208, 212, 216, 220, 224, 228, 232, 236, 240, 244, 248, 252 };
    unsigned char destination[sz];

    add_uchar_saturation(first, second, destination, sz);
    
    for (int i = 0; i < sz; i++) {
        printf("%d ", destination[i]);
    }
}