```c
#include "include/core.h"
#include <assert.h>

ColumnarDBEngine *init_engine(void) {
    ColumnarDBEngine *engine = malloc(sizeof(ColumnarDBEngine));
    if (engine == NULL) {
        perror("Failed to allocate memory for ColumnarDBEngine");
        return NULL;
    }

    engine->storage = init_storage();
    if (engine->storage == NULL) {
        destroy_engine(engine);
        return NULL;
    }

    engine->query_exec = init_query_execution(engine->storage);
    if (engine->query_exec == NULL) {
        destroy_engine(engine);
        return NULL;
    }

    engine->compression = init_compression(engine->storage);
    if (engine->compression == NULL) {
        destroy_engine(engine);
        return NULL;
    }

    return engine;
}

void destroy_engine(ColumnarDBEngine *engine) {
    if (engine == NULL) return;

    destroy_query_execution(engine->query_exec);
    destroy_storage(engine->storage);
    destroy_compression(engine->compression);
    free(engine);
}
```