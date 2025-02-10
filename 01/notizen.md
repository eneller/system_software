# Einführung und erste Schritte mit C

- 3 Kernelfunktionen: Zugriff auf Peripherie, Hardware-Ressourcen Verwaltung, Schnittstelle für Anwendungsprogramme
- POSIX als Standard für Schnittstellen, die vom OS implementiert werden, garantiert jedoch keine vollständige Portabilität
- C als Assembler Alternative für Portabilität 
## System- vs Funktionsaufrufe
Systemaufrufe sind aufgrund des erforderlichen Kontextwechsels und ihrer oft asynchronen Natur zeitlich teurer als Funktionsaufrufe,
welche im selben Ausführungskontext bleiben.
Systemaufrufe sollten daher in performanten Programmen minimiert werden und können mit `strace` verfolgt werden.
## Der Übersetzungsprozess und Übersetzungseinheiten
Die spezifischen Maschinen-Instruktionen sind in den C-Bibliotheken der jeweiligen Plattform hinterlegt.
```bash
as # GNU assembler
ld # GNU linker
```
Statt dem modernen Modulkonzept `import` verwendet C (und seine Derivate) einen Präprozessor, dessen Direktiven durch # gekennzeichnet sind.
Mit `gcc -E` kann dessen Ausgabe analysiert werden.
```c
#define abc=ABCDEFGHIJKLMNOPQRSTUVWXYZ // string replace
#include <stdio.h> // include header file by pasting it here, <> for system files, "" for relative path
```

## Aufbau einfacher C-Programme
```c
sizeof(int);
```
## Kontrollstrukturen
## Einfache Ein- und Ausgabe
Im Gegensatz zu `puts` fügt `printf` keinen impliziten Zeilenumbruch an und unterstützt Formatierungsoptionen für Variablen.
- %d für int in dezimal
- %s string
- %f float dezimal komma
- %e float dezimal exponential
```c
#include <stdio.h>
...
int x0, x1;
//TODO also catch EOF
// returns number of arguments read
if (scanf("%d %d", &x0, &x1) !=2){
    printf("Input failed %d, %d \n", x0, x1 );
}
```

## Übung
```bash
gcc -o output \
-std=c11 \
-g #debug info for gdb
```