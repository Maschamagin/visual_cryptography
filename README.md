Zu Aufgabe 2a)

"Erstellt eine Klasse mit der ihr den Inhalt der vorgegebenen Dateien importieren und exportieren könnt. "

Die Klasse "images" ist in eine header- (images.h) und eine Body-Datei (images.cpp) aufgeteilt. Im Header-file werden Zugriffsrechte (private, public) verwaltet und Methoden und Attribute festgelegt. Die Implementierung der Methoden wird  in der Datei der Klasse (images.cpp) codiert.
Die Klasse enthält die Methode "read_image", mit der aus der beispieldatei_1.txt (in olat bereitgestellt) die Daten in eine Matrix eingelesen werden.
Die Datei des Bildes muss im selben Verzeichnis liegen wie die Quellcodedatei der Klasse, sonst kann sie vom Programm nicht geöffnet werden. In diesem Fall wird das Programm einen Fehler melden: "Cannot open file. "
Ein anderes auftretendes Problem dabei könnte sein, dass die Methode lediglich Bilder mit der selben Anzahl an Spalten (303) einlesen kann.

"Es soll möglich sein auf die einzelnen Bildpunkte mittels Indexzugriff lesend
und schreibend zu zugreifen (also operator() const und &operator() )."
die Methode operator() const dient dem Lesen der Bildpunkte. Durch die Übergabe der Koordinaten (Reihe, Spalte, jeweils Integer-Werte) kann durch diese Methode der Wert der gesuchten Koordinaten gelesen werden. 
die Methode operator() nimmt drei Argumente entgegen: Reihe und Spalte jeweils als Integer-Werte, new_value als Charakter. 
In der main-datei des Programms werden die Koordinaten und der neue Wert als int row, int column und char new_value als Input entgegengenommen und dann an die Methoden als Parameter übergeben.
Ein Beispiel:

type in which coordinate you would like to acces(row, column): 
34
200

value at row 34
and column 200: 
1

what should be the new value for the coordinate? 
please choose between 1 and 0. 
0
new value at row 34
and column 200: 
0

Process finished with exit code 0



"Die Farben des Bildes sollen sich auf die beiden Farben (Weiß / Schwarz) beschränken und geeignet codiert
werden."
in der Methode "read_image" wird jeder Eintrag des 2D Arrays überprüft, ob er einen anderen Wert als '0' oder '1' hat. Falls es einen weiteren character in der Bilddatei gibt, so wird das Programm "Not a black and white image" ausgeben.
