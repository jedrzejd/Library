# Biblioteka

- [Info](#Info)

- [Struktura projektu](#Struktura-projektu)

- [Technologie](#Technologies)

---

## General Info

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

- main.c
    - główny program zawierający interakcje z użytkownikiem i komunikacje z biblotekami

- book.h 
    - biloteka umożliwia dodawanie, edytowaine, usowanie, wypisywanie, przeszukiwanie książek z pliku teksowego 

- customer.h
    - bibloteka umożliwia wypożyczanie i zwracanie książek
    - bibloteka zawiera implementacje listy na potrzeby programu

- data.h
    - bibloteka umożliwia interakcje z plikami teksowymi 

- books.txt
    - baza danych programu
---

## Technologies

- C