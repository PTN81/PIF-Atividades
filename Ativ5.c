#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual_desconto) {
    produto->preco = produto->preco * (1.0 - percentual_desconto / 100.0);
}

void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("\n--- Estoque de Produtos [%d item(s)] ---\n", quantidade);
    for(int i = 0; i < quantidade; i++) {
        printf("ID: %d | Preço: R$ %.2f\n", 
               (ptr + i)->id, 
               (ptr + i)->preco);
    }
    printf("________________________\n");
}

int main() {
    int quant;
    
    printf("\nQuantos produtos deseja cadastrar? ");
    scanf("%d%*c", &quant);
    
    if (quant <= 0) {
        printf("Quantidade deve ser maior que zero!\n");
        return 1;
    }
    
    Produto *estoque = (Produto *)malloc(quant * sizeof(Produto));
    
    if (estoque == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    
    printf("\n--- Cadastro de Produtos ---\n");
    for(int i = 0; i < quant; i++) {
        printf("Produto %d:\n", i + 1);
        printf("   ID: ");
        scanf("%d%*c", &(estoque + i)->id);
        printf("   Preco: R$ ");
        scanf("%f%*c", &(estoque + i)->preco);
    }
    
    imprimir_produtos(estoque, quant);
    
    if (quant >= 1) aplicar_desconto(estoque, 10.0);      
    if (quant >= 2) aplicar_desconto(estoque + 1, 20.0);  
    if (quant >= 3) aplicar_desconto(estoque + 2, 30.0);
    
    printf("\n=== Descontos aplicados ==>");
    imprimir_produtos(estoque, quant);

    free(estoque);
    estoque = NULL;  
    
    printf("\nMemória liberada com sucesso.\n");
    printf("\nPressione ENTER para sair...\n");
    getchar();

    return 0;
}