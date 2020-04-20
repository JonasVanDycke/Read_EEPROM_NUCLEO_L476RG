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
De code die ik gebruikt heb vind u in oderstaande link: <https://os.mbed.com/forum/mbed/topic/3856/?page=1#comment-56893>

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
Het opzoeken hoe de 'format specifier' werkt en zelf hieruit een opstelling maken. (Link i.v.m. 'format specifier':<http://www.cplusplus.com/reference/cstdio/printf/>)
In de code die ik op dit moment heb kom ik het volgende uit voor de 'L dongle':
//////////////////////////////////
Register1 0x0000 = 0x5f 0x97 0x0 0x8 0x0 0x0 0x0 0x0
Register2 0000 = 0x5f 0x97 0 0x8 0 0 0 0
Register3 0x0 = 0x5f 0x97 0x0 0x8 0x0 0x0 0x0 0x0
Register4 0 = 0x5f 0x97 0 0x8 0 0 0 0

## Woensdag 15/04/2020 van 14u45 tot 17u15

Heropzoeken/opfrissen hoe alles weer in elkaar zit en wat er moet gebeuren.
En ondertussen verder gezocht (bv. verschil tussen 'Random Read' en 'Sequential Read').

## Donderdag 16/04/2020 van 11u tot 13u10 en 14u tot 14u15 en 15u tot 18u

### 11u tot 13u10

Verder opzoek werkgedaan (i.v.m. het opstellen van de code).

### 14u tot 14u15 en 15u tot 18u

Verder opzoek werkgedaan (i.v.m. het opstellen van de code).
En hulp gevraagt i.v.m. uitlezen EEPROM's.

## Vrijdag 17/04/2020 van 14u30 tot 18u40

Bij het proberen uitlezen van een Dongle (EEPROM) a.d.h.v. vorige code kwam men volgend resultaat uit:

```
Reading from eeprom
Printing the read data from eeprom to Serial device
0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0
0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0
0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0
```

Na de aanpassen van de Buffers (`char buffer[lengthTest] = {0};` naar `char buffer[lengthTest];`) kreeg ik als uitgang:

```
Reading from eeprom
Printing the read data from eeprom to Serial device
0x2 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x13 0x4 0x0 0x8
0x9c 0xb 0x0 0x20 0x0 0x0 0x0 0x20
0x80 0x25 0x0 0x0 0x0 0x0 0x0 0x0 0x88 0xf 0x0 0x20 0x2
```

Verder getest door waarden te veranderen en de uitkomsten vergelijken bij de aanpassingen, maar bekom nog niet de juiste waarden uit.

## Zaterdag 18/04/2020 van 14u45 tot 16u20 en 17u30 tot 18u40

### 14u45 tot 16u20

Opstelling van de Dongle aangepast volgens de opstelling van de link, zonder de condensator <http://dangerousprototypes.com/blog/2012/10/17/how-to-use-the-bus-pirate-onboard-24aa-i2c-eeprom/>
Aan de hand van deze opstelling, verder kijken of er geen verandering is bij het uit lezen. 

Bij het uitlezen van de `Dongle L` kreeg ik als uitkomst:
(Gewenste waarde `01a2...`)
```
Reading from eeprom
Printing the read data from eeprom to Serial device
01 a2 eb 34 4e dc 7c 5a
0x01 0xa2 0xeb 0x34 0x4e 0xdc 0x7c 0x5a
```

Bij het uitlezen komen de eerste 2 bytes overeenkomen met de gewenste 2 bytes zoals gevraagt.

### 17u30 tot 18u40

De bytes uilezen van de andere Dongles.

Uitlezen van `Dongle NB` (Gewenste waarde `0164...`):

```
Reading from eeprom
Printing the read data from eeprom to Serial device
01 64 a5 47 98 d7 d2 7a
0x01 0x64 0xa5 0x47 0x98 0xd7 0xd2 0x7a
```

Uitlezen van `Dongle SS` (Gewenste waarde `0136...`):

```
Reading from eeprom
Printing the read data from eeprom to Serial device
01 36 ed ca af 28 5d 1d
0x01 0x36 0xed 0xca 0xaf 0x28 0x5d 0x1d
```

Uitlezen van `Dongle ADA` (Gewenste waarde `016b...`):

```
Reading from eeprom
Printing the read data from eeprom to Serial device
01 6b c4 46 42 86 f3 fb
0x01 0x6b 0xc4 0x46 0x42 0x86 0xf3 0xfb
```

## Zondag 19/04/2020 van 14u tot 15u25

Herschikken en vereenvoudigen code.
Code om uit de 8bytes uit te lezen in File 'ReadOnly.cpp' geplaatst.
(Ook nog wat met oude code geprutst).


## Maandag 20/04/2020 van 11u15 tot 13u30

Na meating leerkrachten, heb ik zelf gekeken om een code te schrijven die de data uitleest.
(Waarvan ongeveer 90% zelf gemaakt is)
