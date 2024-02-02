#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtd_dogs, count = 0;

    printf("How many dogs do you have?\n");

    scanf("%d", &qtd_dogs);

    char **dogs_name = malloc(sizeof(char*) * qtd_dogs);

    for (int i = 0; i < qtd_dogs; i++) {
        dogs_name[i] = malloc(sizeof(char) * (qtd_dogs + 1));

        count++;

        printf("Say the name of %d dog: ", count);

        scanf("%s", dogs_name[i]);
    }

    for (int i = 0; i < qtd_dogs; i++) {
        printf("Dog number %d: %s\n", (i + 1), dogs_name[i]);
    }

    free(dogs_name);
}