#include <stdio.h>

#define MAX_CITY_NAME 50
#define CODE_SIZE 4

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char state; // Estado (A-H)
    char code[CODE_SIZE]; // Código da carta (ex: A01)
    char cityName[MAX_CITY_NAME]; // Nome da cidade
    unsigned long int population; // População
    float area; // Área em km²
    float gdp; // PIB em bilhões de reais
    int touristSpots; // Número de pontos turísticos
    float populationDensity; // Densidade populacional
    float gdpPerCapita; // PIB per capita
} Card;

// Calcula atributos derivados da carta
void calculateAttributes(Card *c) {
    c->populationDensity = (float)c->population / c->area;
    c->gdpPerCapita = (c->gdp * 1000000000.0f) / c->population;
}

// Lê os dados de uma carta
void readCardData(Card *c, int number) {
    printf("Digite os dados da Carta %d:\n", number);
    printf("Estado (A-H): ");
    scanf(" %c", &c->state);
    printf("Código (ex: A01): ");
    scanf("%s", c->code);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", c->cityName);
    printf("População: ");
    scanf("%lu", &c->population);
    printf("Área (km²): ");
    scanf("%f", &c->area);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &c->gdp);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->touristSpots);
    printf("\n");
}

// Mostra os dados de uma carta
void showCard(Card c, int number) {
    printf("Carta %d:\n", number);
    printf("Estado: %c\n", c.state);
    printf("Código: %s\n", c.code);
    printf("Nome da Cidade: %s\n", c.cityName);
    printf("População: %lu\n", c.population);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.gdp);
    printf("Número de Pontos Turísticos: %d\n", c.touristSpots);
    printf("Densidade Populacional: %.2f hab/km²\n", c.populationDensity);
    printf("PIB per Capita: %.2f reais\n", c.gdpPerCapita);
    printf("\n");
}

// Compara duas cartas com base no atributo selecionado
void compareCardsByAttribute(Card c1, Card c2, int attribute) {
    printf("\nComparação entre %s e %s\n", c1.cityName, c2.cityName);

    switch (attribute) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %lu\n", c1.cityName, c1.population);
            printf("%s: %lu\n", c2.cityName, c2.population);
            if (c1.population > c2.population) {
                 printf("Resultado: %s venceu!\n", c1.cityName);
                 printf("Carta 1\n");
            } else if (c2.population > c1.population) {
                 printf("Resultado: %s venceu!\n", c2.cityName);
                 printf("Carta 2\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", c1.cityName, c1.area);
            printf("%s: %.2f km²\n", c2.cityName, c2.area);
            if (c1.area > c2.area) {
                 printf("Resultado: %s venceu!\n", c1.cityName);
                 printf("Carta 1\n");
            } else if (c2.area > c1.area) {
                 printf("Resultado: %s venceu!\n", c2.cityName);
                 printf("Carta 2\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", c1.cityName, c1.gdp);
            printf("%s: %.2f bilhões\n", c2.cityName, c2.gdp);
            if (c1.gdp > c2.gdp) {
                 printf("Resultado: %s venceu!\n", c1.cityName);
                 printf("Carta 1\n");
            } else if (c2.gdp > c1.gdp) {
                 printf("Resultado: %s venceu!\n", c2.cityName);
                 printf("Carta 2\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Número de Pontos Turísticos\n");
            printf("%s: %d\n", c1.cityName, c1.touristSpots);
            printf("%s: %d\n", c2.cityName, c2.touristSpots);
            if (c1.touristSpots > c2.touristSpots) {
                 printf("Resultado: %s venceu!\n", c1.cityName);
                 printf("Carta 1\n");
            } else if (c2.touristSpots > c1.touristSpots) {
                 printf("Resultado: %s venceu!\n", c2.cityName);
                 printf("Carta 2\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade demográfica (menor vence)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", c1.cityName, c1.populationDensity);
            printf("%s: %.2f hab/km²\n", c2.cityName, c2.populationDensity);
            if (c1.populationDensity < c2.populationDensity) {
                 printf("Resultado: %s venceu!\n", c1.cityName);
                 printf("Carta 1\n");
            } else if (c2.populationDensity < c1.populationDensity) {
                 printf("Resultado: %s venceu!\n", c2.cityName);
                 printf("Carta 2\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, escolha um atributo válido.\n");
            break;
    }
}

int main() {
    Card card1, card2;
    int choice;

    // Entrada dos dados das cartas
    readCardData(&card1, 1);
    readCardData(&card2, 2);
    
    // Calcula atributos derivados necessários
    calculateAttributes(&card1);
    calculateAttributes(&card2);

    // Exibe as cartas cadastradas
    showCard(card1, 1);
    showCard(card2, 2);

    // Menu interativo para escolha do atributo
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("Digite a opção: ");
    scanf("%d", &choice);

    compareCardsByAttribute(card1, card2, choice);

    return 0;
}