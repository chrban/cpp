
Obligatorisk oppgave 2: Fyrverkeri
========================================

*Effektiv kode med C og C++ vår 2015*

**Innlevering:** 

  * En mappe kalt "oblig2" må ligge i samme github-repository som sist, innen **26.03.2015 kl.23:59**
  * Mappen kan være tom, men må legges ut 1 uke før den endelige fristen, for at jeg skal kunne sjekke at alle er med, og på github.
  * Det ferdige prosjektet må ligge i den samme mappen på github inen **02.04.2015 kl.23:59**
  * Det er fem oppgaver, der de fire første må løses, mens den siste er frivillig.

**Generelle retningslinjer:**

  * Det er lov å snakke med hverandre om løsningen, men det å dele kode med andre, på noen som helst måte, blir betraktet som juks. Det er du alene som skal skrive koden, og du skal kunne redegjøre for innholdet.
  * Spesielt er det viktig at ingen åpner sitt github-repository for noen andre enn meg (alfred-bratterud)
  * Manglende innlevering gjør at man mister muligheten til å få karakter i kurset, med mindre man har *fått innvilget utsettelse før fristen.* 
  * Man vil få tilbakemelding på det man har gjort, og kan da evt. få beskjed om ting som må endres, for at oppgaven skal bli godkjent. 
  * *Alle steg i koden som ikke er helt trivielle skal kommenteres*

## 1) Enkel implementasjon av fyrverkeri

