# Retrospektive
### Abweichungen:
 * Methode Pausieren() von IOHandler fehlt im Klassendiagramm
 * Methode EingabePufferLeeren() von IOHandler fehlt im Klassendiagramm
 * Methode EingabeFehler() von IOHandler fehlt im Klassendiagramm
 * Methode TextEingabe() von IOHandler wurde im Klassendiagramm geplant, aber in der Implementation nicht benötigt
 * Die Menüführung (abseits des Hauptmenüs) wurde nicht im Sequenzdiagramm geplant
 * IOHandler ist im Klassendiagramm nicht als Singleton erkennbar
 * Die Referenzen auf andere Klassen fehlen als Attribute in den Klassen

### Weiterführende Erkenntnisse:
 * In Zukunft werde ich auftretende Fehler/Probleme in der Architektur oder dem Design sauber dokumentieren und sofort entsprechend behenben
 * Vor allem den Ablauf in der Methode StartVorgang() der Klasse Mahlwerk muss ich in den zukünftigen Sprints genauer geplant werden
 * Die genutzten Tools (Visual Studio, Draw.io, Git Bash, Excel) werde ich beibehalten