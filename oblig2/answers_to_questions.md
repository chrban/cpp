## Kortsvarsspørsmål

  **`animated.hpp` har et `protected` datamedlem. Er dette lurt? Nevn noen fordeler og ulemper, og hvordan dette kunne vært gjort anderledes for å unngå ulempene.**

  Bruk av beskyttede variabler i en klasse anbefales ikke, siden variablene blir synlig for arvede klasser. Navnene på typer eller variablene i en base klasse kan da ikke bli endret siden de utledede klasser kan avhenge av dem.

 **Anta at vi ønsket å implementere fyrverkeriet med et annet grafikkbibliotek, `fancyGraphics (FG)`. Hva kunne vært gjort anderledes i designet for at dette skulle kunne blitt gjort enklere? (hint: ser på det som er lilla i klassediagrammet)**

  Gjøre det slik at alt som angår tegning av grafikk gjøres kun ett sted. Da vil kun en klasse trenge å implementere grafikkbiblioteket.

 **Basert på ditt forrige svar; hvis du skulle laget ett eller flere "namespaces" i dette prosjektet, hvilke skulle det vært? Hvilke filer skulle vært med i hvilket namespace og hvilke filer skulle hatt `using namespace ...` for de ulike (hvis flere) namespacene?**

  FG som namespace.
 

 **Klassene `animated` og `animation_canvas` legger opp til polymorfi. Kunne `animation_canvas` vært implementert med templates i stedet? Hva ville vært fordeler og ulemper?**

  Fordeler kan være at ytelsen øker siden templates løses ved kompilering.

  Ulemper med templates er at kompilatoren ikke gir gode feilmeldinger

**Bortsett fra det du har diskutert, ser du andre svakheter i designet, eller andre ting du ville gjort anderledes?**

 Slå sammen has_color og is_vector