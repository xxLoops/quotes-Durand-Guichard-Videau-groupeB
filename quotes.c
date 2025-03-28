#include "quotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_quotes(QuotesList *list) {
    list->size = 0;
    list->capacity = 10;
    list->quotes = malloc(list->capacity * sizeof(char *));
}

void load_quotes_from_file(QuotesList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        add_quote(list, buffer);
    }
    fclose(file);
}

void add_quote(QuotesList *list, const char *quote) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->quotes = realloc(list->quotes, list->capacity * sizeof(char *));
    }
    list->quotes[list->size] = malloc(strlen(quote) + 1);
    strcpy(list->quotes[list->size], quote);
    list->size++;
}

void remove_quote(QuotesList *list, int index) {
    if (index < 0 || index >= list->size) return;
    free(list->quotes[index]);
    for (int i = index; i < list->size - 1; i++) {
        list->quotes[i] = list->quotes[i + 1];
    }
    list->size--;
}

void display_quotes(const QuotesList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d : %s\n", i, list->quotes[i]);
    }
}

void free_quotes(QuotesList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->quotes[i]);
    }
    free(list->quotes);
}
