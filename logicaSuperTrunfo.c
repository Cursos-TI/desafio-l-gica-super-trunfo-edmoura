#include <stdio.h>

#define MAX_CITY_NAME 50
#define CODE_SIZE 4

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char state;                   // Estado (A-H)
    char code[CODE_SIZE];         // Código da carta (ex: A01)
    char cityName[MAX_CITY_NAME]; // Nome da cidade
    unsigned long int population; // População
    float area;                   // Área em km²
    float gdp;                    // PIB em bilhões de reais
    int touristSpots;             // Número de pontos turísticos
    float populationDensity;      // Densidade populacional
    float gdpPerCapita;           // PIB per capita
} Card;

// Calcula atributos derivados
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

// Compara duas cartas em todos os atributos
void compareCards(Card c1, Card c2) {
    printf("===== Comparação de Cartas =====\n\n");

    // População
    printf("População:\n");
    printf("Carta 1 - %s (%c): %lu\n", c1.cityName, c1.state, c1.population);
    printf("Carta 2 - %s (%c): %lu\n", c2.cityName, c2.state, c2.population);
    if (c1.population > c2.population)
        printf("Resultado: Carta 1 venceu!\n\n");
    else if (c2.population > c1.population)
        printf("Resultado: Carta 2 venceu!\n\n");
    else
        printf("Resultado: Empate!\n\n");

    // Área
    printf("Área:\n");
    printf("Carta 1 - %s (%c): %.2f km²\n", c1.cityName, c1.state, c1.area);
    printf("Carta 2 - %s (%c): %.2f km²\n", c2.cityName, c2.state, c2.area);
    if (c1.area > c2.area)
        printf("Resultado: Carta 1 venceu!\n\n");
    else if (c2.area > c1.area)
        printf("Resultado: Carta 2 venceu!\n\n");
    else
        printf("Resultado: Empate!\n\n");

    // PIB
    printf("PIB:\n");
    printf("Carta 1 - %s (%c): %.2f bilhões\n", c1.cityName, c1.state, c1.gdp);
    printf("Carta 2 - %s (%c): %.2f bilhões\n", c2.cityName, c2.state, c2.gdp);
    if (c1.gdp > c2.gdp)
        printf("Resultado: Carta 1 venceu!\n\n");
    else if (c2.gdp > c1.gdp)
        printf("Resultado: Carta 2 venceu!\n\n");
    else
        printf("Resultado: Empate!\n\n");

    // Pontos turísticos
    printf("Pontos Turísticos:\n");
    printf("Carta 1 - %s (%c): %d\n", c1.cityName, c1.state, c1.touristSpots);
    printf("Carta 2 - %s (%c): %d\n", c2.cityName, c2.state, c2.touristSpots);
    if (c1.touristSpots > c2.touristSpots)
        printf("Resultado: Carta 1 venceu!\n\n");
    else if (c2.touristSpots > c1.touristSpots)
        printf("Resultado: Carta 2 venceu!\n\n");
    else
        printf("Resultado: Empate!\n\n");

    // Densidade populacional (vence o menor valor)
    printf("Densidade Populacional:\n");
    printf("Carta 1 - %s (%c): %.2f hab/km²\n", c1.cityName, c1.state, c1.populationDensity);
    printf("Carta 2 - %s (%c): %.2f hab/km²\n", c2.cityName, c2.state, c2.populationDensity);
    if (c1.populationDensity < c2.populationDensity)
        printf("Resultado: Carta 1 venceu!\n\n");
    else if (c2.populationDensity < c1.populationDensity)
        printf("Resultado: Carta 2 venceu!\n\n");
    else
        printf("Resultado: Empate!\n\n");

    // PIB per capita
    printf("PIB per Capita:\n");
    printf("Carta 1 - %s (%c): %.2f reais\n", c1.cityName, c1.state, c1.gdpPerCapita);
    printf("Carta 2 - %s (%c): %.2f reais\n", c2.cityName, c2.state, c2.gdpPerCapita);
    if (c1.gdpPerCapita > c2.gdpPerCapita)
        printf("Resultado: Carta 1 venceu!\n\n");
    else if (c2.gdpPerCapita > c1.gdpPerCapita)
        printf("Resultado: Carta 2 venceu!\n\n");
    else
        printf("Resultado: Empate!\n\n");
}

int main() {
    Card c1, c2;

    // Entrada de dados das duas cartas
    readCardData(&c1, 1);
    readCardData(&c2, 2);

    // Calcula atributos derivados
    calculateAttributes(&c1);
    calculateAttributes(&c2);

    // Mostra as cartas cadastradas
    showCard(c1, 1);
    showCard(c2, 2);

    // Compara as duas cartas
    compareCards(c1, c2);

    return 0;
}