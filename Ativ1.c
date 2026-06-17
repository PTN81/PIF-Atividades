#include <stdio.h>

int main() {
    float preco = 100.0;
    float *ptr = &preco;
       
    *ptr = *ptr * 1.10;
    
    printf("\nPreço final do produto: R$ %.2f\n", preco);
    
    printf("\nPressione ENTER para sair...\n");
    getchar();
    
    return 0;
}