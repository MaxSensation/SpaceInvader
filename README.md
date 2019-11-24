# SpaceInvader
 
## Uppgiftsbeskrivning, Programmeringsprojekt
Denna uppgift �r en obligatorisk inl�mningsuppgift p� delkursen CPROG,  Programmering i C och C++ HT2019. 

Uppgiften ska l�sas enskilt eller i grupper om h�gst tre personer.

Innan du s�tter ig�ng, s� ska du anm�la dig till en grupp i Daisy, gruppnumret i Daisy blir ditt gruppnummer.

L�sningen ska l�mnas in senast den 2020-01-18 f�r r�ttning i samband med kursen. Ett andra inl�mningstillf�lle kommer att ordnas i samband med omtentan, 2020-03-06. 



## Inl�mning 
Inl�mningen g�rs i denna kursmodul i iLearn, under rubriken Projektinl�mning.

Det som ska l�mnas in ska vara ett ZIP-arkiv inneh�llande sammanpackade k�llkods-filer samt datafiler mm som ing�r i l�sningen1, samt en README-fil som text eller PDF, med kortfattad instruktion f�r spelet och kommentarer, bl.a. ska programmets krav p� placering av datafiler (s�kv�gar) framg� av README-filen. I en inl�mningskommentar till inl�mningen i iLearn SKA gruppmedlemmarnas namn och personnr st�, samt vilken ev. till�ggsniv� [Basniv�, Till�ggsniv�1, �] gruppen g�r anspr�k p�. 

Om den inl�mnade l�sningen inte uppfyller kraven f�r godk�nt (Basniv�), s� f�r man betyget REST och kan komplettera inluppen inom anvgiven tid. Detta kan upprepas tv� g�nger, om l�sningen fortfarande inte uppfyller kraven f�r godk�nt efter tredje inl�mningen blir inluppen underk�nd och en ny inlupp ska l�sas n�sta g�ng kursen g�r.



1Obs allts�: inga projektfiler fr�n era programmeringsmilj�er, DLL:er, SDL-bibliotek osv.



## Uppgiften 
Uppgiften g�r ut p� att designa och implementera en liten spelmotor2 f�r 2D-spel och sedan skapa ett spel (ett till�mpningsprogram) med hj�lp av denna spelmotor.

Obs! att det "viktiga" i uppgiften �r den generella spelmotorn, ett API, medan spelet �r mest ett testprogram f�r API:et. 

Uppgiften �r mycket �ppen: du f�r sj�lv best�mma b�de designen av spelmotorn och sj�lva spelet. N�r det g�ller designen och implementeringen av spelmotorn �r det t�nkt att cwing-exemplet fr�n f�rel�sning kan ge en v�gledning, dessutom beskrivs grovt en m�jlig arkitektur nedan. 



2 Det har framf�rts kritik mot att vi kallar det h�r lilla projektet f�r en spelmotor eftersom spelmotorer �r normalt programsystem av en helt annan magnitud av storlek och komplexitet. Jag hittar dock inget b�ttre ord f�r beskrivningen av den generella delen av inluppen. 



## Beskrivning av t�nkt arkitektur 
Det �r t�nkt att spelmotorn best�r av en klass, s�g GameEngine, som implementerar (och d�ljer fr�n spelprogrammeraren) SDL:s h�ndelseloop, samt av en b�rjan till en klasshierarki f�r "sprite"-klasser. En sprite i ett spelprogram �r en tv�dimensionell figur som eventuellt kan r�ra sig �ver sk�rmen, av sig sj�lv eller styrd av anv�ndaren. Ett Sprite-objekt representeras p� sk�rmen av (�tminstone) en bild och man m�ste kunna rita ut Sprite:ns bild. Dessutom kan det beh�vas hj�lpklasser och -funktioner f�r att underl�tta spelprogrammeringen.

