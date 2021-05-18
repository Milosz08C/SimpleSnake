#include "Waz.h"
Plansza p;
Waz::Waz()// : predkoscX({ 3.f,0.f }), test()
{    
    glowa.setFillColor(sf::Color::Green);
    glowa.setSize(sf::Vector2f(20, 20));
    glowa.setPosition(p.win_width/2, p.win_heigth/2);
    glowa.setOutlineThickness(3);
    glowa.setOutlineColor(sf::Color::Black);
    oko.setFillColor(sf::Color::Black);
    oko.setRadius(3.f);
    oko.setPosition(glowa.getPosition() + sf::Vector2f(7,7));
}

void  Waz::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
    for (auto& c : cialo)
    {
        win.draw(c, state);
    }
    win.draw(glowa, state);
    win.draw(oko, state);
}

void Waz::dodaj()
{
    cialo.emplace_back();
    cialo[dlWeza].setFillColor(sf::Color::Green);
    cialo[dlWeza].setSize(sf::Vector2f(20, 20));
    cialo[dlWeza].setOutlineThickness(3);
    cialo[dlWeza].setOutlineColor(sf::Color::Black);
    cialo[dlWeza].setPosition(400, 400);
    po.emplace_back();
    if (dlWeza==0)
    {
        if (predkoscX == sf::Vector2f{ -3.f, 0.f } || predkoscX == sf::Vector2f{ -5.f,0.f })
        {
            cialo[dlWeza].setPosition(glowa.getPosition() + sf::Vector2f(30, 0));

            if (poziom() == 0)
            {
                po[dlWeza] = { -3.f,0.f };
            }
            else if (poziom() == 2)
            {
                po[dlWeza] = { -5.f,0.f };
            }

        }
       
        if (predkoscX == sf::Vector2f{ 3.f,0.f } || predkoscX == sf::Vector2f{ 5.f,0.f})
        {
            cialo[dlWeza].setPosition(glowa.getPosition() - sf::Vector2f(30, 0));

            if (poziom() == 0)
            {
                po[dlWeza] = { 3.f,0.f };
            }
            else if (poziom() == 2)
            {
                po[dlWeza] = { 5.f,0.f };
            }
        }

        if (predkoscX == sf::Vector2f{ 0.f,-3.f } ||predkoscX == sf::Vector2f{ 0.f,-5.f }) //gora
        {
            cialo[dlWeza].setPosition(glowa.getPosition() + sf::Vector2f(0, 30));
            if (poziom() == 0)
            {
                po[dlWeza] = { 0.f,-3.f };
            }
            else if (poziom() == 2)
            {
                po[dlWeza] = { 0.f,-5.f };
            }
        }

        if (predkoscX == sf::Vector2f{ 0.f,3.f } || predkoscX == sf::Vector2f{ 0.f,5.f }) //dol
        {
            cialo[dlWeza].setPosition(glowa.getPosition() - sf::Vector2f(0, 30));
            if (poziom() == 0)
            {
                po[dlWeza] = { 0.f,3.f };
            }
            else if (poziom() == 2)
            {
                po[dlWeza] = { 0.f,5.f };
            }
        }
    }
    
    else
    {
        if (po[dlWeza - 1] == sf::Vector2f{ -3.f,0.f } || po[dlWeza - 1] == sf::Vector2f{ -5.f,0.f}) //lewa
        {
            cialo[dlWeza].setPosition(cialo[dlWeza - 1].getPosition() + sf::Vector2f(30, 0));
            if (poziom() == 0)
            {
                po[dlWeza] = { -3.f,0.f };
            }
            else if (poziom() == 2)
            {
                po[dlWeza] = { -5.f,0.f };
            }
        }

         if (po[dlWeza - 1] == sf::Vector2f{3.f,0.f} || po[dlWeza - 1] == sf::Vector2f{ 5.f,0.f }) //prawa
        {
            cialo[dlWeza].setPosition(cialo[dlWeza - 1].getPosition() - sf::Vector2f(30, 0));
            if (poziom() == 0)
            {
                po[dlWeza] = { 3.f,0.f };
            }
            else if (poziom() == 2)
            {
                po[dlWeza] = { 5.f,0.f };
            }
        }

        if (po[dlWeza - 1] == sf::Vector2f{0.f,-3.f} || po[dlWeza - 1] == sf::Vector2f{ 0.f,-5.f }) //gora
        {
            cialo[dlWeza].setPosition(cialo[dlWeza - 1].getPosition() + sf::Vector2f(0, 30));
            if (poziom() == 0)
            {
                po[dlWeza] = { 0.f,-3.f };
            }
            else if (poziom() == 2)
            {
                po[dlWeza] = { 0.f,-5.f };
            }
        }

        if(po[dlWeza - 1] == sf::Vector2f{0.f,3.f} || po[dlWeza - 1] == sf::Vector2f{ 0.f,5.f })//dol
        {
            cialo[dlWeza].setPosition(cialo[dlWeza - 1].getPosition() - sf::Vector2f(0, 30));

            if (poziom() == 0)
            {
                po[dlWeza] = { 0.f,3.f };
            }
            else if (poziom() == 2)
            {
                po[dlWeza] = { 0.f,5.f };
            }
        }
    }
    dlWeza += 1;    
}

