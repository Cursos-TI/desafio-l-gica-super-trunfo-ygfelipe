#include <stdio.h>
#include <string.h>

// Estrutura representando uma carta do Super Trunfo
struct Carta {
    char estado[3];                  // Sigla do estado
    char codigo[10];                 // Código identificador da carta
    char nomeCidade[50];            // Nome da cidade
    int populacao;                  // População total da cidade
    float area;                     // Área da cidade em km²
    float pib;                      // PIB da cidade em bilhões de reais
    int pontosTuristicos;          // Número de pontos turísticos
    float densidadePopulacional;   // População / Área
    float pibPerCapita;            // PIB / População
};

// Função para calcular a densidade populacional e o PIB per capita
void calcularIndicadores(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
}

int main() {
    // Definindo duas cartas fictícias com dados realistas
    struct Carta carta1 = {
        "AM", "C101", "Manaus",
        2219580,       // População
        11401.10,      // Área em km²
        73.1,          // PIB em bilhões
        14             // Pontos turísticos
    };

    struct Carta carta2 = {
        "DF", "C202", "Brasília",
        3094325,       // População
        5802.00,       // Área em km²
        289.0,         // PIB em bilhões
        18             // Pontos turísticos
    };

    // Calculando os indicadores para cada carta
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibindo os dados principais usados na comparação
    printf("Comparação de cartas (Atributo: Densidade Populacional - MENOR vence):\n\n");

    printf("Carta 1 - %s (%s): %.2f hab/km²\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);

    // Lógica de comparação com if/else
    if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