Eventuellt (Basniv�) kan Sprite-hierarkin best� av endast en rot-klass i den generella delen (om du inte hittar l�mpliga generella specialiseringar av Sprite-klassen) och �verl�ta �t den specifika speldelen att skapa l�mpliga subklasser.

Hos GameEngine ska man kunna installera sina Sprite-objekt och sedan beg�ra att "h�ndelseloopen" k�rs ig�ng, varefter Sprite-objekten b�rjar agera p� sk�rmen.

F�r samtliga Till�ggsniv�er ska man �ven kunna ange antalet frames per second (FPS) d.v.s. hur m�nga varv i loopen som (h�gst) ska k�ras per sekund (det inneb�r att man eventuellt beh�ver f�rdr�ja loopen om det visar sig att den g�r f�r snabbt). Man ska �ven kunna ta bort Sprite-objekt (som av n�gon anledning f�rsvunnit ur spelet, allts� att borttagande av Sprites ska vara implementerat i spelmotorn �ven om denna funktionalitet inte skulle beh�vas i det specifika spelet d�r ni testar spelmotorn.)

Till skillnad fr�n f�rel�sningsexempel ska GameEngine-loopen inte endast v�nta p� h�ndelser (anv�ndarens handlingar som tangentnedtryckningar, musr�relser eller mus-knapptryckningar) utan ge en takt i vilken Sprite-objekten ska agera. F�r varje varv i loopen, efter att ha kontrollerat om det finns n�gra anv�ndargenererade h�ndelser och i s� fall ha tagit hand om dem, ska man g� igenom alla installerade Sprite-objekt och anropa en medlemsfunktion (ofta kallas en s�dan medlemsfunktion tick) som uppdate-rar deras tillst�nd (t.ex. �ndrar positionen om objektet r�r sig o.s.v.). Denna metod b�r ta som argument n�got som ger Sprite-objekten �tkomst till omv�rlden, s� att de kan interagera med omv�rlden (t.ex. samlingen av andra Sprite-objekt eller sj�lva GameEngine-objektet). Det �r meningen att till�mpningar (de specifika spelen) ska kunna �verskugga denna medlemsfunktion i sina egna subklasser till Sprite eller dess subklasser.

I forts�ttningen kallar jag loopen f�r spelloop istf. h�ndelseloop.

I inl�mningsuppgiften �r det t�nkt att spelloopen agerar p� f�ljande s�tt:

(f�r Till�ggsniv� C och h�gre) om det finns anv�ndargenererade h�ndelser s� kollas om h�ndelsen �r ett kortkommando � i s� fall anropas motsvarande funktion 
annars skickas h�ndelsen vidare till Sprite-objekten
Sprite-objekten g�s igenom och deras tick-funktion anropas (uppdatering sker)
Sprite-objekten g�s igenom och ritas upp p� sk�rmen (i det uppdaterade tillst�ndet)
tiden kontrolleras och eventuell f�rdr�jning framkallas
I sin interaktion med omv�rlden b�r Sprite-objekt kunna kontrollera om de har kolliderat med n�got (t.ex. med andra Sprite-objekt) (kollisionsdetektering). Detta kan inte programmeras in i den generella delen (det �r alltf�r spelspecifikt) men det ska f�rberedas: det ska finnas funktioner (eller medlemsfunktioner hos n�gon klass) som kan kontrollera om ett Sprite-objekt har kolliderat med ett annat. Hur finmaskig denna kontroll ska g�ras beror p� vilken Till�ggsniv�, f�r Till�ggsniv� l�gre �n A r�cker det med kontroll av de omgivande rektanglar, f�r Till�ggsniv� A ska kontrollen g�ras p� pixelniv�.


## Krav och kriterier p� l�sningen
Det �r ett krav att det f�rdiga programmet ska best� av en mer generell del (spelmotorn) och en mer specifik del (ditt specifika spel). Spelmotorn ska vara utformad s� att man enkelt och utan att beh�va modifiera koden f�r spelmotorn kan skapa andra spel av samma typ.

