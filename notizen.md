# [ ][ ]1: Einführung und erste Schritte mit C

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

# [ ][ ]2: Ganzzahlige Datentypen
## Repräsentation 
Signed (vorzeichenbehaftete) ganze Zahlen werden heute durch das b-Komplement dargestellt (2-Komplement), da so keine Unterscheidung zwischen signed und unsigned Addition notwendig ist.
Überläufe können bei allen Operationen auftreten, irrelevant ob signed oder unsigned. Bei x86-64 gibt es dafür ein Statusregister namens EFLAGS
## Arithmetische Operationen
## Auswahl, Risiken, Überläufe
Hier die Größen der in C üblichen ganzzahligen Datentypen in Byte. Pointer haben die der Architektur entsprechende Größe, bei 64 Bit also 64 / 8 Bit = 8 Byte.
> char (1) <= short (2) <= unsigned / int (4) <= long (4/8) <= long long (8)# Gleitkommazahlen nach IEEE 754
Darstellung als Vorzeichen s mit Mantisse m und Exponent e, wobei die Mantisse als 1,m also als wissenschaftl. binäre Notation interpretiert wird.
$$ s*m*b^e $$

# [ ][ ]3: Gleitkommazahlen
# [ ][ ]4:Arrays und Zeigerarithmetik
Größe eines Datentyps `sizeof()` ist immer vielfaches der Ausrichtung `alignof()`, die bestimmt an welchen Adressen im Speicher ein Objekt beginnnen kann.
Da Arrays in C kein primitiver Datentyp sind, wird bei der Übergabe an Funktionen nur ein Zeiger auf das erste Element übergeben, die Länge des Arrays geht verloren.
Im Regelfall sollten Arrays deshalb als Zeiger auf den Array übergeben werden.

## VLA
VLAs (Variable Length Arrays), deren Länge zur Laufzeit definiert wird, wurden mit C99 eingeführt, werden jedoch weder im Linux Kernel noch in C++ verwendet
und werden gemeinhin als Fehler im Sprachstandard betrachtet. Mittels `gcc -Wvla` kann man Warnungen bei ihrer Nutzung erhalten.
# [ ][ ]5: Verbunde und dynamische Datenstrukturen
# [ ][ ]6: Virtueller Adressraum und Speicherverwaltung
# [ ][ ]7: Speicherverwaltungsalgorithmen
# [ ][ ]8: Kommandozeilenparameter und Einbettung in die Shell
# [ ][ ]9: Modularisierung
# [ ][ ]10: Dateisysteme
# [ ][ ]11: Sichere Programmierung
# [ ][ ]12: Systemaufrufe
# [ ][ ]13: Interne Datenstrukturen des Kernels und atomare Operationen
# [ ][ ]14: Gepufferte Eingabe und reguläre Ausdrücke