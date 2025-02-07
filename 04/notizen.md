# Arrays und Zeigerarithmetik
Größe eines Datentyps `sizeof()` ist immer vielfaches der Ausrichtung `alignof()`, die bestimmt an welchen Adressen im Speicher ein Objekt beginnnen kann.
Da Arrays in C kein primitiver Datentyp sind, wird bei der Übergabe an Funktionen nur ein Zeiger auf das erste Element übergeben, die Länge des Arrays geht verloren.
Im Regelfall sollten Arrays deshalb als Zeiger auf den Array übergeben werden.

## VLA
VLAs (Variable Length Arrays), deren Länge zur Laufzeit definiert wird, wurden mit C99 eingeführt, werden jedoch weder im Linux Kernel noch in C++ verwendet
und werden gemeinhin als Fehler im Sprachstandard betrachtet. Mittels `gcc -Wvla` kann man Warnungen bei ihrer Nutzung erhalten.