Nedan f�ljer kraven som st�lls p� den generella delen, det finns �ven krav p� det spel som ska skapas f�r att testa spelmotorn, dessa beskrivs l�ngre ner p� sidan, kraven p� spelet m�ste helt enkelt vara uppfyllda.

F�r att f� godk�nt p� den generella delen, m�ste nedanst�ende krav f�r Basniv� vara uppfyllda. Till�ggsniv�erna bygger p� varandra, s� f�r att uppfylla Till�ggsniv� C, s� m�ste �ven Till�ggsniv� D vara uppfylld. Id�en med Till�ggsniv�er �r till f�r att var och en ska kunna utmana sig sj�lv, och v�lja problem efter ambitionsniv�. N�r du uppfyllt kraven f�r Till�ggsniv� D, och det finns tid �ver, s� utmana dig sj�lv och f�rs�k ut�ka dina krav med n�sta Till�ggsniv�. 

F�r Basniv� g�ller f�ljande krav:

programmet ska kodas i C++ och anv�nda grafikbiblioteket SDL (n�rmare best�mt SDL2)
objektorienterad programmering ska anv�ndas: programmet ska vara uppdelad i klasser med anv�ndning av oo-tekniker som inkapsling, arv och polymorfism
till�mpningsprogrammeraren ska skyddas mot att g�ra sv�ruppt�ckta fel som att anv�nda v�rdesemantik f�r objekt av polymorfa klasser
det ska finnas en gemensam basklass (s�g Sprite) f�r alla figurer, denna basklass ska vara f�rberedd f�r att vara en rotklass i en klasshierarki (om till�mpningsprogrammet �nskar g�ra subklasser till den)
inkapsling: datamedlemmar ska vara privata om inte v�ldigt speciella sk�l f�religger
det ska inte finnas n�got minnesl�ckage, du ska se till att dynamiskt allokerat minne st�das bort
spelmotorn ska kunna ta emot input (tangentbordsh�ndelser, mush�ndelser) och reagera p� dem enligt till�mpningsprogrammets �nskem�l, eller vidarebefordra dem till till�mpningens objekt
enkel kollisionsdetektering: man ska kunna kolla om den omgivande rektangeln f�r en Sprite har kolliderat med den omgivande rektangeln f�r en annan Sprite
programmet ska vara kompilerbart och k�rbart p� en dator under b�de Linux och MS Windows (allts� inga plattformspecifika konstruktioner) med SDL 2 och SDL_ttf, SDL_image och SDL_mixer (Om man vill programmera med andra bibliotek kan man f� dispens fr�n detta krav men det kr�ver en �verenskommelse med kursansvarige)
F�r Till�ggsniv� D tillkommer f�ljande krav:

man ska kunna ange en h�gsta "frame rate" (antalet frames per sekund)
det ska finnas olika typer av Sprites i en klasshierarki i den generella delen, det kan t.ex. vara r�rliga Sprites (f�r figurer som flyttar sig sj�lva och d�r man kan ange hur mycket de ska flytta sig i x- resp. y-led per tick) och or�rliga Sprites. Objekt av dessa klasser ska endast kunna skapas dynamiskt och v�rdesemantik ska vara f�rbjuden f�r dem
F�r Till�ggsniv� C g�ller samma krav som f�r D och �ven f�ljande krav:

en av subklasser till Sprite ska kunna vara en animerad figur, representerad internt antingen med flera bilder som v�xlar efter ett angivet antal tick eller med en sprite sheet
spelmotorn ska vara f�rberedd f�r att till�mpningen vill installera kortkommandon (enkla tangenttryckningar). Till�mpningen ska kunna ange en tangent och en call back-funktion som ska anropas d� denna tangent har tryckts ner
F�r Till�ggsniv� B g�ller samma krav som f�r C och �ven f�ljande:

