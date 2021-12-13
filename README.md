# Object Oriented Programming: Tirecenter

Project focussed on C++ OOP about a tirecenter.

![Class](Tire-Center-Class.png)

![Use case](./Tire-Center-Use-Case.png)

## TODO

- [ ] Use cases to finish
  - [ ] Filter tires/rims
  - [ ] Update stock?
- [ ] Invoice calc discount etc
  - [ ] fix discount
- [ ] Lookup invoice per customer
- [X] Loading and saving
  - [X] Articles
  - [X] Customers
  - [X] Invoices (has to be fixed)
  - [ ] Tirecenter (optionally)
- [ ] Error handling
  - [X] ~~Wrong input types~~ -> not necessary
- [ ] Make functions for reading lines (low priority)
- [X] Proper exit and back options in menus
- [ ] Styling (low priority)
  - [ ] Coloring
  - [ ] Spacing
- [ ] Minimize warnings
- [X] Abstract article class
- [ ] Clean up parameters in actions (full tirecenter not necessary)
- [X] convert to `nullptr`
- [X] fix customer constructor
- [X] Split up actions into header and cpp
- [ ] Convert files to lowercase
- [X] Delete all pointers in tirecenter/invoices deconstructor

## Project info

> De bandencentrale verkoopt banden en velgen in verschillende maten. Ze hebben hiervan een kleine stock, die ze graag met het programma zouden beheren. Ook willen ze de klanten in dit programma bijhouden en willen ze van elke klant weten welke banden en/of velgen deze gekocht hebben. Het programma moet de stock kunnen weergeven van alle banden en velgen die er verkocht worden. Ook indien ze niet voorradig zijn moeten deze weergegeven worden. De stock moet volledig kunnen weergegeven worden, maar er moet ook kunnen gefilterd worden op banden of velgen. Ook hadden ze graag kunnen filteren op maat. Banden worden verkocht per stuk of per set van 2 of 4 stuks, velgen steeds in sets van 4. Wanneer een medewerker de totale order van een klant heeft afgewerkt wordt deze stock geüpdate en wordt een factuur gemaakt met de prijs van de artikelen, de totaalprijs en de verkregen korting. Alle artikelen hebben een aantal vaste kenmerken, zoals een fabrikant, een naam en een diameter. Banden hebben als extra kenmerken een breedte en hoogte (in mm), een snelheidsindex (letter) en een seizoensaanduiding. Velgen hebben een breedte (in inch) en een kleur en zijn van staal of aluminium. Ook worden de klanten bijgehouden in het systeem. Er wordt een opsplitsing gemaakt tussen particuliere klanten en bedrijfsklanten. Zo krijgen bedrijfsklanten een andere prijs te zien dan particuliere klanten en kunnen ze een extra korting krijgen bij de aankoop vanaf 10 sets. Particuliere klanten krijgen een korting bij aankoop van een set van vier banden en extra korting bij de aankoop van een bijpassende set velgen. Elke opgemaakte factuur moet aan een klant gelinkt kunnen worden. De eigenaar en een medewerker moeten met het systeem kunnen werken. De eigenaar moet nieuwe artikels kunnen toevoegen en artikels kunnen verwijderen. Beide moeten in staat zijn om artikels te kunnen bekijken en filteren. Ook moeten zowel eigenaar als medewerker klanten kunnen toevoegen en bekijken en moeten ze per klant de facturen kunnen opvragen. Enkel de eigenaar moet in staat zijn om een klant te verwijderen (de bijhorende facturen moeten in het systeem aanwezig blijven).
