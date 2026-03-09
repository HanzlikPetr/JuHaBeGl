IVS Projekt - Kalkulačka
---------

Tento repozitář obsahuje týmový projekt pro předmět IVS (Praktické aspekty vývoje software). Jedná se o kalkulačku se základními a pokročilými matematickými operacemi (faktoriál, mocnina, odmocnina), vytvořenou pomocí principů Test-driven development (TDD).

Překlad a spuštění (Makefile)
---------

Projekt obsahuje `Makefile` s následujícími hlavními cíly:

* `make all` - Přeloží celý projekt (včetně programu pro profiling).
* `make run` - Spustí grafické rozhraní kalkulačky.
* `make test` - Spustí automatické testy matematické knihovny.
* `make doc` - Vygeneruje programovou dokumentaci (Doxygen).
* `make stddev` - Spustí překlad programu pro výpočet směrodatné odchylky (profiling).
* `make pack` - Zabalí projekt pro odevzdání.
* `make clean` - Smaže všechny dočasné a vygenerované soubory.
* `make help` - Zobrazí nápovědu pro kompilaci a spuštění.

Postup manuálního překladu
---------

1. Získejte zdrojové kódy:
   * Naklonováním repozitáře: `git clone <odkaz-na-vas-repozitar>`
   * NEBO rozbalením odevzdaného archivu.
2. Otevřete terminál a přejděte do kořenové složky projektu.
3. Přeložte projekt příkazem: `make all` 
4. Spusťte program příkazem: `make run`

*(INSTALATORY BUDOU DOPLNENY)*

Prostredi
---------

Ubuntu 64bit

Autori
------

JuHaBeGl
- xhanzlp00 Petr Hanzlík
- xjurokv00 Vojtěch Jurok
- xberanm00 Marek Beran
- xgleton00 Ondřej Glet

Licence
-------

Tento program je svobodný software a je distribuován s otevřenými zdrojovými texty pod licencí GNU GPL v. 3. Můžete jej šířit a upravovat podle ustanovení této licence.
