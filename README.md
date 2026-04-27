IVS Projekt - Kalkulačka 🧮
---------

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Platform: Ubuntu](https://img.shields.io/badge/Platform-Ubuntu%2064--bit-orange.svg)]()

Tento repozitář obsahuje týmový projekt pro předmět IVS (Praktické aspekty vývoje software). Jedná se o kalkulačku vytvořenou pomocí principů Test-driven development (TDD).

Vlastnosti a funkce
---------

* Základní matematické operace (sčítání, odčítání, násobení, dělení).
* Pokročilé operace: 
  * Faktoriál (`x!`)
  * Mocnina (`xⁿ`)
  * N-tá odmocnina (`ⁿ√x`)
  * Zaokrouhlovaní (`x~n`)
  * Absolutní hodnota (`|x|`)
* Výpočet směrodatné odchylky (externí utilita pro profiling).
* Grafické uživatelské rozhraní (GUI) s nápovědou.

Překlad a spuštění (Makefile)
---------

Projekt obsahuje `Makefile` s následujícími hlavními cíly:

| Příkaz | Popis |
|---|---|
| `make all` | Přeloží celý projekt (včetně programu pro profiling). |
| `make run` | Spustí grafické rozhraní kalkulačky. |
| `make test` | Spustí automatické testy matematické knihovny. |
| `make doc` | Vygeneruje programovou dokumentaci pomocí nástroje Doxygen. |
| `make stddev` | Spustí překlad programu pro výpočet směrodatné odchylky. |
| `make pack` | Zabalí projekt do archivu pro finální odevzdání. |
| `make clean` | Smaže všechny dočasné, objektové a vygenerované soubory. |
| `make help` | Zobrazí nápovědu pro kompilaci a spuštění v terminálu. |

Postup manuálního překladu
---------
Nutné balíčky pro kompilaci:
- `gcc` (pro překlad C kódu)
- `make` (pro správu build procesu)
- `doxygen` (pro generování dokumentace)
- `git` (pro klonování repozitáře)
- `zip`/`tar` (pro balení projektu)
- `qt6-base-dev` (pro grafické rozhraní)

*instalace balíčků se může lišit v závislosti na distribuci, například pro Ubuntu:*
```bash
sudo apt update
sudo apt install build-essential make doxygen git zip tar qt6-base-dev
```

1. **Získejte zdrojové kódy:**
   * Naklonováním repozitáře:
     ```bash
     git clone [https://github.com/HanzlikPetr/JuHaBeGl.git](https://github.com/HanzlikPetr/JuHaBeGl.git)
     ```
   * NEBO rozbalením odevzdaného `.zip`/`.tar.gz` archivu.

2. **Sestavení a spuštění:**
   Otevřete terminál, přejděte do kořenové složky projektu a zadejte:
   ```bash
   cd src
   make all
   make run

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

Ikona aplikace pochází z kolekce [Google Material Icons](https://fonts.google.com/icons) a je využívána za podmínek licence Apache 2.0.
