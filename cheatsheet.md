# Format Specifiers
## Print in Binary
# Operator Precedence
# Declaration Precedence 
int ** a[19]
# Preprocessor
# Makefile
```Makefile
target : prerequisites
    recipe
```
Vergleicht Timestamps von target und prerequsites und aktualisiert das target durch Ausführung des Recipe wenn die prerequisites neuer als das target sind.

Beispiel:
```Makefile
main : main.o util.o def.o
    gcc -o main.o util.o def.o

main.o : main.c def.h util.h
    gcc -c main.c

util.o : util.c util.h

def.o : def.c def.h
```
# System Calls