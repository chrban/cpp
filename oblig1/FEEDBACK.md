# Oblig 1

### Resultat: 
Godkjent!

### Checklist:
* [x] Begge programmen bygger med `make`.
* [x] Begge programmen starter og kjører under Linux.
* [x] **oppvarming** gir riktig output.
* [x] **blackjack** har det viktigeste funksjonaliteten.
	* [x] En spiller har et saldo og kan satse et beløp.
	* [x] En spiller har valgen "HIT" og "STAND".
	* [x] En spiller kan ikke fortsette når den har gått tom for penger.
	* [x] Dealerns handlinger virker riktige.
	* [x] Spillet følger reglene til BlackJack.
* [x] Ingen alvorlige kjøretidsfeil (segfault etc.)
* [x] Ingen minnelekasjer funnet med `valgrind`.
* [x] Repo innholder `RAPPORT.md`.



### Tilbakemelding:

Et stort pluss for multiplayer, ser ut til å fungere bra! Digger også "grafikken" - kult! :)

Er også et pluss for at du levert en objektorientert løsning med separate filer og headers. Synes klassene dine og koden ser ryddig og bra ut.

Har funnet en logisk feil i spillet ditt. Hvis en spiller taper på å gå BUST, og summen av disse korten er større enn dealers, så vil spilleren fortsatt vinne penger (dette gjelder ikke hvis man velger "STAND"). Se eksempel:

	Player nr.1,  you have $ = 6600
	
	Place your bet: 6600 
	______________________________________________________________________________
	
	
	
	Player nr.1,  your cardValue is: 19                         Money at stake: $6600
	
	
	
	[ ♧ 9 ] [ ♤ Jack ] 
	
	
	 Hit or Stand?   (1 = HIT, 2 = STAND) 1
	______________________________________________________________________________
	
	
	    _               _           _       
	   | |             | |         | |      
	   | |__  _   _ ___| |_ ___  __| |      
	   | '_ \| | | / __| __/ _ \/ _` |      
	   | |_) | |_| \__ \ ||  __/ (_| |_ _ _ 
	   |_.__/ \__,_|___/\__\___|\__,_(_|_|_)
	
	  CardValue is: 25
	
	[ ♧ 9 ] [ ♤ Jack ] [ ♤ 6 ] 
	Dealer has:  15
	[ ♤ 9 ] [ ♢ 6 ] 
	
	______________________________________________________________________________
	
	
	Dealer hitter!
	
	
	Dealer has:  20
	
	
	
	[ ♤ 9 ] [ ♢ 6 ] [ ♤ 5 ] 
	
	
	(Dealer tenker..) 
	______________________________________________________________________________
	
	
	Dealer velger å stå på: 20
	
	
	Utbetalt $13200  til spiller 1 (Slo dealer)
	Fjernet $-6600  fra spiller 1 sin konto (BUSTED))
	  ...Starting
	       _   _  _______   _______       
	      | \ | ||  ___\ \ / /_   _|      
	      |  \| || |__  \ V /  | |        
	      | . ` ||  __| /   \  | |        
	      | |\  || |___/ /^\ \ | |        
	      \_| \_/\____/\/   \/ \_/        
	                                      
	                                      
	      ______ _____ _   _ _   _______  
	      | ___ \  _  | | | | \ | |  _  \ 
	      | |_/ / | | | | | |  \| | | | | 
	      |    /| | | | | | | . ` | | | | 
	      | |\ \\ \_/ / |_| | |\  | |/ /  
	      \_| \_|\___/ \___/\_| \_/___/   
	
	______________________________________________________________________________
	
	
	Player nr.1,  you have $ = 13200

En annen ting, som du nevner i rapporten din, er input-validering. Det går her å føre inn 0 eller et negativt antall spillere (krasjer spillet), og det er også mulig å bette 0 eller et negativt beløp.