void Waz::move()
{
    predkoscPocz(predkoscX);
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))&&wBoki!=1)
    {
    
        wBoki = 1;
        wPionie = 0;
        if (cialo.size() > 0)
        {
            opoznienie.emplace_back();
            opoznienie[lewaZmienna] = glowa.getPosition();
            lewaZmienna += 1;
        }
        if (poziom() == 0)
        {
            predkoscX = { -3.f,0.f };
        }
        else if (poziom() == 2)
        {
            predkoscX = { -5.f,0.f };
        }
    }
    
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))&&wBoki!=1)
    {

        wBoki = 1;
        wPionie = 0;
        if (cialo.size() > 0)
        {    
            opoznieniePrawa.emplace_back();
            opoznieniePrawa[prawaZmienna] = glowa.getPosition();
            prawaZmienna += 1;        
        }

        if (poziom() == 0)
        {
            predkoscX = { 3.f,0.f };
        }
        else if (poziom() == 2)
        {
            predkoscX = { 5.f,0.f };
        }
    }
    
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))&&wPionie!=1)
    {
        
        wBoki = 0;
        wPionie = 1;
        if (cialo.size() > 0)
        {
         opoznienieGora.emplace_back();
          opoznienieGora[goraZmienna] = glowa.getPosition();
          goraZmienna += 1;  
        }
       
        if (poziom() == 0)
        {
            predkoscX = { 0.f,-3.f };
        }
        else if (poziom() == 2)
        {
            predkoscX = { 0.f,-5.f };
        }
    }
    
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))&&wPionie!=1 )
    {
       
        wBoki = 0;
        wPionie = 1;
        if (cialo.size() > 0)
        {
           opoznienieDol.emplace_back();
            opoznienieDol[dolZmienna] = glowa.getPosition();
            dolZmienna += 1;
        }

        if (poziom() == 0)
        {
            predkoscX = { 0.f,3.f };
        }
        else if (poziom() == 2)
        {
            predkoscX = { 0.f,5.f };
        }
    }

    glowa.move(predkoscX);
    oko.move(predkoscX);


    if (cialo.size() > 0)
    {
   
        dol();
        gora();
        prawa();
        lewa();
       
        for (int i = 0; i < cialo.size(); i++)
        {
            cialo[i].move(po[i]);
        }
    }
    //to tez nie dziala
    //to z opoznieniem nie dziala!! -dziala
    //popraw krawedzie!! -dziala
    //popraw by sie dalo skrecac w dwie strony!! -dziala
    //kombinacja gora/dol/lewa/prawa w obojetnie jakiej kolejnosci nie dziala -dziala
    ustaw();
}

bool Waz::lewaKra()
{
    sf::Vector2f c1(10,0);
    for (int i = 0; i < p.win_heigth; i++)
    {
        sf::Vector2f c(0, i);
            if (glowa.getPosition()-c1 == c)
            {
                lewaK = i;
                return true;
            }

    }

    return false;
}

bool Waz::prawaKra()
{
    sf::Vector2f c1(10, 0);
    for (int i = 0; i < p.win_heigth; i++)
    {
    sf::Vector2f c(p.win_width, i);
    if (glowa.getPosition() == c - c1 )
        {
            prawaK = i;
            return true;
        }
    }
    return false;    
}