spelmotorn ska vara f�rberedd f�r hantering av spelniv�er (levels). Till�mpningar ska kunna skapa flera olika "scener" best�ende av olika Sprite-objekt och bakgrundsbilder och l�tt v�xla mellan dem
kortkommandon (tangenttryckningar) ska kunna knytas �ven till medlemsfunktioner i angivna objekt (f�rutom till fria funktioner). Det ska vara l�tt f�r till�mpningen att ange antingen en funktionspekare till en fri funktion eller kombinationen av en objektpekare och en funktionsmedlemspekare tillsammans med tangenten
det ska finnas en grafisk komponent (Sprite-subklass?) som ska kunna anv�ndas som ett inmatningsf�lt f�r text, som till�mpningen kan anv�nda f�r textinmatning (t.ex. namn p� spelaren f�r en highscore-lista). Det beh�ver inte (men f�r g�rna) finnas editeringsm�jligheter f�r inmatningsf�ltet.
F�r Till�ggsniv� A g�ller samma krav som f�r B och dessutom:

kollisionsdetektering ska g�ras p� pixelniv�, med h�nsyn tagen till genomskinliga pixlar
spelmotorn ska implementera viss funktionalitet hos en fysikmotor, n�mligen att r�rliga Sprites kan p�verkas av en gravitation samt ska kunna studsa mot varandra vid kollision osv. Sprites ska ha en viss elasticitet som p�verkar deras studsbeteende.

## Ett spel
Du ska sj�lv v�lja vilket spel du vill skapa i din spelmotor. Det ska dock vara av typen arkadspel d.v.s. ett tv�dimensionellt spel med r�rliga figurer (sprites) av vilka en styrs av anv�ndaren. Klassiska spel som SpaceInvaders och PacMan, eller plattformspel som Mario och Sonic �r exempel p� s�dana spel. H�r �r n�gra l�nkar som kan ge inspiration:

http://en.wikipedia.org/wiki/Space_Invaders 
http://en.wikipedia.org/wiki/Breakout_(arcade_game)
http://en.wikipedia.org/wiki/Arkanoid
http://en.wikipedia.org/wiki/Pac_man 
http://www.2dplay.com/
Spelet skall ha f�ljande egenskaper(krav):

Spelet ska simulera en v�rld som inneh�ller olika typer av objekt. Objekten ska ha olika beteenden och r�ra sig i v�rlden och agera p� olika s�tt n�r de m�ter andra objekt.
Det m�ste finnas minst tv� olika typer av objekt och det ska finnas flera instanser av minst en av dessa. T.ex ett spelarobjekt och m�nga instanser av fiendeobjekt.
Ett beteende som m�ste finnas med �r att figurerna ska r�ra sig �ver sk�rmen. R�relsen kan f�lja ett m�nster och/eller vara slumpm�ssig.
Det r�cker att grafiken �r tv�dimensionell (f�r enkelhetens skull).
V�rlden (spelplanen) kan antas vara lika stor som f�nstret (du kan g�ra en st�rre spelplan med panorering, men det blir lite kr�ngligare).
En figur ska styras av spelaren, med tangentbordet eller med musen. Du kan �ven g�ra ett spel d�r man spelar tv� stycken genom att dela p� tangentbordet (varje spelare anv�nder olika tangenter). D� styr man var sin figur.
Det ska h�nda olika saker n�r objekten m�ter varandra, de ska p�verka varandra p� n�got s�tt. T.ex kan ett av objekten tas bort, eller s� kan objek-ten f�rvandlas p� n�got s�tt, eller s� kan ett nytt objekt skapas. (Ett exempel p� att skapa/ta bort objekt �r n�r man i Space Invaders trycker p� skjuta- knappen, t.ex en musknapp, d� avfyras ett laserskott och skottet blir d� en ny figur som skapas och placeras i v�rlden, p� en position vid laserkanonens mynning. Skottet r�r sig fram�t (upp�t) och om det tr�ffar ett fiendeskepp tas b�de skottet och skeppet bort, om skottet kommer utanf�r spelplanen, dvs det missar, tas endast skottet bort.