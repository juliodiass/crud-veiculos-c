#include <stdio.h>

// STRUCT GERAL
typedef struct {
    char placa[8];
    char marca[30];
    char modelo[30];
    int ano;
} Veiculos;


// EMANUEL - Cadastro e arquivos

void cadastrarveiculo(void);

int verificarplaca(char *placa);

void cadastrarnoarquivo(Veiculos veiculo);


// LUIS - Consultas e alteracao

void listarVeiculos(void);

long buscarPorPlaca(FILE *arquivo, const char *placa);

void buscarVeiculo(void);

void alterarVeiculo(void);


// JULIO - Menu e relatorios

void exibirmenu(void);

void exibirRelatorios(void);

void selecionarmenu(int opcao);

void relatorioPorMarca(void);

void relatorioPorAno(void);
