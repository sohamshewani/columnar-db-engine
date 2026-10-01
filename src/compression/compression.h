```c
#ifndef COLUMNAR_DB_ENGINE_COMPRESSION_H
#define COLUMNAR_DB_ENGINE_COMPRESSION_H

#include <stdio.h>
#include <stdlib.h>

#include "src/storage/storage.h"

typedef struct CompressionManager CompressionManager;

CompressionManager *init_compression(StorageManager *storage);
void destroy_compression(CompressionManager *compression);

#endif // COLUMNAR_DB_ENGINE_COMPRESSION_H
```