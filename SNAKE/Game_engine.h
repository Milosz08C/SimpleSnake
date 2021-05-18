#pragma once

#include <fstream>
#include "Waz.h"
#include"Znicz.h"
#include"Plansza.h"
#include "Apple.h"


class Game_engine
{
	Waz* pyton; 
	Apple* jabol;
	Znicz* zloty;
	
	std::vector<sf::Text> text; //menu
	std::vector<sf::Text> text2; //wybor poziomu
	std::vector<sf::Text> textKoniec; //napisy koncowe
	std::vector<sf::Text> textInfo; // informacje o trybie Hard
	std::vector<sf::Text> Topka; //Top 10 wynikow
	std::vector<sf::Text> miejsce; //Numer wyniku
	sf::Text powrot; //powrot z highscore
	sf::Text pkt; //wyswietla punkty podczas gry
	bool kolizja(); //sprawdza kolizje z jablkiem
	bool kolizjaZnicz(); //sprawdza kolizje ze zniczem w trybie Hard
	void sprawdzaj(); //jesli kolizja==true dodaje pkt, segment weza i spawni nowe jablko
	void sprawdzajZnicz(); // jesli kolizjaZnicz ==true dodaje punkty i spawni nowy znicz
	void krawedzie(sf::RenderTarget&); //rysuje krawedzie w trybie normal i hard
	int wybor = 0; //zmienia ekran
	//std::vector<int> wynikDoSort; //zmienna uzywana do sortowania wynikow
	int wynik=0; // zmienna do zapisywania wyniku podczas gry
	int textZmienna = 0; //zmienna do zamkniecia pliku w odpowiednim momencie
	std::vector<std::string> wyniki; //zmienna do zapisania wyniku z pliku
	void punkty(sf::RenderTarget & ); //rysuje punkty
	void wyborPoziomu(sf::RenderTarget &); //wyswietla dostepne poziomy trudnosci
	void ekranKoncowy(sf::RenderTarget &); //wyswietla ekran po przegranej
	void reset(); //resetuje wszystkie zmienne wykorzystywane podczas gry
	bool czy_koniec(); //sprawdza czy nastapila przegrana 
	void info(sf::RenderTarget&); //wyswietla informacje o trybie Hard
	void zapis(int&); //zapisuje wyniki do Pliku 
	void wyswietlWynik(sf::RenderTarget&); //wyswietla Wyniki w highscore
	std::vector<int> sortowanie(std::vector<int>&,int );// u¿ycie sortowania B¹belkowego do wyznaczenia TOP 10 wynikow
	std::vector<std::string> PrzedWysw(std::vector<std::string>&);
public:
	Game_engine(Waz& , Apple&, Znicz&);
	void display();
};

