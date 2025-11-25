# Physics Engine

Quick guide for building, running, and testing the project. This project uses CMake and GoogleTest.

If you want automation (scripts / CI) after that, I can add them.

---

## Table of Contents
- [Requirements](#requirements)
- [Quick Build (minimal)](#quick-build-minimal)
- [Recommended Build (out-of-source)](#recommended-build-out-of-source)
- [Using Ninja](#using-ninja)
- [Running the main executable](#running-the-main-executable)
- [Tests (CTest / GoogleTest)](#tests-ctest--googletest)
- [Running a specific test](#running-a-specific-test)
- [Common issues and troubleshooting](#common-issues-and-troubleshooting)
- [Project structure](#project-structure)
- [Helpful commands / Shortcuts](#helpful-commands--shortcuts)

---

## Requirements
- CMake >= 3.14
- C++ compiler supporting C++23 (gcc / clang)
- Ninja (optional, recommended for faster builds)
- make (if not using Ninja)
Optional tools: `gdb`, `valgrind` for debugging

Check CMake version with:
```sh
cmake --version
```

---

## Quick Build (minimal)
If you just want to quickly build in-source (not recommended for long-term) — run:
```sh
# from project root
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j$(nproc)
```
Then run the executable (example path):
```sh
# from project root
./build/main/main_exec
```

Note: The `..` method uses an out-of-source directory `build/` since you `cd` into it; it's simpler than generating build files inside the source tree.

---

## Recommended Build (out-of-source, single command)
Preferred for scripts or CI — keep source and build outputs separate:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -- -j$(nproc)
# or with modern CMake
cmake --build build --parallel $(nproc)
```

This keeps your working tree clean and allows multiple builds (e.g. `build-debug` and `build-release`).

---

## Using Ninja
If you have `ninja` installed, it is faster for parallel builds:
```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

---

## Running the main executable
Default executable target is `main_exec` (see `main/CMakeLists.txt`). After a successful build run:
```sh
./build/main/main_exec
```
If you can't find it:
```sh
find build -type f -executable -name "main_exec" -print
```

---

## Tests (CTest / GoogleTest)
The top-level `CMakeLists.txt` has an option `BUILD_TESTS` (OFF by default).

1) Configure the build with tests enabled:
```sh
cmake -S . -B build -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build -- -j$(nproc)
```

2) Run all tests using CTest (parallel example):
```sh
ctest --test-dir build --output-on-failure -j 4
# or from the build directory:
cd build && ctest --output-on-failure --parallel 4
```

3) List tests (no run):
```sh
ctest --test-dir build -N
```

---

## Running a specific test (GoogleTest)
You can also run a single test binary directly and use GoogleTest filters:
```sh
# tests executable is usually in build/tests/tests_exec
./build/tests/tests_exec --gtest_filter=Vector2D_TF.test_getter
```

To run tests that match a regex using ctest:
```sh
ctest --test-dir build -R Vector2D
```

---

## Common issues and troubleshooting (⚠️)
- No `main_exec` target: ensure `BUILD_MAIN_EXEC=ON` and `main/` subdirectory exists in `CMakeLists.txt`.
- No tests found: make sure `-DBUILD_TESTS=ON` was passed and `tests/` contains test targets.
- Undefined reference during linking: verify `target_link_libraries` is correct, e.g. `main_exec` links `physics_2d` and `rigid_body`.
- `-j$(nproc)` overloads your machine: lower the number or use `-j4`.
- To clean build: `rm -rf build` and re-run CMake.

If a public header from `rigid_body` uses `Vector2D`, `rigid_body` should link to `physics_2d` as `PUBLIC` (this project already does that).

---

## Project structure (high-level)
- `main/` — main executable (`main_exec`), links `physics_2d`, `rigid_body`.
- `physics/physics2d/vector` — `physics_2d` library for vector math.
- `physics/rigid_body` — `rigid_body` library that depends on `physics_2d`.
- `tests/` — unit tests (GoogleTest) for core components.
- `CMakeLists.txt` — top-level CMake configuration.

---

## Useful commands / short examples
```sh
# Full configure + build + test in one line:
cmake -S . -B build -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug && cmake --build build -- -j$(nproc) && ctest --test-dir build --output-on-failure --parallel $(nproc)

# Clean build
rm -rf build

# Add one less thread for build (reserve one CPU):
cmake --build build -- -j$(( $(nproc) - 1 ))
```

---

## Want automation? (optional)
I can add simple scripts: `scripts/build.sh`, `scripts/test.sh` and a basic GitHub Actions workflow that runs build/test on push/PR. Tell me if you want that and I'll add them.

---

If you want `README` to contain more details (examples using Valgrind or GDB, CI snippets, or a contributing guide), tell me what to add.


# Physics Engine

Krótki przewodnik jak budować projekt, uruchamiać wykonywalny plik `main_exec`, uruchamiać testy i debugować typowe problemy.

✅ Dla kogo: C++ dev, Linux (bash/zsh). Projekt używa CMake i GoogleTest (jako zależność w build). 

---

## Spis treści

- [Wymagania](#wymagania)
- [Szybkie polecenia (najprościej)](#szybkie-polecenia-najprościej)
- [Konfiguracja i build (zalecane)](#konfiguracja-i-build-zalecane)
- [Uruchamianie programu](#uruchamianie-programu)
- [Testy (z CMake/CTest / GoogleTest)](#testy-z-cmakectest--googletest)
- [Uruchamianie konkretnego testu](#uruchamianie-konkretnego-testu)
- [Debugowanie i tipy](#debugowanie-i-tipy)
- [Struktura projektu](#struktura-projektu)

---

## Wymagania

- CMake (>= 3.14 zalecane)
- Kompilator kompatybilny z C++23 (gcc/clang)
- Ninja (opcjonalnie, zalecane do szybszego buildu)
- make (jeżeli nie używasz Ninja)
- (opcjonalnie) gdb, valgrind, perf do debugowania / profilowania

Sprawdź wersję CMake:

```zsh
cmake --version
```

---

## Szybkie polecenia (najprościej)

Jeżeli chcesz szybko zbudować projekt i uruchomić: 

```zsh
# W katalogu repo (gdzie jest top-level CMakeLists.txt) 
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j$(nproc)

# uruchom program
# (najpewniej binarny: ./build/main/main_exec)
cd ..
./build/main/main_exec
```

> Uwaga: to jest out-of-source build — wszystkie artefakty (obj, .a, etc.) są w katalogu `build/`.

---

## Konfiguracja i build (zalecane, bez cd)

Dla skryptów i CI preferujemy jednoznaczny sposób: `-S` (source) i `-B` (build dir).

```zsh
# konfiguracja (Debug lub Release)
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# build
cmake --build build -- -j$(nproc)
# alternatywnie, jeżeli CMake obsługuje --parallel
cmake --build build --parallel $(nproc)
```

Z Ninja (szybsze):

```zsh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

---

## Uruchamianie programu

Główny target to `main_exec` (zdefiniowany w `main/CMakeLists.txt`). Po budowie, wykonaj:

```zsh
./build/main/main_exec
```

Jeżeli nie jesteś pewien gdzie znajduje się binarka, wyszukaj ją:

```zsh
find build -type f -executable -name "main_exec" -print
```

---

## Testy (z CMake/CTest / GoogleTest)

Top-level `CMakeLists.txt` ma opcję `BUILD_TESTS` (domyślnie OFF).

1) Konfiguracja i włączenie testów

```zsh
cmake -S . -B build -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build -- -j$(nproc)
```

2) Uruchomienie wszystkich testów

```zsh
ctest --test-dir build --output-on-failure -j 4
# lub (jeśli jesteś w katalogu build):
cd build
ctest --output-on-failure --parallel 4
```

3) Lista wszystkich testów (bez uruchamiania):

```zsh
ctest --test-dir build -N
```

4) Poniższy przykład uruchamia tylko testy związane z Vector2D (regex):

```zsh
ctest --test-dir build -R Vector2D
```

---

## Uruchamianie konkretnego testu (GoogleTest)

Możesz także uruchomić konkretny test executable bezpośrednio:

```zsh
# lista testów i plik wykonywalny prawdopodobnie znajduje się
# build/tests/tests_exec
./build/tests/tests_exec --gtest_filter=Vector2D_TF.test_getter
```

Możesz użyć filtrów GoogleTest, np. `--gtest_filter=SuiteName.testName`

---

## Najczęstsze problemy i debugowanie (⚠️)

- Nie znaleziono targetu `main_exec`:
  - Upewnij się, że `BUILD_MAIN_EXEC` jest ON (domyślnie ON w top-level `CMakeLists.txt`) lub że katalog `main` został dodany.

- Brak testów ("No tests were found"):
  - Upewnij się, że zbudowałeś projekt z `-DBUILD_TESTS=ON` i że katalog `tests/` rzeczywiście zawiera `CMakeLists.txt` z `add_test`.

- Błędy linkera (undefined reference):
  - Sprawdź czy `target_link_libraries` zawiera poprawne biblioteki i czy linkujesz odpowiedni target. W tym repo, `main_exec` linkuje `physics_2d` i `rigid_body`.
  - Sprawdź, czy bibliotekę (static `.a`) rzeczywiście zbudowano (np. `build/physics/physics2d/vector/libphysics_2d.a`).

- Symbol nieznany w publicznym API `rigid_body`:
  - Jeśli `rigid_body` w nagłówkach (`includes/`) używa `Vector2D`, to `target_link_libraries(rigid_body PUBLIC physics_2d)` jest poprawne. Nie zmieniaj na `PRIVATE` jeśli nagłówki zależą od `physics_2d`.

- Zbyt duża liczba jednoczesnych zadań (-j):
  - `-j$(nproc)` przyspiesza build; na słabszych maszynach zmniejsz liczbę, np. `-j4`.

- Chcesz czysty build:

```zsh
rm -rf build
```

---

## Debug (gdb, valgrind)

Uruchom kolejno z gdb lub valgrind, jeśli coś się grzebie w runtime:

```zsh
gdb --args ./build/main/main_exec <args>
# valgrind
valgrind --leak-check=full ./build/main/main_exec
```

---

## Struktura projektu (skrót)

- `main/` — główny program `main_exec` (linkuje `physics_2d`, `rigid_body`)
- `physics/physics2d/vector` — biblioteka `physics_2d` (vektory)
- `physics/rigid_body` — `rigid_body` (zależne od `physics_2d`)
- `tests/` — testy jednostkowe (GoogleTest)
- `CMakeLists.txt` — top-level CMake

---

## Przydatne polecenia (skróty)

```zsh
# configure + build + run tests (one-liner)
cmake -S . -B build -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug && cmake --build build -- -j$(nproc) && ctest --test-dir build --output-on-failure --parallel $(nproc)

# zestaw debugowy:
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug && cmake --build build-debug && ctest --test-dir build-debug --output-on-failure
```

---

## Chcesz automatyzację? (Opcjonalne skrypty)

Możemy dodać prosty `scripts/build.sh` i `scripts/test.sh`, jeśli chcesz. Napisz, a zrobię to za Ciebie.

---

Jeśli chcesz, mogę:
- dodać skrypty `scripts/build.sh` i `scripts/test.sh`,
- przygotować `CONTRIBUTING.md` z zasadami builda/PR,
- albo dodać krótką sekcję `How to contribute`.

Daj znać co preferujesz. Żeby sfinalizować — oznaczę zadania jako ukończone (README oraz porady i rozwiązywanie problemów).