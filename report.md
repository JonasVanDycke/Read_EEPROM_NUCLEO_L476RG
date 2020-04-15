# Report

<!--git push https://github.com/vives-projectwerk-2-2020/Read_EEPROM_NUCLEO_L476RG.git-->

## Zondag 22/03/2020 van 14u30 tot 17u30

Verbinding kunnen maken met de Nucleo (ik wist niet hoe je code naar de Nucleo stuurde, is nu opgelost).
Het opzoeken van code om de EEPROM te lezen (ik heb nog niets concreets gevonden, nog mee bezig).

## Maandag 23/03/2020 van 14u tot 19u30

Ik heb eerst op een kladblad appart de pinwaarden van de EEPROM opgeschreven en de pinnen die met de dongle overeenkomen. Hierachter heb ik de opstelling gemaakt voor het uitlezzen van de EEPROM.
Maar aangezien ik nog geen werkende code had, ben ik verder beginnen kijken voor eventuele code om de EEPROM's mee uit te lezen. Waarbij ik hier en daar een paar dingen gevonden heb, maar al snel ondervond dat ik niet visueel de uitkomende data van de EEPROM kon zien.
Na wat verder zoeken hoe ik visueel de data kan zien, vond ik dat 'Putty' kon gebruikt worden. Bij het uitvoeren van 'Putty' kwam ik voor de eerste EEPROM 'NB' de uitkomst van "Register 0xe0 = 0x0 0x0 0x0 0x85 0x2b 0x0 0x8".
Ik weet niet of dit correct is, maar het is al een goede stap in de juiste richting. Ik heb hier lang aan bezig geweest, maar ik begrijp nu beter waar ik mee bezig ben en hoe het in elkaar zit.
De code die ik gebruikt heb vind u in oderstaande link: https://os.mbed.com/forum/mbed/topic/3856/?page=1#comment-56893

## Dinsdag 24/03/2020 van 15u tot 17u30

Het installeren en testen van "stm32cubeIDE" voor eventueel gebruik om de Nucleo te programeren.

## Vrijdag 27/03/2020 van 14u20 tot 17u40

Het uitlezen van NB EEPROM, waarbij ik een paar aanpasingen heb gemaakt. Hierbij heb ik voor elke andere uitkomst de code in een 'test.txt' file gezet.
Bij elke 'test' staat er onderaan de verkregen uitkomst.
Ook heb ik een andere EEPROM getest (dongle 'L') en kwam ik het zelfde uit als de vorige EEPROM. Dit betekent dat er duidelijk fouten in de code zijn. Ik zal deze de volgende keer oplossen.

## Zondag 29/03/2020 van 15u30 tot 20u40

Het verder bekijken van waar mogelijks de fouten in de code zitten.
En het testen van de code door kleine aanpassingen te maken in de code.
Verder online opzoeken hoe de EEPROM's worden uitgelezen.

## Maandag 30/03/2020 van 15u30 tot 19u15

Het verder zoeken om de 8 bytes te kunnen uitlezen.
Het opzoeken hoe de 'format specifier' werkt en zelf hieruit een opstelling maken. (Link i.v.m. 'format specifier':http://www.cplusplus.com/reference/cstdio/printf/)
In de code die ik op dit moment heb kom ik het volgende uit voor de 'L dongle':
//////////////////////////////////
Register1 0x0000 = 0x5f 0x97 0x0 0x8 0x0 0x0 0x0 0x0
Register2 0000 = 0x5f 0x97 0 0x8 0 0 0 0
Register3 0x0 = 0x5f 0x97 0x0 0x8 0x0 0x0 0x0 0x0
Register4 0 = 0x5f 0x97 0 0x8 0 0 0 0

## Woensdag 15/04/2020 van 14u45 tot 17u15

Heropzoeken/opfrissen hoe alles weer in elkaar zit en wat er moet gebeuren.
En ondertussen verder gezocht (bv. verschil tussen 'Random Read' en 'Sequential Read').