bool Waz::gornaKra()
{
    sf::Vector2f c1(0, 20);
    for (int i = 0; i < p.win_width; i++)
    {
        sf::Vector2f c(i, 0);
            if ((glowa.getPosition() + c1) == c)
            {
                gornaK = i;
                return true;
            }
    }
    return false;
  
}

bool Waz::dolnaKra()
{
    sf::Vector2f c1(0, 10);
    for (int i = 0; i < p.win_width; i++)
    {
        sf::Vector2f c(i, p.win_heigth);

        if (glowa.getPosition()+c1 == c)
        {
            dolnaK = i;
            return true;
        }

    }
    return false;
  
}

bool Waz::lewaKraCialo()
{
    sf::Vector2f c1(10, 0);
    for (int j = 0; j < cialo.size(); j++)
    {
        for (int i = 0; i < p.win_heigth; i++)
        {
            sf::Vector2f c(0, i);
            if ((cialo[j].getPosition() - c1) == c)
            {
                lewaKC = i;
                LewaZkraw = j;
                return true;
            }
        }
    }
    return false;

}

bool Waz::prawaKraCialo()
{
    sf::Vector2f c1(10, 0);
    for (int j = 0; j < cialo.size(); j++)
    {
        for (int i = 0; i < p.win_heigth; i++)
        {
            sf::Vector2f c(p.win_width, i);
            if ((cialo[j].getPosition() + c1) == c)
            {
                prawaKC = i;
                PrawaZkraw = j;
                return true;
            }
        }
    }
    return false;

}

bool Waz::dolnaKraCialo()
{
    sf::Vector2f c1(0, 10);
    for (int j = 0; j < cialo.size(); j++)
    {
        for (int i = 0; i < p.win_width; i++)
        {
            sf::Vector2f c(i,p.win_heigth);
            if ((cialo[j].getPosition() + c1) == c)
            {
                dolnaKC = i;
                DolnaZkraw = j;
                return true;
            }
        }
    }
    return false;

}

bool Waz::goraKraCialo()
{
    sf::Vector2f c1(0, 20);
    for (int j = 0; j < cialo.size(); j++)
    {
        for (int i = 0; i < p.win_width; i++)
        {
            sf::Vector2f c(i, 0);
            if ((cialo[j].getPosition() + c1) == c)
            {
                gornaKC = i;
                GornaZkraw = j;
                return true;
            }
        }
    }
    return false;

}

void Waz::ustaw()
{

        if (lewaKraCialo() == true)
        {
            cialo[LewaZkraw].setPosition(p.win_width-10, lewaKC);
            zderzenieKra = 1;            
        }
        
        else if (prawaKraCialo() == true)
        {
            cialo[PrawaZkraw].setPosition(10, prawaKC);
            zderzenieKra = 1;
            
        }

        else if (dolnaKraCialo() == true)
        {
            cialo[DolnaZkraw].setPosition(dolnaKC, 10);
            zderzenieKra = 1;

        }

        else if (goraKraCialo() == true)
        {
            cialo[GornaZkraw].setPosition(gornaKC, p.win_heigth-10);
            zderzenieKra = 1;
        }

        else  if (lewaKra() == true)
        {
            glowa.setPosition(p.win_width - 10, lewaK);
            oko.setPosition(glowa.getPosition() + sf::Vector2f(7, 7));
            zderzenieKra = 1;
        }
        else if (prawaKra() == true)
        {
            glowa.setPosition(10, prawaK);
            oko.setPosition(glowa.getPosition() + sf::Vector2f(7, 7));
            zderzenieKra = 1;
        }

        else if (dolnaKra() == true)
        {
            glowa.setPosition(dolnaK, 10);
            oko.setPosition(glowa.getPosition() + sf::Vector2f(7, 7));
            zderzenieKra = 1;
        }

        else if (gornaKra() == true)
        {
            glowa.setPosition(gornaK,p.win_heigth-10);
            oko.setPosition(glowa.getPosition() + sf::Vector2f(7, 7));
            zderzenieKra = 1;
        }
        
}

void Waz::dol()
{      
    if (cialo.size() > 0)
    {
        for (int i = 0; i < cialo.size(); i++)
        {
            for (int z = 0; z < opoznienieDol.size(); z++)
            {
                for (int dl = 0; dl < 10; dl++)
                {
                    if (cialo[i].getPosition() == opoznienieDol[z] - sf::Vector2f(0, dl))
                    {                  
                        if (i==cialo.size()-1)
                        {
                            dolZmienna = 0;                           
                        }
                        if (poziom() == 0)
                        {
                            po[i] = { 0.f,3.f };
                        }
                        else if (poziom() == 2)
                        {
                            po[i] = { 0.f,5.f };
                        }
                           
                    }

                }
            }
        }
    }
}

