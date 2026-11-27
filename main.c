#include <stdio.h>
typedef struct {
    char placa[8];
    char marca[30];
    char modelo[30];
    int ano;
}Veiculos;
void exibirmenu();
void exibirRelatorios();
void selecionarmenu(int opcao);
void cadastrarveiculo();
void cadastrarnoarquivo(Veiculos veiculo);
int main() {
    int opcao = 0;
    do{
        exibirmenu();
        scanf("%d", &opcao);
        selecionarmenu(opcao);
    }while(opcao != 6);
    return 0;
}
void exibirmenu(){
    printf("\n===== SISTEMA DE VEICULOS: =====\n");
    printf("1 - Cadastrar veiculo\n");
    printf("2 - Listar veiculos\n");
    printf("3 - Buscar veiculo\n");
    printf("4 - Alterar veiculo\n");
    printf("5 - Relatorios\n");
    printf("6 - Sair\n");   
}
void exibirRelatorios(){
    printf("\n===== RELATORIOS: =====\n");
    printf("1 - Veiculos por marca\n");
    printf("2 - Veiculos por ano de fabricacao\n");
    printf("0 - Voltar\n");
}
void selecionarmenu(int opcao){
    switch(opcao){
        case 1:
            printf("\n===== Cadastro de veiculos =====\n");
            cadastrarveiculo();
            break;
        case 2:
            printf("\n===== Listar veiculos =====\n");
            break;
        case 3:
            printf("\n===== Buscar veiculo =====\n");
            break;
        case 4:
            printf("\n===== Alterar veiculo =====\n");
            break;
        case 5:
            printf("\n===== Relatorios =====\n");
            break;
        case 6:
            printf("Voce saiu do sistema.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
    }
}
void cadastrarveiculo(){
    Veiculos veiculo;
    printf("Digite a placa do veiculo: ");
    scanf(" %7[^\n]", veiculo.placa);
    printf("Digite a marca do veiculo: ");
    scanf(" %29[^\n]", veiculo.marca);
    printf("Digite o modelo do veiculo: ");
    scanf(" %29[^\n]", veiculo.modelo);
    printf("Digite o ano de fabricacao do veiculo: ");
    scanf("%d", &veiculo.ano);
    cadastrarnoarquivo(veiculo);
}
void cadastrarnoarquivo(Veiculos veiculo) {
    FILE *arquivo = fopen("veiculos.bin", "ab");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    if(fwrite(&veiculo, sizeof(Veiculos), 1, arquivo) == 1) {
        printf("Veiculo cadastrado com sucesso!\n");
    } 
    else{
        printf("Erro ao gravar veiculo.\n");
    }
    fclose(arquivo);
}
