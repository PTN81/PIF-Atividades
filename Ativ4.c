#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual_desconto) {
    produto->preco = produto->preco * (1.0 - percentual_desconto / 100.0);
}

void imprimir_produtos(Produto *ptr, int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        printf("ID: %d | Preço: R$ %.2f\n", 
               (ptr + i)->id, 
               (ptr + i)->preco);
    }
}

int main() {
    Produto estoque[3] = {
        {1, 100.0},
        {2, 200.0},
        {3, 300.0}
    };
    
    printf("\n*** Produtos sem descontos ***\n");
    imprimir_produtos(estoque, 3);
    
    aplicar_desconto(&estoque[0], 10.0);
    aplicar_desconto(&estoque[1], 20.0);
    aplicar_desconto(&estoque[2], 30.0);
    
    printf("\n*** Produtos com descontos ***\n");
    imprimir_produtos(estoque, 3);

    printf("\nPressione ENTER para sair...\n");
    getchar();
    
    return 0;
}