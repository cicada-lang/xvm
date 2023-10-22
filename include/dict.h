typedef struct _dict_t dict_t;
typedef struct _word_t word_t;

dict_t *dict_new(size_t size);
void dict_destroy(dict_t **self_p);
void dict_purge(dict_t *self);
size_t dict_size(dict_t *self);
