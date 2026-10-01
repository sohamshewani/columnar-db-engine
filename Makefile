all: columnar_db_engine

install: all
	install -d $(DESTDIR)/usr/local/bin
	install -m 755 columnar_db_engine $(DESTDIR)/usr/local/bin/

columnar_db_engine: src/main.o src/core.o src/storage.o src/query_execution.o src/compression.o
	$(CC) $(CFLAGS) -o $@ $^ -lpthread

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

src/core.o: src/core.c include/core.h
	$(CC) $(CFLAGS) -c $< -o $@

src/storage.o: src/storage/storage.c src/storage/storage.h
	$(CC) $(CFLAGS) -c $< -o $@

src/query_execution.o: src/query_execution/query_execution.c src/query_execution/query_execution.h
	$(CC) $(CFLAGS) -c $< -o $@

src/compression.o: src/compression/compression.c src/compression/compression.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: test

test: 
	running_unit_tests

.PHONY: integration-test

integration-test: 
	running_integration_tests

running_unit_tests:
	make test

running_integration_tests:
	make integration-test
