#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quotes.h"

int main() {
    QuotesList list;
    init_quotes(&list);
    load_quotes_from_file(&list, "quotes.txt");

    int choice;
    char buffer[256];

    do {
        printf("\n MENU \n");
        printf("1. Afficher les citations\n");
        printf("2. Ajouter une citation\n");
        printf("3. Supprimer une citation\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);
        getchar(); // mange le \n

        switch(choice) {
            case 1:
                display_quotes(&list);
            break;
            case 2:
                printf("Nouvelle citation : ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0; // enlever \n
            add_quote(&list, buffer);
            break;
            case 3:
                display_quotes(&list);
            printf("Indice à supprimer : ");
            int index;
            scanf("%d", &index);
            getchar();
            remove_quote(&list, index);
            break;
            case 4:
                printf("Au revoir !\n");
            break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choice != 4);

    free_quotes(&list);
    return 0;
}
