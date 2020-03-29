# Report

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