void Waz::gora()
{
   
    if (cialo.size() > 0)
    {
        for (int i = 0; i < cialo.size(); i++)
        {
            for (int z = 0; z < opoznienieGora.size(); z++)
            {
                for (int dl = 0; dl < 10; dl++)
                {
                    if (cialo[i].getPosition() == opoznienieGora[z] + sf::Vector2f(0, dl))
                    {
                        if (i==cialo.size()-1)
                        {
                            goraZmienna = 0;
                        }
                        if (poziom() == 0)
                        {
                            po[i] = { 0.f,-3.f };
                        }
                        else if (poziom() == 2)
                        {
                            po[i] = { 0.f,-5.f };
                        }
                        
                    }
                }
            }
        }
    }
}

void Waz::lewa()
{
  
    if (cialo.size() > 0)
    {
        for (int i = 0; i < cialo.size(); i++)
        {
           for (int z = 0; z < opoznienie.size(); z++)
            {
                for (int dl = 0; dl < 10; dl++)
                {
                    if (cialo[i].getPosition() == opoznienie[z] + sf::Vector2f(dl, 0))
                    {
                        if (i==cialo.size()-1)
                        {
                            lewaZmienna = 0;
                            
                        }
                        if (poziom() == 0)
                        {
                            po[i] = { -3.f,0.f };
                        }
                        else if (poziom() == 2)
                        {
                            po[i] = { -5.f,0.f };
                        }

                    }
                }
            }
        }
    }
}

void Waz::prawa()
{
    
    if (cialo.size() > 0)
    {
        for (int i = 0; i < cialo.size(); i++)
        {
           for (int z = 0; z < opoznieniePrawa.size(); z++)
            {
                for (int dl = 0; dl < 10; dl++)
                {
                    if (cialo[i].getPosition() == opoznieniePrawa[z] - sf::Vector2f(dl, 0))
                    {
                        if (i==cialo.size()-1 )
                        {
                           prawaZmienna = 0;
                           
                        }
                        if (poziom() == 0)
                        {
                            po[i] = { 3.f,0.f };
                        }
                        else if (poziom() == 2)
                        {
                            po[i] = { 5.f,0.f };
                        }
                        
                    }
                }
          }
        }
    }
}

