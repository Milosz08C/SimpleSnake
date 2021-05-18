#include "Game_engine.h"
Plansza plan;

Game_engine::Game_engine(Waz& w, Apple& a,Znicz&z) : pyton(&w), jabol(&a), zloty(&z)
{
}

void Game_engine::display()
{
    sf::RenderWindow win(sf::VideoMode(plan.win_width, plan.win_heigth), "WEZYK");
    sf::Font font;

    font.loadFromFile("BebasNeue-Bold.ttf");
    pkt.setFont(font);
    for (int i = 0; i < 3; i++)
    {
        text2.emplace_back();
    }
   

    text2[0].setFont(font);
    text2[0].setString("SNAKE");
    text2[0].setCharacterSize(100);
    text2[0].setFillColor(sf::Color::Green);
    text2[0].setStyle(sf::Text::Bold);
    text2[0].setPosition(plan.text_pozX, plan.tex_pozY);

    text2[1].setFont(font);
    text2[1].setString("START");
    text2[1].setCharacterSize(50);
    text2[1].setFillColor(sf::Color(255, 173, 51));
    text2[1].setStyle(sf::Text::Bold);
    text2[1].setPosition(plan.text_pozX + 40, plan.tex_pozY + 100);

    text2[2].setFont(font);
    text2[2].setString("HIGHSCORE");
    text2[2].setCharacterSize(50);
    text2[2].setFillColor(sf::Color(255, 173, 51));
    text2[2].setStyle(sf::Text::Bold);
    text2[2].setPosition(plan.text_pozX + 10, plan.tex_pozY + 150);

    win.setFramerateLimit(120);

    while (win.isOpen())
    {
            sf::Event event;
            win.clear(sf::Color(0, 102, 150));
            for (auto& o : text2)
            {
                win.draw(o);
            }
            while (win.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    win.close();
            }
          for (int i = 0; i < 120; i++)
            {
                for (int j = 12; j < 100; j++)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(text2[1].getPosition() + sf::Vector2f(i, j)))
                    {
                        wybor = 1;
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(text2[2].getPosition() + sf::Vector2f(i, j)))
                    {
                        wybor = 7;
                    }
                }
            }
         
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                win.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                zapis(wynik);
                reset();
                wybor = 0;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                wybor = 2;
            }

            if (wybor == 1)
            {
                win.clear(sf::Color(0, 102, 150));
                wyborPoziomu(win);

                for (int i = 0; i < 100; i++)
                {
                    for (int j = 12; j < 80; j++)
                    {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(text[0].getPosition() + sf::Vector2f(i, j)))
                        {            
                           pyton->poziomTrudnosci = ez;
                           wybor = 2;
                        }
                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(text[1].getPosition() + sf::Vector2f(i, j)))
                        {
                            pyton->poziomTrudnosci = medium;
                            wybor = 3;
                        }
                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(text[2].getPosition() + sf::Vector2f(i, j)))
                        {
                            wybor = 6;
                        }
                      
                    }
                }

            }

            if (wybor == 2) //ez
            {
                win.clear(sf::Color(77, 77, 51));
                win.draw(*pyton);
                win.draw(*jabol);
                pyton->move();
                punkty(win);
                sprawdzaj();
                if (czy_koniec() == true)
                {
                    wybor = 5;
                }
            }
            else if (wybor == 3) //medium
            {
                win.clear(sf::Color(77, 77, 51));
                win.draw(*pyton);
                win.draw(*jabol);
                pyton->move();
                punkty(win);
                sprawdzaj();
                krawedzie(win);
                if (czy_koniec() == true)
                {
                    wybor = 5;
                }
                
            }
            else if (wybor == 4) //hard
            {
                win.clear(sf::Color(77, 77, 51));
                win.draw(*pyton);
                win.draw(*jabol);
                win.draw(*zloty);
                pyton->move();
                zloty->move();
                sprawdzaj();
                sprawdzajZnicz();
                punkty(win);
                krawedzie(win); 
                if (czy_koniec() == true)
                {
                    wybor = 5;
                }
            }
            else if (wybor == 5)
            {
                if (textZmienna == 0)
                {
                  zapis(wynik);
                }
                win.clear(sf::Color(0, 102, 150));
                ekranKoncowy(win);
                for (int i = 0; i < 160; i++)
                {
                    for (int j = 12; j < 100; j++)
                    {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(textKoniec[1].getPosition() + sf::Vector2f(i, j)))
                        {
                            reset();
                            wybor = 0;
                        }
                    }
                }

            }

            else if (wybor == 6)
            {
                win.clear(sf::Color(0, 102, 150));
                info(win);
                for (int i = 0; i < 100; i++)
                {
                    for (int j = 12; j < 80; j++)
                    {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(textInfo[2].getPosition() + sf::Vector2f(i, j)))
                        {
                            pyton->poziomTrudnosci = hard;
                            wybor = 4;
                        }
                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(textInfo[1].getPosition() + sf::Vector2f(i, j)))
                        {
                            reset();
                            wybor = 0;
                        }
                    }
                }
            }
            
            else if (wybor == 7)
            {
                win.clear(sf::Color(0, 102, 150));
                wyswietlWynik(win);
                for (int i = 0; i < 100; i++)
                {
                    for (int j = 12; j < 80; j++)
                    {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(win) == sf::Vector2i(powrot.getPosition() + sf::Vector2f(i, j)))
                        {
                            wybor = 0;
                        }
                    }
                }
            }

            win.display();    
     }

 }

