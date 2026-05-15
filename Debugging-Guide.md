# Debugging-Anleitung für VS Code

Dieses Dokument erklärt die wichtigsten Debugging-Schritte und die Symbole, die du in der Debug-Leiste siehst.

## 1. Debug starten

- **F5**: Startet den Debugger. VS Code startet das Programm und hält an Breakpoints.
- **Run → Start Debugging**: Gleiche Aktion wie F5.

## 2. Debug stoppen

- **Shift+F5**: Stoppt die aktuelle Debugging-Sitzung und beendet das Programm.
- **Rotes Quadrat**: Klicken, um den Debugger sofort zu stoppen.

> Wichtig: Wenn du das Programm nicht stoppst, bleibt `Embedded.exe` möglicherweise gesperrt, und das erneute Bauen schlägt fehl.

## 3. Debug neu starten

- **Strg+Shift+F5**: Startet das Debugging neu.
- **Kreis mit Pfeil**: Klicken, um die Debug-Sitzung neu zu starten.

> Der Debugger stoppt zuerst die aktuelle Sitzung und startet danach neu.

## 4. Schrittweise Ausführen

- **F10 (Step Over)**: Geht zur nächsten Zeile im gleichen Funktionskontext. Springt nicht in eine Funktion hinein.
- **F11 (Step Into)**: Geht in eine Funktion hinein, wenn die aktuelle Zeile einen Funktionsaufruf enthält.
- **Shift+F11 (Step Out)**: Führt die aktuelle Funktion zu Ende und kehrt zur aufrufenden Funktion zurück.

## 5. Weiterlaufen

- **F5 oder Play-Symbol**: Fahre fort, bis der nächste Breakpoint erreicht wird oder das Programm endet.
- **Play mit Balken**: Manche Layouts zeigen einen grünen Pfeil oder ein „Weiter“-Symbol.

## 6. Gängige Symbole in der Debug-Leiste

In der Leiste rechts aus dem Screenshot sind meist folgende Symbole zu sehen:

- `▷` oder grüner Pfeil: **Start/Weiter**
- `■` rotes Quadrat: **Stopp**
- `↻` Kreis mit Pfeil: **Neustart**
- `↓↷` oder `F10`: **Step Over**
- `↓↵` oder `F11`: **Step Into**
- `↑↵` oder `Shift+F11`: **Step Out**
- `⏸` oder Pause-Symbol: **Pause** (falls verfügbar)

## 7. Was tun, bevor du neu baust?

1. Stoppe den Debugger mit `Shift+F5` oder dem roten Quadrat.
2. Schließe das Debug-Terminal, falls das Programm noch läuft.
3. Baue das Projekt neu.

## 8. Häufige Fehler und Lösungen

- Fehler: `cannot open output file ... Permission denied`
  - Ursache: `Embedded.exe` läuft noch oder ist vom Debugger gesperrt.
  - Lösung: Debug stoppen oder Programm beenden.

- Fehler: Das Formatieren beim Speichern funktioniert nicht
  - Ursache: Falscher `clang-format`-Pfad oder kein Standardformatter für C eingestellt.
  - Lösung: Prüfe `settings.json` und teste manuelles Formatieren mit `Shift+Alt+F`.

## 9. Extra-Tipp

Wenn du die Debug-Ansicht öffnest, siehst du auch:
- Breakpoints
- Variablen
- Aufrufstapel
- Speicher

Diese Ansicht hilft dir, das Programmverhalten während des Debuggens besser zu verstehen.

---

Viel Erfolg beim Debuggen! Wenn du möchtest, kann ich auch eine spezifische `launch.json`-Erklärung schreiben.