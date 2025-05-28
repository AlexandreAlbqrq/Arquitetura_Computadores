// Teste_Manu_Trb_Assby.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "conio.h"
#define sz 160

void add_int(int* v1, int* v2, int* result, int size) {
    for (int i = 0; i < sz; i++) {
        v1[i] = i;
        v2[i] = i;
        result[i] = v1[i] + v1[i];
    }
}

void add_int_asm(int* v1, int* v2, int* result, int size) {
    _asm {
                    mov ecx, 0
                    mov esi, v1
                    mov edi, v2
                    mov edx, result

        loop_start: cmp ecx, sz
                    je loop_end

                    mov al, [esi + ecx]
                    mov dl, [edi + ecx]

                    add al, dl

                    mov[edx + ecx], al
                    inc ecx
                    jmp loop_start

        loop_end:
    }
}

int main() {
    int v1[sz], v2[sz], result[sz];

    add_int(v1, v2, result, sz);
    printf("Codigo em C: \n");
    for (int i = 0; i < sz; i++) {
        printf("%d ", result[i]);
    }

    printf("\n**********************************************\n");
    printf("Codigo em Assembly: \n");
    add_int_asm(v1, v2, result, sz);
    for (int i = 0; i < sz; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}