bool Game_engine::kolizja()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int z = 0; z <16; z++)
            {
                for (int m = 0; m < 16; m++)
                {
                    if (pyton->glowaGetPosition() + sf::Vector2f(z, m) == jabol->jablkoGetPosition() + sf::Vector2f(i, j))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Game_engine::punkty(sf::RenderTarget & win)
{
    sf::Font font;
    
    font.loadFromFile("BebasNeue-Bold.ttf");
    pkt.setFont(font);
    pkt.setString(std::to_string(wynik));
    pkt.setCharacterSize(30);
    pkt.setFillColor(sf::Color::Blue);
    pkt.setStyle(sf::Text::Bold);
    pkt.setPosition(20, 0);
    win.draw(pkt);
}

void Game_engine::wyborPoziomu(sf::RenderTarget &win)
{
    sf::Font font;

    font.loadFromFile("BebasNeue-Bold.ttf");
    pkt.setFont(font);
    for (int i = 0; i < 3; i++)
    {
        text.emplace_back();
    }
    text[0].setFont(font);
    text[0].setString("EASY");
    text[0].setCharacterSize(80);
    text[0].setFillColor(sf::Color(255, 173, 51));
    text[0].setStyle(sf::Text::Bold);
    text[0].setPosition(plan.text_pozX - 60, plan.tex_pozY + 200);

    text[1].setFont(font);
    text[1].setString("MEDIUM");
    text[1].setCharacterSize(80);
    text[1].setFillColor(sf::Color(255, 173, 51));
    text[1].setStyle(sf::Text::Bold);
    text[1].setPosition(plan.text_pozX - 60, plan.tex_pozY + 280);

    text[2].setFont(font);
    text[2].setString("HARD (zloty znicz)");
    text[2].setCharacterSize(80);
    text[2].setFillColor(sf::Color(255, 173, 51));
    text[2].setStyle(sf::Text::Bold);
    text[2].setPosition(plan.text_pozX - 60, plan.tex_pozY + 360);

    for (auto& o : text)
    {
        win.draw(o);
    }
}

bool Game_engine::kolizjaZnicz()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int z = 0; z < 20; z++)
            {
                for (int m = 0; m < 20; m++)
                {
                    if (pyton->glowaGetPosition() + sf::Vector2f(z, m) == zloty->kulkaGetPosition() + sf::Vector2f(i, j))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Game_engine::sprawdzaj()
{
    if (kolizja() == true)
    {
        wynik += 10;
        jabol->appleSpawn();
        pyton->dodaj();
    }
}

void Game_engine::sprawdzajZnicz()
{

    if (kolizjaZnicz() == true)
    {
    wynik += 300;
    zloty->kulkaSpawn();
    }
}

void Game_engine::krawedzie(sf::RenderTarget&win)
{
    sf::VertexArray linia(sf::LinesStrip);
    linia.append(sf::Vector2f{ 3,3 });
    linia.append(sf::Vector2f{ 3,797 });
    linia.append(sf::Vector2f{ 797,797 });
    linia.append(sf::Vector2f{ 797,3 });
    linia.append(sf::Vector2f{ 3,3 });
    win.draw(linia);
}

void Game_engine::ekranKoncowy(sf::RenderTarget& win)
{
    sf::Font font;

    font.loadFromFile("BebasNeue-Bold.ttf");
    pkt.setFont(font);
    for (int i = 0; i < 3; i++)
    {
        textKoniec.emplace_back();
    }
    textKoniec[0].setFont(font);
    textKoniec[0].setString("PRZEGRANA");
    textKoniec[0].setCharacterSize(150);
    textKoniec[0].setFillColor(sf::Color(255, 173, 51));
    textKoniec[0].setStyle(sf::Text::Bold);
    textKoniec[0].setPosition(plan.text_pozX - 160, plan.tex_pozY + 80);

    textKoniec[1].setFont(font);
    textKoniec[1].setString("POWROT");
    textKoniec[1].setCharacterSize(80);
    textKoniec[1].setFillColor(sf::Color::Black);
    textKoniec[1].setStyle(sf::Text::Bold);
    textKoniec[1].setPosition(plan.text_pozX - 30, plan.tex_pozY + 380);

    textKoniec[2].setFont(font);
    textKoniec[2].setString("PUNKTY:");
    textKoniec[2].setCharacterSize(80);
    textKoniec[2].setFillColor(sf::Color(255, 173, 30));
    textKoniec[2].setStyle(sf::Text::Bold);
    textKoniec[2].setPosition(plan.text_pozX-160, plan.tex_pozY + 270);


    pkt.setCharacterSize(80);
    pkt.setPosition(plan.text_pozX+70, plan.tex_pozY + 270);
    win.draw(pkt);
    for (auto& t : textKoniec)
    {
        win.draw(t);
    }
}

void Game_engine::reset()
{
    pyton->clear();
    jabol->jablkoClear();
    jabol->appleSpawn();
    zloty->kulkaSpawn();
    wynik = 0;
    textZmienna = 0;
}

bool Game_engine::czy_koniec()
{
    if (pyton->zderzenie() == true)
    {
        return true;
    }
    else if ((wybor == 3 || wybor == 4) && pyton->zderzenieKrawedz() == true)
    {
        return true;
    }
    return false;
}

void Game_engine::info(sf::RenderTarget &win)
{
    sf::Font font;
    font.loadFromFile("BebasNeue-Bold.ttf");

    for (int i = 0; i < 3; i++)
    {
        textInfo.emplace_back();
    }
   
    textInfo[0].setFont(font);
    textInfo[0].setString("Jesli zlapiesz zloty znicz, zyskujesz 300pkt");
    textInfo[0].setCharacterSize(40);
    textInfo[0].setFillColor(sf::Color(255, 173, 51));
    textInfo[0].setStyle(sf::Text::Bold);
    textInfo[0].setPosition(plan.text_pozX - 250, plan.tex_pozY + 80);

    
    textInfo[1].setFont(font);
    textInfo[1].setString("POWROT");
    textInfo[1].setCharacterSize(80);
    textInfo[1].setFillColor(sf::Color(255, 173, 51));
    textInfo[1].setStyle(sf::Text::Bold);
    textInfo[1].setPosition(plan.text_pozX +90, plan.tex_pozY + 200);

    textInfo[2].setFont(font);
    textInfo[2].setString("GRAJ");
    textInfo[2].setCharacterSize(80);
    textInfo[2].setFillColor(sf::Color(255, 173, 51));
    textInfo[2].setStyle(sf::Text::Bold);
    textInfo[2].setPosition(plan.text_pozX - 200, plan.tex_pozY + 200);

    for (auto& t : textInfo)
    {
        win.draw(t);
    }

}

void Game_engine::zapis(int &wynik)
{
    std::ofstream wyniki("wyniki.txt", std::ios::app);
    textZmienna += 1;
    wyniki << wynik << std::endl;  
    wyniki.close();
}

void Game_engine::wyswietlWynik(sf::RenderTarget &win)
{   
    PrzedWysw(wyniki);
    
    sf::Font font;
    font.loadFromFile("BebasNeue-Bold.ttf");
    int odleglosc=0;
    int numer = 1;
    for (int i = 0; i < wyniki.size(); i++)
    {
        Topka.emplace_back();
        miejsce.emplace_back();
        Topka[i].setFont(font);
        miejsce[i].setFont(font);
        Topka[i].setString(wyniki[i]);
        miejsce[i].setString(std::to_string(numer));
        Topka[i].setCharacterSize(50);
        miejsce[i].setCharacterSize(50);
        Topka[i].setFillColor(sf::Color::Blue);
        miejsce[i].setFillColor(sf::Color::Black);
        Topka[i].setStyle(sf::Text::Bold);
        miejsce[i].setStyle(sf::Text::Bold);
        Topka[i].setPosition(400, 40+odleglosc);
        miejsce[i].setPosition(Topka[i].getPosition()-sf::Vector2f(50,0));
        odleglosc+= 60;
        numer += 1;
    }

    powrot.setFont(font);
    powrot.setString("BACK");
    powrot.setCharacterSize(80);
    powrot.setFillColor(sf::Color::Black);
    powrot.setStyle(sf::Text::Bold);
    powrot.setPosition(340, 650);
    
    win.draw(powrot);
    for (int i=0; i< miejsce.size(); i++)
    {
        win.draw(miejsce[i]);
        win.draw(Topka[i]);
    }
   
}

std::vector<int> Game_engine::sortowanie(std::vector<int>& vec, int ilosc)
{
    for (int i = 0; i < ilosc; i++)
    {
        for (int j = 1; j < ilosc - i; j++)
        {
            if (vec[j - 1] < vec[j])
            {
                std::swap(vec[j - 1], vec[j]);
            }
            if (vec[j - 1] == vec[j])
            {
                vec[j - 1] = 0;
            }
        }
    }

    return vec;
}

std::vector<std::string> Game_engine::PrzedWysw(std::vector<std::string>&wyniki)
{
    std::vector<int> wynikDoSort;
    std::fstream dokument;
    dokument.open("wyniki.txt");

    do
    {
        wyniki.emplace_back();
        std::getline(dokument, wyniki[wyniki.size() - 1]);
    } while (wyniki[wyniki.size() - 1] != "");
    dokument.close();
    if (wyniki[wyniki.size() - 1] == "")
    {
        wyniki.resize(wyniki.size() - 1);
    }
    for (auto& w : wyniki)
    {
        wynikDoSort.push_back(std::stoi(w));
        //wynikDoSort[wynikDoSort.size() - 1] = std::stoi(w);
    }

    for (int i = 0; i < wyniki.size(); i++)
    {
        sortowanie(wynikDoSort, wyniki.size());
    }


    for (int i = 0; i < wyniki.size(); i++)
    {
        wyniki[i] = std::to_string(wynikDoSort[i]);
    }
    if (wyniki.size() > 10)
    {
        wyniki.resize(10);
    }

    return wyniki;
}