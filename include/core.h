```c
#ifndef COLUMNAR_DB_ENGINE_CORE_H
#define COLUMNAR_DB_ENGINE_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#include "src/storage/storage.h"
#include "src/query_execution/query_execution.h"
#include "src/compression/compression.h"

typedef struct ColumnarDB Engine {
    StorageManager *storage;
    QueryExecution *query_exec;
    CompressionManager *compression;
} ColumnarDBEngine;

ColumnarDBEngine *init_engine(void);
void destroy_engine(ColumnarDBEngine *engine);

#endif // COLUMNAR_DB_ENGINE_CORE_H
```