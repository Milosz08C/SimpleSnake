#pragma once
#include<SFML/Graphics.hpp>
#include"Plansza.h"

enum trudnosc{ez,medium,hard};
class Waz : public sf::Drawable
{
	
	sf::Vector2f predkoscX;

	
	int lewaK=0,prawaK=0,dolnaK=0,gornaK=0; //krawedzie dla glowy
	int lewaKC = 0, prawaKC = 0, dolnaKC = 0, gornaKC = 0; //krawedzie dla ciala
	int LewaZkraw = 0, PrawaZkraw = 0, DolnaZkraw = 0, GornaZkraw = 0; //sprawdza ktore cialo przeszlo przez krawedz
	int dlWeza = 0; //dlugosc weza
	int lewaZmienna = 0, prawaZmienna = 0, goraZmienna = 0, dolZmienna = 0; //do poruszania cialem
	int wBoki = 0, wPionie = 0; // blokuje podczas ruchu w lewo ruch w prawo itd. 
	int zderzenieKra = 0; //zmienna przechowujaca 0 lub 1 jesli w trybie normal/hard nastapilo zderzenie z krawedzia
	bool lewaKraCialo(); //sprawdza czy cialo przekroczylo lewa krawedz
	bool prawaKraCialo(); //sprawdza czy cialo przekroczylo prawa krawedz
	bool goraKraCialo(); //sprawdza czy cialo przekroczylo gorna krawedz
	bool dolnaKraCialo(); //sprawdza czy cialo przekroczylo dolna krawedz
	bool lewaKra();// sprawdza czy glowa przekorczyla lewa krawedz
	bool prawaKra(); //sprawdza cz glowa przekroczyla prawa krawedz
	bool dolnaKra(); //sprawdza czy glowa przekroczyla dolna krawedz 
	bool gornaKra(); //sprawdza czy glowa przekroczyla gorna krawedz
	void dol(); //ruch w dol ciala
	void gora(); //ruch w gore ciala 
	void lewa(); //ruch w lewa ciala
	void prawa(); //ruch w prawa ciala
	void ustaw(); //ustawia po zderzeniu z krawedzia
	int poziom(); //zwraca wybrany poziom w formie inta
	std::vector<sf::Vector2f> po; //vector ruchu ciala
	sf::Vector2f predkoscPocz(sf::Vector2f&);
	int zmiennaPocz = 0;
	std::vector<sf::Vector2f> opoznienie; std::vector<sf::Vector2f> opoznienieDol; std::vector<sf::Vector2f> opoznienieGora; std::vector<sf::Vector2f> opoznieniePrawa; //przechowuje pozycje glowy w ktorej nastapilo nacisnieniecie klawisza ruchu
	void draw(sf::RenderTarget& win, sf::RenderStates state) const override;
	std::vector<sf::RectangleShape> cialo;
	sf::RectangleShape glowa;
	sf::CircleShape oko;
public:
	bool zderzenieKrawedz(); //sprawdza czy glowa zderzyla sie z krawedzia w trybie normal/hard
	trudnosc poziomTrudnosci; 
	void dodaj(); //dodaje segment ciala 
 	void clear(); //czysci zmienne
	void move(); //odpowiada za ruch weza
	sf::Vector2f glowaGetPosition(); 
	bool zderzenie(); //sprawdza czy nastapilo zderzenie z cialem 
	Waz();
};

//dodawanie cos psuje
