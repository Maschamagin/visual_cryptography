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
12
12
value at row 12 and column 12: 1
what should be the new value for the coordinate? 
please choose between 1 and 0. 
0
new value at row 12 and column 12: 0

Process finished with exit code 0



"Die Farben des Bildes sollen sich auf die beiden Farben (Weiß / Schwarz) beschränken und geeignet codiert
werden."
in der Methode "read_image" wird jeder Eintrag des 2D Arrays überprüft, ob er einen anderen Wert als '0' oder '1' hat. Falls es einen weiteren character in der Bilddatei gibt, so wird das Programm "Not a black and white image" ausgeben.


zu Aufgabe 2b)
"Erstellt eine weitere Klasse (CBild), im Unterschied zu (NBild) sollen deren Elemente die Blöcke A
und B repräsentieren. Es sollen ebenfalls Methoden zum Importieren und Exportieren von Bildern
implementiert werden." 
Die Klasse c_images beinhaltet die Methode read_image_file, um die Daten aus einer Bilddatei (implementiert wieder mit der beispieldatei_1.txt, die bei Olat bereitgestellt wurde) zunächst in ein 2-diimensionales Array (matrix) zu importieren, und dann mithilfe der Methode substitute_pixels_with_pixel_blocks jeden Pixel in einen der beiden Blöcke A oder B zu übersetzen. In dem Programm wird jeder Pixel, der mit '0' (also weiß) belegt ist zu einem Block A, jeder schwarze Bildpunkt (mit dem Wert '1') wird in einen Block B übersetzt.
Dazu wird ein 2-dimensionales Array erzeugt, das doppelt so viele Zeilen und Spalten hat wie das ursprüngliche Bild. jeder Pixel
des Originals wird dann von 4 Bildpunkten repräsentiert: 
- dem Bildpunkt mit den Koordinaten 2*(Zeile des Pixels im Originalbild) und 2*(Spalte des Pixels im Originalbild)
- dem Bildpunkt mit den Koordinaten 2*(Zeile des Pixels im Originalbild) und [2*(Spalte des Pixels im Originalbild)]+1
- dem Bildpunkt mit den Koordinaten [2*(Zeile des Pixels im Originalbild)]+1 und 2*(Spalte des Pixels im Originalbild)
- dem Bildpunkt mit den Koordinaten [2*(Zeile des Pixels im Originalbild)]+1 und [2*(Spalte des Pixels im Originalbild)]+1

Wenn der Pixel im Originalbild den Wert '0' hat, ist die Übersetzung dieses Bildpunktes in Block A in der Methode substitute_pixels_with_pixel_blocks so realisiert:

            if (matrix[i][j] == '0') {
                // this is the actual translation of a one-pixel-value into block A:
                matrix_of_pixel_blocks[i * 2][j * 2] = 1;
                matrix_of_pixel_blocks[i * 2][(j * 2) + 1] = 0;
                matrix_of_pixel_blocks[(i * 2) + 1][j * 2] = 0;
                matrix_of_pixel_blocks[(i * 2) + 1][(j * 2) + 1] = 1;


Den Export der Daten in eine neue Bilddatei wird auch in der Methode substitute_pixels_with_pixel_blocks realisiert. So wird das gesamte Array, das die Blöcke A und B repräsentiert (matrix_of_pixel_blocks) in eine Datei geschrieben, die der Methode als Arguement übergeben werden muss. 

Zusätzlich wurde eine Methode get_block_from_pixel erstellt, die als Argumente zwei Integer-Werte entgegennimmt: die Koordinaten des Pixels im Originalbild, auf den zugegriffen werden soll (Zeile, Spalte). Die Methode sucht im neu erstellten 2D Array, das die Blöcke A und B repräsentiert nach den jeweiligen Bildpunkten und evaluiert, ob es sich dabei um einen Block A oder B handelt.
Das Ergebnis wird dann in der Konsole ausgegeben.
In der main-Datei des Programms werden erst die Koordinaten des Bildpunktes erfragt, über den man sich informieren möchte, dann werden die Werte des Bildpunktes im Orignal- sowie im Blockbild ausgegeben.
Ein Beispiel:
type in which coordinate you would like to acces(row, column): 
12
12
value at row 12 and column 12: 1
what should be the new value for the coordinate? 
please choose between 1 and 0. 
0
new value at row 12 and column 12: 0
pixel represented as a block in encrypted image: Block A. 
10
01

Process finished with exit code 0