I mappen for oblig2 ligger det det et ferdig designet klassehierarki for et fyrverkeri ([se klassediagram her](./fireworks_class_hierarchy.pdf)), laget i et lite animasjonsrammeverk bygget på [fltk](http://www.fltk.org). Du skal nå lage implementasjonen til dette fyrverkeriet:

  1. For alle .hpp-filene som trenger å implementeres (du må finne ut hvilke), må det lages en `.cpp`-fil med samme fornavn. I tillegg skal det være en fil `main.cpp` som skal inneholde `main`. Denne fila skal kompileres til `fireworks` og bare opprette et vindu, gjerne i fullskjermmodus, og starte et fyrverkeri i vinduet.
  2. Du skal ikke forandre header-filene! Du vil sikkert finne ting som burde- og kunne vært anderledes - men dette må du jobbe rundt, og eventuelle svakheter skal du skrive noe om i neste oppgave. 
  3. Prosjektet skal kompileres med en make-fil som må lages, ved å skrive `make fireworks` eller også bare `make` (begge deler skal funke)
  4. Make-fila skal kompilere alle klasser hver for seg, som `.o`-filer og deretter kompilere `fireworks.cpp`, der `.o`-filene linkes inn med statisk eller dynamisk linking. PS: Velger du dynamisk linking, må du sørge for at `.so`-biblioteket ikke trengs å installeres, men kan ligge der det ble bygget.
  5. Alle kompilerte filer skal bli borte når man skriver `make clean`. 
  6. Koden må fungere på ubuntu 14.4 (kurs-vm'en), og kompileres med siste versjon av `gcc`, som pr. i dag  er `gcc-4.9`. 

Du kan skrive all den koden du mener du trenger, men forsøk å være konsis, uten at det er noe mål i seg selv å få det spesielt kort.

**Krav til fyrverkeriet:**

  1. Forsøk å få fyrverkeriet til å likne på [dette](https://screencast.uninett.no/relay/ansatt/alfrebhioa.no/2015/19.03/12866/Fireworks_CPP_2015_-_20150319_125437_36.html). 
  2. Følg ellers retningslinjene i oppgavene om fyrverkeri (i [oppgaver.md](../oppgaver.md)), mtp. farger og bevegelse i dottene. Spesielt, forsøk å få de ulike dottene til å ha litt ulik farge, men med overvekt av en farge. Jeg har valgt orange.
  3. Ganske mye er "random" i fyrverkeriet - dermed er det naturligvis mye som vil variere fra kjøring til kjøring.
     * Hver enkelt dotts fart og retning er random, gitt noen begrensninger. Dette styres i `is_vector`.
     * Hvor hver enkelt rakett starter, er random, men godt innenfor skjermen. Dette styres i `rocket`.
     * Hvor lang tid det tar før en rakett "fyrer av" er random, dvs. at raketten har en random lang lunte ("fuse"), men med en rimelig "maks-tid". Dette styres også i `rocket`.
     * Fargen på hver dott er randomisert, men med overvekt av orange. Dette styres i `has_color`.

## 2) Fyrverkeri 2.0 med "abstract DotFactory"
Du skal nå lage en ny versjon av det samme fyrverkeriet, der dottene lages av en "dotFactory". Se [utvidet klassediagram her](./fireworks2_class_hierarchy.pdf).

1. Det nye fyrverkeriet kan gjenbruke kode fra det forrige så mye som mulig, men må ha en egen versjon av `rocket.cpp`, `rocket2.cpp` som implementerer factory-konstruktøren, samt en egen versjon av `fireworks.cpp`, `fireworks2.cpp` som lager noen forskjellige frabrikker, og sender med en fabrikkpeker til hver rakett.
2. Det nye fyrverkeriet skal bygges med `make fireworks2` og skal kunne kjøres med `./fireworks2`. 
3. Implementér en asbrakt klasse, `AbstractDotFactory`, som har én "pure virtual" funksjon `dot* createDot()`
4. Lag nå tre konkrete subklasser av denne fabrikken: `NormalDotFactory`, som lager ca. like dotter som den første i videoen, `BlinkingDotFactory`, som produserer blinkende dotter, `TintedDotFactory`, som produserer dotter med "overvekt" av én selvvalgt farge, feks. lilla, og til sist en `MixedDotFactor`, som produserer ulike typer dotter (en av hver av typene over, med to-tre ulike tints), hver gang `create_dot` kalles. Du kan gjerne lage flere, men minst disse fire.
5. For hver av de tre typene dotter må det naturligvis finnes en egen subklasse av "dot". Disse blir "concrete products". Det er ikke nødvendig å gjøre "dot" abstrakt for å få til dette, siden den allerede har det den trenger av virtuelle funksjoner.

PS: Når du først har forstått hvordan fabrikkene fungerer er det *veldig lett* å lage flere; det er snakk om en håndfull linjer kode pr. fabrikk - det er bare snakk om å returnere nye typer dotter.

## 3) Template-parameter for TintedDotFactory
Endre `TintedDotFactory` til å ta en farge av typen [`FL_color`](http://www.fltk.org/doc-1.3/Enumerations_8H.html#a8b762953646f8abee866061f1af78a6a) som template-parameter, slik at `TintedDotFactory<FL_BLUE>::create_dot()` returnerer dotter som er "stort sett blå", `TintedDotFactory<FL_RED>` lager "stort sett røde" dotter osv.  Med "stort sett" mener vi at du kan randomisere litt av fargenyansen, men at det alltid skal være overvekt av denne ene fargen.  

For å generere ulike versjoner av fargene kan du bruke funksjonene `fl_darker` og `fl_lighter`.

Til slutt skal du utvide `fireworks2` til å la noen rockets få fabrikker med ulike "tints". Et eksempel på hvordan det kan se ut helt til slutt kan du se i [denne videoen](https://screencast.uninett.no/relay/ansatt/alfrebhioa.no/2015/19.03/14400/Fireworks2_CPP_2015_-_20150319_145220_36.html).

## 4) Kortsvarsspørsmål
Du skal svare på følgende spørsmål, i filen `answers_to_questions.md`:

  1. `animated.hpp` har et `protected` datamedlem. Er dette lurt? Nevn noen fordeler og ulemper, og hvordan dette kunne vært gjort anderledes for å unngå ulempene.
  2. Anta at vi ønsket å implementere fyrverkeriet med et annet grafikkbibliotek, `fancyGraphics (FG)`. Hva kunne vært gjort anderledes i designet for at dette skulle kunne blitt gjort enklere? (hint: ser på det som er lilla i klassediagrammet)
  3. Basert på ditt forrige svar; hvis du skulle laget ett eller flere "namespaces" i dette prosjektet, hvilke skulle det vært? Hvilke filer skulle vært med i hvilket namespace og hvilke filer skulle hatt `using namespace ...` for de ulike (hvis flere) namespacene?
  4. Klassene `animated` og `animation_canvas` legger opp til polymorfi. Kunne `animation_canvas` vært implementert med templates i stedet? Hva ville vært fordeler og ulemper?
  5. Bortsett fra det du har diskutert, ser du andre svakheter i designet, eller andre ting du ville gjort anderledes?

## 5) Implementasjon av egen animasjon (frivillig)

I tillegg til fyrverkeriet skal du lage en egen animasjon, som bruker det samme animasjonsrammeverket, dvs. `animated` og `animation_canvas`. Du står fritt til hva du vil lage her, og det trenger ikke være spesielt fancy. Målet er å vise at du forstår hvordan man skriver og bruker *gjenbrukbar kode*. Det stilles følgende krav til animasjonen:

  1. Det skal ikke være et nytt fyrverkeri
  2. Det må være minst tre elementer som animeres
  3. Din animasjon skal kunne bygges med `make custom` og kjøres med `./custom`

PS: Dette kan gjøres på noen veldig få linjer - det er en mulighet til å utfolde seg fritt, men trenger ikke ta mer enn en halvtime å lage, hvis du har skjønt koden.


#Lykke til!
