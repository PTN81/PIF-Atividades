#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual_desconto) {
    produto->preco = produto->preco * (1.0 - percentual_desconto / 100.0);
}

int main() {
    Produto p;
    p.id = 1;
    p.preco = 100.0;
    
    printf("\nProduto ID: %d\n", p.id);
    printf("Preço original: R$ %.2f\n", p.preco);
    
    aplicar_desconto(&p, 10.0);
    
    printf("Preço com desconto: R$ %.2f\n", p.preco);
    
    printf("\nPressione ENTER para sair...\n");
    getchar();
    
    return 0;
}