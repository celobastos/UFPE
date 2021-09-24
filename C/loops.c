// Laços!
#include <stdio.h>

//Juquinha conseguiu passar na cadeira 'Como fugir de um agiota NII' e quer fugir de pagar a segunda parcela, desta vez ele gastou seu dinheiro em uma bicicleta, crie um programa que mostre a velocidade da bicicleta de acordo com a aceleração constante que Juquinha produz!
//A cada cidade ele para e volta a correr, mostre também sua perca de velocidade (aceleração^2)
//A bibicleta do Juquinha só chega a 30km
//A cada cidade a aceleração aumenta 1
//Se Juquinha desacelerar brutamente (Sua velocidade < 0 ao desacelerar) ele cai e é pego!

int main () {
    int curva, aceleracao, i = 0;
    scanf("%d %d", &aceleracao, &curva);

    while (curva > 0) {
        for (i = 0; i < 30; i += aceleracao) {
            printf("%d ", i);
        }
        printf("\n");
        //Manipular os argumentos do for
        for (i = 30; i > 0; i -= aceleracao + 4) {
            printf("%d ", i);
        }
        printf("\n");
        //Aprende a não apenas criar variável no escopo
        if (i < 0) {
            curva = 0;
            printf("Juquinha se cagou todo no chao e foi pego.\n");
        }
        aceleracao++;
        curva--;
    }
    return 0;
}