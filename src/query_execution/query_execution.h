```c
#ifndef COLUMNAR_DB_ENGINE_QUERY_EXECUTION_H
#define COLUMNAR_DB_ENGINE_QUERY_EXECUTION_H

#include <stdio.h>
#include <stdlib.h>

#include "src/storage/storage.h"

typedef struct QueryExecution QueryExecution;

QueryExecution *init_query_execution(StorageManager *storage);
void destroy_query_execution(QueryExecution *query_exec);

#endif // COLUMNAR_DB_ENGINE_QUERY_EXECUTION_H
```