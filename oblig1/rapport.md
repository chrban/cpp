

##Rapport BlackJack


**Veien hit**

Jeg startet med å skrive hele programmet rett fram, uten objekter i det hele tatt. 
Det gjorde jeg først og fremst for å komme igang, samt bli kjent med c++ syntaksen.
Det var interessant å gå gjennom forskjellige ideer for å representere en kortstokk! Det fikk meg til å tenke ut mange måter å gjøre det på. Jeg var f.eks innom doble arrays og enums før jeg representerte 52 kort i en int-array, hvor jeg regnet ut verdier basert på modulus regning.
Modulus 13 gav verdien på kortet, mens heltalldivisjon gav hvilket suit-intervall kortet tilhørte.

#####Etter seks versjoner med forbedringer av denne løsningen, bestemte jeg meg for å forkaste alt og løse oppgaven objektorientert.

**Gjeldende versjon**

Tanken om gjenbruk av kode gjorde at jeg skilte ut programmet i kort, og spiller-objekter. Dette kan enkelt implmenteres i framtidige spill. Blackjack filen min inneholder all spill-logikk. Her opprettes det vektorer av Spillere og en kortvektor, som representerer en kortstokk.
Kortobjektene er bygd opp slik at det enkelt kan genereres flere kortstokker i samme spill. Grunnet at jeg har litt knapt med tid før innleveringsfristen er imidlertid ikke dette 'aktivert' i spillet mitt. 

Spillgangen er slik at du velger antall spillere som skal delta, hvor du så angir hvor mye du ønsker å satse. 
Hver spiller spiller seg ferdig (bust/stand) før neste spiller slipper til. Pr nå er det slik at du selv stryrer
alle spillerene, men det er tenkt at dataspillere skal kunne ta egne valg. Koden for dette finnes allerede for dealer, og kan i prinsippet
enkelt tilføres til dataspillere. Igjen, grunnet lite tid velger jeg å nedprioritere dette.

Den største utfordringen jeg møtte på var selve spillogikken. Jeg fant ingen 'pen' måte å skrive gangen i spillet på.
Det er derfor et noe ugreit if/else cluster i koden min.. Kanskje kunne mye vært gjort om jeg hadde benyttet meg mer av switch-case, som kunne erstattet mye tilsynelatende rot.

Jeg vil presisere at jeg har et høyt ambisjonsnivå, men at at tiden ikke strekker til denne gangen. Det er mye jeg simpelten ikke rakk å implementere og teste. Blant annet har jeg lite testing av input, noe som absolutt bør være på plass!
Planleggingen min har ikke vært optimal, med tanke på at jeg skrev såpass mye kode som jeg endte opp med å forkaste. Likevel har måten jeg har jobbet meg framover på har vært veldig lærerik!



Kortstokken:
```
[ ♤ Ace ][ ♤ 2 ][ ♤ 3 ][ ♤ 4 ][ ♤ 5 ][ ♤ 6 ][ ♤ 7 ][ ♤ 8 ][ ♤ 9 ][ ♤ 10 ][ ♤ Jack ][ ♤ Queen ][ ♤ King ]
[ ♡ Ace ][ ♡ 2 ][ ♡ 3 ][ ♡ 4 ][ ♡ 5 ][ ♡ 6 ][ ♡ 7 ][ ♡ 8 ][ ♡ 9 ][ ♡ 10 ][ ♡ Jack ][ ♡ Queen ][ ♡ King ]
[ ♢ Ace ][ ♢ 2 ][ ♢ 3 ][ ♢ 4 ][ ♢ 5 ][ ♢ 6 ][ ♢ 7 ][ ♢ 8 ][ ♢ 9 ][ ♢ 10 ][ ♢ Jack ][ ♢ Queen ][ ♢ King ]
[ ♧ Ace ][ ♧ 2 ][ ♧ 3 ][ ♧ 4 ][ ♧ 5 ][ ♧ 6 ][ ♧ 7 ][ ♧ 8 ][ ♧ 9 ][ ♧ 10 ][ ♧ Jack ][ ♧ Queen ][ ♧ King ]
```
