#ifndef QUOTES_H
#define QUOTES_H

typedef struct {
    char **quotes;
    int size;
    int capacity;
} QuotesList;

void init_quotes(QuotesList *list);
void load_quotes_from_file(QuotesList *list, const char *filename);
void add_quote(QuotesList *list, const char *quote);
void remove_quote(QuotesList *list, int index);
void display_quotes(const QuotesList *list);
void free_quotes(QuotesList *list);

#endif
