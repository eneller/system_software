# Ganzzahlige Datentypen
## Repräsentation 
Signed (vorzeichenbehaftete) ganze Zahlen werden heute durch das b-Komplement dargestellt (2-Komplement), da so keine Unterscheidung zwischen signed und unsigned Addition notwendig ist.
Überläufe können bei allen Operationen auftreten, irrelevant ob signed oder unsigned. Bei x86-64 gibt es dafür ein Statusregister namens EFLAGS
# Arithmetische Operationen
# Auswahl, Risiken, Überläufe
Hier die Größen der in C üblichen ganzzahligen Datentypen in Byte. Pointer haben die der Architektur entsprechende Größe, bei 64 Bit also 64 / 8 Bit = 8 Byte.
> char (1) <= short (2) <= unsigned / int (4) <= long (4/8) <= long long (8)