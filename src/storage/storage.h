```c
#ifndef COLUMNAR_DB_ENGINE_STORAGE_H
#define COLUMNAR_DB_ENGINE_STORAGE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StorageManager StorageManager;

StorageManager *init_storage(void);
void destroy_storage(StorageManager *storage);

#endif // COLUMNAR_DB_ENGINE_STORAGE_H
```