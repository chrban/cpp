# Oblig 1

### Resultat: 
Lever på nytt


### Checklist:
* [] Begge programmene bygger med `make`.
* [] Begge programmene starter og kjører under Linux.
* [x] **oppvarming** gir riktig output.
  * "off by one" på siste beskjed gir galt spørsmålstegn, men det er OK
* [] **blackjack** har den viktigeste funksjonaliteten.
  * [] En spiller har et saldo og kan satse et beløp.
  * [] En spiller har valgen "HIT" og "STAND".
  * [] En spiller kan ikke fortsette når den har gått tom for penger.
  * [] Dealerns handlinger virker riktige.
  * [] Spillet følger reglene til BlackJack.
* [] Ingen alvorlige kjøretidsfeil (segfault etc.)
* [] Ingen minnelekasjer funnet med `valgrind`.
* [x] Repo innholder `RAPPORT.md`.



### Tilbakemelding:

* Linux er case-sensitivt! Det vil si at vi får "Player.h: No such file or directory - fordi den heter player.h". Du skulle ha testet på Linux fra start.
* Jeg ser du har gjort mye bra arbeid med Blackjack (pen ascii-art på starten) - så du vil få skikkelig tilbakemelding på dette, men fix Makefile først, og sørg for at alt bygger og kjører på Linux. 

PS: Siden dette bare gjelder Makefile, si fra straks du har fikset det, og verifisert at alt funker på Ubuntu 14.4, så får du raskere vite om det andre er greit.