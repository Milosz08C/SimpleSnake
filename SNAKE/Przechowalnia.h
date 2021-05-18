#pragma once
/*
    if (cialo.size() > 2) //lewa
    {
        if (cialo[cialo.size() - 2].getPosition() == cialo[cialo.size() - 3].getPosition() + sf::Vector2f(30, 0));
        {
            cialo[dlWeza].setPosition(cialo[dlWeza - 1].getPosition() + sf::Vector2f(30, 0));
            pomocniczy = { -3.f,0.f };
        }
        
    }

        if (cialo.size() > 2) //prawa
    {
        if (cialo[cialo.size() - 2].getPosition() == cialo[cialo.size() - 3].getPosition() - sf::Vector2f(30, 0));
        {
            cialo[dlWeza].setPosition(cialo[dlWeza - 1].getPosition() - sf::Vector2f(30, 0));
              pomocniczy = { 3.f,0.f };
        }
      
    }

        if (cialo.size() > 2) //gora
    {
        if (cialo[cialo.size() - 2].getPosition() == cialo[cialo.size() - 3].getPosition() + sf::Vector2f(0, 30));
        {
            cialo[dlWeza].setPosition(cialo[dlWeza - 1].getPosition() + sf::Vector2f(0, 30));
             pomocniczy = { 0.f,-3.f };
        }

    }

        if (cialo.size() > 2)//dol
    {
        if (cialo[cialo.size() - 2].getPosition() == cialo[cialo.size() - 3].getPosition() - sf::Vector2f(0, 30));
        {
            cialo[dlWeza].setPosition(cialo[dlWeza - 1].getPosition() - sf::Vector2f(0, 30));
                    pomocniczy = { 0.f,3.f };
        }

    }



*/

//dodawanie
/*
/*cialo[dlWeza - 1].getPosition() == cialo[dlWeza- 2].getPosition() + sf::Vector2f(30, 0) lewa
  cialo[dlWeza-1].getPosition() == cialo[dlWeza-2].getPosition() - sf::Vector2f(30, 0) prawa
  cialo[dlWeza-1].getPosition() == cialo[dlWeza-2].getPosition() + sf::Vector2f(0, 30) gora
  cialo[dlWeza-1].getPosition() == cialo[dlWeza-2].getPosition() - sf::Vector2f(0, 30) dol


          /*if (gora() == true /*&& x == 3)
        {
            po[ruchgora] = { 0.f,-3.f };
            if (dlWeza - 1 > ruchgora)
            {
                ruchgora += 1;
            }
            else if (dlWeza - 1 == ruchgora)
            {
                ruchgora = 0;
            }
        }*/

        /*if (lewa() == true /*&& x == 1)
        {
            //ruchprawa = 0;
            po[ruchlewa] = { -3.f,0.f };
            if (dlWeza - 1 > ruchlewa)
            {
                ruchlewa += 1;
            }
            else if (dlWeza - 1 == ruchlewa)
            {
                ruchlewa = 0;
            }
        }

        if (prawa() == true /*&& x == 2)
        {
          //  ruchlewa = 0;
            po[ruchprawa] = { 3.f,0.f };
            if (dlWeza - 1 > ruchprawa)
            {
                ruchprawa += 1;
            }
            else if (dlWeza - 1 == ruchprawa)
            {
                ruchprawa = 0;
            }
        }*/


        /*for (int i = 0; i < cialo.size(); i++)
            {
            /*if (po[i] == sf::Vector2f{ -3.f,0.f })
            {
                po[i] = sf::Vector2f{ -(3,5.f),0.f };
            }

            else if (po[i] == sf::Vector2f{ 3.f,0.f })
            {
                po[i] = sf::Vector2f{ (3,5.f),0.f };
            }

            else if (po[i] == sf::Vector2f{ 0.f,3.f })
            {
                po[i] = sf::Vector2f{ 0.f,(3,5.f) };
            }

            else if (po[i] == sf::Vector2f{ 0.f,-3.f })
            {
                po[i] = sf::Vector2f{ 0.f,-(3,5.f) };
            }
            }
        }























/*if (dol() == true && x == 4)
{
    pomocniczy = { 0.f,3.f };
    cialo[0].move(pomocniczy);
}
else if (gora() == true && x == 3)
{
    pomocniczy = { 0.f,-3.f };
    for (int z = 0; z < cialo.size(); z++)
    {
        cialo[z].move(pomocniczy);
    }
}
else if (lewa() == true && x == 1)
{
    pomocniczy = { -3.f,0.f };
    for (int z = 0; z < cialo.size(); z++)
    {
        cialo[z].move(pomocniczy);
    }
}

else if (prawa() == true && x == 2)
{
    pomocniczy = { 3.f,0.f };
    for (int z = 0; z < cialo.size(); z++)
    {
        cialo[z].move(pomocniczy);
    }
}
else
{
    for (int z = 0; z < cialo.size(); z++)
    {
        cialo[z].move(pomocniczy);
    }
} */




/*           for (int z = 0; z < cialo.size(); z++)
           {
               if (cialo[z].getPosition() == opoznienie - sf::Vector2f(0, dl))
               {
                   return true;
               }
           }*/


//DOL          
/*
    if (cialo.size() > 0)
    {
        for (int i = 0; i < cialo.size(); i++)
        {
            for (int z = 0; z < opoznienieDol.size(); z++)
            {
                for (int dl = 0; dl < 24; dl++)
                {
                    if (cialo[i].getPosition() == opoznienieDol[z] - sf::Vector2f(0, dl))
                    {
                        if (cialo[cialo.size() - 1].getPosition() == opoznienieDol[opoznienieDol.size() - 1] - sf::Vector2f(0, dl))
                        {
                            dolZmienna = 0;
                        }
                        po[i] = { 0.f,3.f };
                    }

                }
            }
        }
    }
*/