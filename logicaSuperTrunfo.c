#include <stdio.h>

#define MAX_CITY_NAME 50
#define CODE_SIZE 4

typedef struct {
    char state;
    char code[CODE_SIZE];
    char cityName[MAX_CITY_NAME];
    unsigned long int population;
    float area;
    float gdp;
    int touristSpots;
    float populationDensity;
    float gdpPerCapita;
} Card;

void calculateAttributes(Card *c) {
    c->populationDensity = (float)c->population / c->area;
    c->gdpPerCapita = (c->gdp * 1000000000.0f) / c->population;
}

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

float getAttributeValue(Card c, int attribute) {
    switch (attribute) {
        case 1: return (float)c.population;
        case 2: return c.area;
        case 3: return c.gdp;
        case 4: return (float)c.touristSpots;
        case 5: return c.populationDensity;
        default: return 0.0f;
    }
}

void showAttributeName(int attribute) {
    switch (attribute) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Número de Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica (menor vence)"); break;
        default: printf("Atributo inválido");
    }
}

int chooseAttribute(int excluded) {
    int choice;
    printf("Escolha um atributo:\n");
    for (int i = 1; i <= 5; i++) {
        if (i == excluded) continue;
        printf("%d - ", i);
        showAttributeName(i);
        printf("\n");
    }
    printf("Digite a opção: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 5 || choice == excluded) {
        printf("Opção inválida. Tente novamente.\n");
        return chooseAttribute(excluded);
    }
    return choice;
}

int main() {
    Card card1, card2;
    int firstAttribute, secondAttribute;
    float card1Attr1, card1Attr2, card2Attr1, card2Attr2;
    float totalCard1, totalCard2;

    readCardData(&card1, 1);
    readCardData(&card2, 2);

    calculateAttributes(&card1);
    calculateAttributes(&card2);

    showCard(card1, 1);
    showCard(card2, 2);

    printf("\nEscolha o primeiro atributo para comparação:\n");
    firstAttribute = chooseAttribute(-1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    secondAttribute = chooseAttribute(firstAttribute);

    card1Attr1 = getAttributeValue(card1, firstAttribute);
    card1Attr2 = getAttributeValue(card1, secondAttribute);
    card2Attr1 = getAttributeValue(card2, firstAttribute);
    card2Attr2 = getAttributeValue(card2, secondAttribute);

    printf("\n===== Comparação =====\n");
    printf("%s vs %s\n\n", card1.cityName, card2.cityName);

    printf("Atributo 1: ");
    showAttributeName(firstAttribute);
    printf("\n%s: %.2f\n%s: %.2f\n", card1.cityName, card1Attr1, card2.cityName, card2Attr1);

    // Comparação do primeiro atributo
    if (firstAttribute == 5) {
            if (card1Attr1 < card2Attr1) {
                printf("Vencedor do atributo 1: %s\n", card1.cityName);
                printf("Carta 1\n");
            } else if (card2Attr1 < card1Attr1) {
                printf("Vencedor do atributo 1: %s\n", card2.cityName);
                printf("Carta 2\n");
            } else {
                printf("Vencedor do atributo 1: Empate\n");
            }
    } else {
            if (card1Attr1 > card2Attr1) {
                printf("Vencedor do atributo 1: %s\n", card1.cityName);
                printf("Carta 1\n");
            } else if (card2Attr1 > card1Attr1) {
                printf("Vencedor do atributo 1: %s\n", card2.cityName);
                printf("Carta 2\n");
            } else {
                printf("Vencedor do atributo 1: Empate\n");
            }
    }

    printf("\nAtributo 2: ");
    showAttributeName(secondAttribute);
    printf("\n%s: %.2f\n%s: %.2f\n", card1.cityName, card1Attr2, card2.cityName, card2Attr2);

    // Comparação do segundo atributo
    if (secondAttribute == 5) {
            if (card1Attr2 < card2Attr2) {
                printf("Vencedor do atributo 2: %s\n", card1.cityName);
                printf("Carta 1\n");
            } else if (card2Attr2 < card1Attr2) {
                printf("Vencedor do atributo 2: %s\n", card2.cityName);
                printf("Carta 2\n");
            } else {
                printf("Vencedor do atributo 2: Empate\n");
            }
    } else {
            if (card1Attr2 > card2Attr2) {
                printf("Vencedor do atributo 2: %s\n", card1.cityName);
                printf("Carta 1\n");
            } else if (card2Attr2 > card1Attr2) {
                printf("Vencedor do atributo 2: %s\n", card2.cityName);
                printf("Carta 2\n");
            } else {
                printf("Vencedor do atributo 2: Empate\n");
            }
    }

    // Soma final — lembrar que densidade é invertida: menor = melhor
    totalCard1 = (firstAttribute == 5 ? -card1Attr1 : card1Attr1) +
                 (secondAttribute == 5 ? -card1Attr2 : card1Attr2);
    totalCard2 = (firstAttribute == 5 ? -card2Attr1 : card2Attr1) +
                 (secondAttribute == 5 ? -card2Attr2 : card2Attr2);

    printf("\n===== Resultado Final =====\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", card1.cityName, totalCard1);
    printf("%s: %.2f\n", card2.cityName, totalCard2);

    if (totalCard1 > totalCard2) {
        printf("Resultado: %s venceu a rodada!\n", card1.cityName);
        printf("Carta 1\n");
    } else if (totalCard2 > totalCard1) {
        printf("Resultado: %s venceu a rodada!\n", card2.cityName);
        printf("Carta 2\n");
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
