#include <stdio.h>

void aplicar_desconto(float *preco, float percentual_desconto) {
    *preco = *preco * (1.0 - percentual_desconto / 100.0);
}

int main() {
    float preco = 100.0;
    
    aplicar_desconto(&preco, 10.0);
    
    printf("\nPreço com desconto: R$ %.2f\n", preco);
    
    printf("\nPressione ENTER para sair...\n");
    getchar();
    
    return 0;
}