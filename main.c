#include <stdio.h>
#include <string.h>
typedef struct {
    char placa[8];
    char marca[30];
    char modelo[30];
    int ano;
}Veiculos;
// Protótipos das funções
void exibirmenu();
void exibirRelatorios();
void selecionarmenu(int opcao);
void cadastrarveiculo();
int verificarplaca(char *placa);
void cadastrarnoarquivo(Veiculos veiculo);
int main() {
    int opcao = 0;
    // Loop principal do menu
    do{
        exibirmenu();
        scanf("%d", &opcao);
        selecionarmenu(opcao);
    }while(opcao != 6);
    return 0;
}
void exibirmenu(){
    // Exibe o menu principal do sistema
    printf("\n===== SISTEMA DE VEICULOS: =====\n");
    printf("1 - Cadastrar veiculo\n");
    printf("2 - Listar veiculos\n");
    printf("3 - Buscar veiculo\n");
    printf("4 - Alterar veiculo\n");
    printf("5 - Relatorios\n");
    printf("6 - Sair\n");   
}
void exibirRelatorios(){
    // Exibe o menu de relatórios do sistema
    printf("\n===== RELATORIOS: =====\n");
    printf("1 - Veiculos por marca\n");
    printf("2 - Veiculos por ano de fabricacao\n");
    printf("0 - Voltar\n");
}
void selecionarmenu(int opcao){
    // Seleciona a opção escolhida do menu principal
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
    // Função para cadastrar um novo veículo
    Veiculos veiculo;
    printf("Digite a placa do veiculo: ");
    scanf(" %7[^\n]", veiculo.placa);
    // Realiza a verificação se a placa já está cadastrada
    int jacadastrado = verificarplaca(veiculo.placa);
    if(jacadastrado == 1){
        printf("\n XXX Placa ja cadastrada. XXX\n");
        return;
    }
    printf("Digite a marca do veiculo: ");
    scanf(" %29[^\n]", veiculo.marca);
    printf("Digite o modelo do veiculo: ");
    scanf(" %29[^\n]", veiculo.modelo);
    printf("Digite o ano de fabricacao do veiculo: ");
    scanf("%d", &veiculo.ano);
    // Chama a função para cadastrar o veículo
    cadastrarnoarquivo(veiculo);
}
int verificarplaca(char *placa){
    // Função para verificar se a placa já está cadastrada
    Veiculos veiculo;
    // Abre o arquivo binário para leitura (rb)
    FILE *arquivo = fopen("veiculos.bin", "rb");
    // Verifica se o arquivo foi aberto corretamente
    if(arquivo == NULL){
        return 0;
    }
    // Percorre o arquivo lendo a estrutura de um veículo por vez
    // O fread retorna 1 enquanto conseguir ler um registro completo
    while(fread(&veiculo, sizeof(Veiculos), 1, arquivo) == 1){
        // Compara a placa do veículo lido com a placa informada no cadastro
        // O strcmp retorna 0 quando as duas strings são iguais
        if(strcmp(veiculo.placa, placa) == 0){
            fclose(arquivo);
            // Indica que a placa já está cadastrada
            return 1;
        }
    }
    fclose(arquivo);
    return 0;
}
void cadastrarnoarquivo(Veiculos veiculo) {
    // Função para cadastrar o veículo (abre o arquivo para escrita no final)
    FILE *arquivo = fopen("veiculos.bin", "ab");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    // Grava a estrutura do veículo no arquivo
    if(fwrite(&veiculo, sizeof(Veiculos), 1, arquivo) == 1){
        printf("Veiculo cadastrado com sucesso!\n");
    } 
    // Caso ocorra algum erro na gravação
    else{
        printf("Erro ao gravar veiculo.\n");
    }
    fclose(arquivo);
}