bool Waz::zderzenie()
{
    if (cialo.size() > 0)
    {
        for (int dl = 0; dl < cialo.size(); dl++)
        {
            for (int i = 0; i < 14; i++)
            {
                for (int j = 0; j < 14; j++)
                {
                    if (glowa.getPosition() + sf::Vector2f(i, j) == cialo[dl].getPosition())
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;  
}

void Waz::clear()
{
    po.clear();
    cialo.clear();
    glowa.setPosition(p.win_width / 2, p.win_heigth / 2);
    oko.setPosition(glowa.getPosition() + sf::Vector2f(7, 7));
    lewaK = 0, prawaK = 0, dolnaK = 0, gornaK = 0;
    dlWeza = 0;
    opoznienie.clear(); opoznienieDol.clear(); opoznienieGora.clear(); opoznieniePrawa.clear();
    lewaZmienna = 0, prawaZmienna = 0, goraZmienna = 0, dolZmienna = 0;
    wBoki = 0, wPionie = 0;
    zderzenieKra = 0;
    poziomTrudnosci = ez;
    zmiennaPocz = 0;
}

int Waz::poziom()
{
     if (poziomTrudnosci == hard)
     {
        return 2;
     }
    else return 0;
}

sf::Vector2f Waz::glowaGetPosition()
{
    return glowa.getPosition();
}

bool Waz::zderzenieKrawedz()
{
    if (zderzenieKra==1)
    {
        return true;
    }
    return false; 
}

sf::Vector2f Waz::predkoscPocz(sf::Vector2f &vec)
{
    if (zmiennaPocz == 0)
    {
        if (poziom() == 2)
        {
            zmiennaPocz += 1;
            return vec = { 5.f,0.f };
        }
        else
        {
            zmiennaPocz += 1;
            return vec = { 3.f,0.f };
        }
    }

}


/*void Waz::korekta()
{
    if (cialo.size() > 0)
    {
        if (predkoscX == sf::Vector2f{ 0.f,3.f })
        {
            for (int i = 30; i < 100; i++)
            {
                for (int z = 6; z < 80; z++)
                {
                    if (cialo[0].getPosition() == glowa.getPosition() - sf::Vector2f(i, z))
                    {
                        po[0] = { 0.f,3.f };
                        cialo[0].setPosition(glowa.getPosition() - sf::Vector2f(0, 33));
                    }
                }
            }
        }
        else if (predkoscX == sf::Vector2f{ 0.f,-3.f })
        {
            for (int i = 30; i < 100; i++)
            {
                for (int z = 6; z < 80; z++)
                {
                    if (cialo[0].getPosition() == glowa.getPosition() + sf::Vector2f(i, z))
                    {
                        po[0] = { 0.f,-3.f };
                        cialo[0].setPosition(glowa.getPosition() + sf::Vector2f(0, 33));
                    }
                }
            }
        }
        else if (predkoscX == sf::Vector2f{ 3.f,0.f })
        {
            for (int i = 30; i < 100; i++)
            {
                for (int z = 6; z < 80; z++)
                {
                    if (cialo[0].getPosition() == glowa.getPosition() - sf::Vector2f(z, i))
                    {
                        po[0] = { 3.f,0.f };
                        cialo[0].setPosition(glowa.getPosition() - sf::Vector2f(33, 0));
                    }
                }
            }
        }
        else if (predkoscX == sf::Vector2f{ -3.f,0.f })
        {
            for (int i = 30; i < 100; i++)
            {
                for (int z = 6; z < 80; z++)
                {
                    if (cialo[0].getPosition() == glowa.getPosition() + sf::Vector2f(z, i))
                    {
                        po[0] = { -3.f,0.f };
                        cialo[0].setPosition(glowa.getPosition() - sf::Vector2f(0, 33));
                    }
                }
            }
        }
    }
}

void::Waz::korekta2()
{
    if (cialo.size() > 1 && po.size() > 1)
    {
        for (int d = 1; d < cialo.size(); d++)
        {
            if (po[d - 1] == sf::Vector2f{ 0.f,3.f })//dol
            {
                for (int i = 30; i < 100; i++)
                {
                    for (int z = 6; z < 100; z++)
                    {
                        if (cialo[d].getPosition() == cialo[d - 1].getPosition() - sf::Vector2f(i, z))
                        {
                            po[d] = { 0.f,3.f };
                            cialo[d].setPosition(glowa.getPosition() - sf::Vector2f(0, 33));
                        }
                    }
                }
            }
            else if (po[d - 1] == sf::Vector2f{ 0.f,-3.f })//gora
            {
                for (int i = 30; i < 100; i++)
                {
                    for (int z = 6; z < 100; z++)
                    {
                        if (cialo[d].getPosition() == cialo[d - 1].getPosition() + sf::Vector2f(i, z))
                        {
                            po[d] = { 0.f,-3.f };
                            cialo[d].setPosition(cialo[d-1].getPosition() + sf::Vector2f(0, 33));
                        }
                    }
                }
            }
            else if (po[d - 1] == sf::Vector2f{ 3.f,0.f })//prawa
            {
                for (int i = 30; i < 100; i++)
                {
                    for (int z = 6; z < 100; z++)
                    {
                        if (cialo[d].getPosition() == cialo[d - 1].getPosition() - sf::Vector2f(z, i))
                        {
                            po[d] = { 3.f,0.f };
                            cialo[d].setPosition(cialo[d-1].getPosition() - sf::Vector2f(33, 0));
                        }
                    }
                }
            }
            else if (po[d - 1] == sf::Vector2f{ -3.f,0.f })//lewa
            {
                for (int i = 30; i < 100; i++)
                {
                    for (int z = 6; z < 100; z++)
                    {
                        if (cialo[d].getPosition() == cialo[d - 1].getPosition() + sf::Vector2f(z, i))
                        {
                            po[d] = { -3.f,0.f };
                            cialo[d].setPosition(cialo[d-1].getPosition() - sf::Vector2f(33, 0));
                        }
                    }
                }
            }
        }
    }

}*/