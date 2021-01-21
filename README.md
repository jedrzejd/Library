# Biblioteka

- [Info](#Info)

- [Struktura projektu](#Struktura-projektu)

- [Technologia](#Technologies)

---

## Info

Program umożliwia zarządzanie biblioteką. 

Książki w bazie powinny być posortowane alfabetycznie wg.autora. 

Baza danych powinna zawierać następujące informacje o książce: nr katalogowy, autor; tytuł; kategorię, datę wydania; wydawnictwo, nr ISBN, dostępność.

Bibloteka umożliwia przechowywanie danych klientów: imię i nazwisko, adres, telefon.

Program umożliwia:

- dodawanie, edycję, kasowanie, wypisywanie wszystkich pozycji, wyszukiwanie pozycji (po autorze, tytule i kategorii)

- wypożyczenie i zwrot książki

- zapisanie do pliku tekstowego danych o książkach

---

## Struktura projektu

Po uruchomieniu programu wyswitlane są informacje i instrukcje w jaki sposób korzystać z Bibloteki

- main.c
    - główny moduł zawierający interakcje z użytkownikiem i komunikacje z biblotekami

- book.h 
    - biloteka umożliwia dodawanie, edytowanine, usowanie, wypisywanie, przeszukiwanie książek z pliku teksowego 
    - dodatkową zaimplentowane są komperatory
- customer.h
    - bibloteka umożliwia wypożyczanie i zwracanie książek:
    - bibloteka zawiera implementacje listy na potrzeby projektu z następującymi możliwościami:
      - Dodanie elementu do listy
      - Usowanie pierwszego elemntu listy
      - Usowanie ostatniego elemtu listy
      - Pobranie wartości ostatniego elemtu listy
      - Usunieci dowolnego elentu z listy
    - zawiera funkcje pomocnicze do porównywania elemntów typów danych

- data.h
    - bibloteka zawierająca funkcje umożliwiące interakcje z plikami teksowymi 

- books.txt
    - baza danych programu, plik przechowuje dane w następującym schemacie:
         - dane są odzielone od siebie znakiem końca linii, w jednej linii między informacjami jest spacja
  
         - numer w bazie, autor, tytuł, kategoria, data wydania,  wydawnictwo, nr ISBN, dostępność
---

## Technologia

- C
