#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game
{
    private:
    RenderWindow window;
    VertexArray line1;
    VertexArray line2;
    VertexArray line3;
    VertexArray line4;
    CircleShape circle[9];
    vector <int> p1_move;
    vector <int> p2_move;
    int t_moves;
    Font font;
    Text string;
    int occ[9];

    public:
    Game(): window(VideoMode(800,800),"Tic-Tac-Toe"),line1(Lines,2),line2(Lines,2),line3(Lines,2),line4(Lines,2),t_moves(2),occ{0}
    {
      font.loadFromFile("Arial.ttf");
      string.setFont(font);
      string.setFillColor(Color::Black);
      string.setCharacterSize(30);
      string.setPosition(250,150);
    }
    void run()
    {
      while(window.isOpen())
      {
      window.clear(Color::White);
      string.setString("Press A To Start");
      window.draw(string);
      window.display();
      if(Keyboard::isKeyPressed(Keyboard::A))
      {
         while(window.isOpen())
        {
        Event ef;
        while(window.pollEvent(ef))
        {
            if(ef.type==Event::Closed)
            {
                window.close();
            }
        }
        window.clear(Color::White);
        drawlines();
        moves();
        drawcircles();
        checkwin();
        window.display();
        }
        break;
      }
      } 
    }
    void drawlines()
    {
        line1[0].position = Vector2f(300, 250);
        line1[0].color  = Color::Black;
        line1[1].position = Vector2f(300,500);
        line1[1].color = Color::Black;

        line2[0].position = Vector2f(450, 250);
        line2[0].color  = Color::Black;
        line2[1].position = Vector2f(450,500);
        line2[1].color = Color::Black;

        line3[0].position = Vector2f(200, 325);
        line3[0].color  = Color::Black;
        line3[1].position = Vector2f(550,325);
        line3[1].color = Color::Black;

        line4[0].position = Vector2f(200, 425);
        line4[0].color  = Color::Black;
        line4[1].position = Vector2f(550,425);
        line4[1].color = Color::Black;

        window.draw(line1);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);
    }

    void moves()
    {
        if(Keyboard::isKeyPressed(Keyboard::Num1) && occ[0]==0)
      {
        (t_moves%2==0)?p1_move.push_back(0):p2_move.push_back(0);
        t_moves++;
        occ[0]=1;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num2) && occ[1]==0)
      {
        (t_moves%2==0)?p1_move.push_back(1):p2_move.push_back(1);
        t_moves++;
        occ[1]=1;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num3) && occ[2]==0)
      {
        (t_moves%2==0)?p1_move.push_back(2):p2_move.push_back(2);
        t_moves++;
        occ[2]=1;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num4) && occ[3]==0)
      {
        (t_moves%2==0)?p1_move.push_back(3):p2_move.push_back(3);
        t_moves++;
        occ[3]=1;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num5) && occ[4]==0)
      {
       (t_moves%2==0)?p1_move.push_back(4):p2_move.push_back(4);
       t_moves++;
       occ[4]=1;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num6) && occ[5]==0)
      {
        (t_moves%2==0)?p1_move.push_back(5):p2_move.push_back(5);
        t_moves++;
        occ[5]=1;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num7) && occ[6]==0)
      {
        (t_moves%2==0)?p1_move.push_back(6):p2_move.push_back(6);
        t_moves++;
        occ[6]=1;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num8) && occ[7]==0)
      {
        (t_moves%2==0)?p1_move.push_back(7):p2_move.push_back(7);
        t_moves++;
        occ[7]=1;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num9) && occ[8]==0)
      {
        (t_moves%2==0)?p1_move.push_back(8):p2_move.push_back(8);
        t_moves++;
        occ[8]=1;
      }
    }
    void checkwin()
    {
      const int win[8][3]={
        {0,1,2},{3,4,5},{6,7,8},{0,3,5},{1,4,6},{2,5,7},{0,4,8},{2,4,6}
      };
      for(int i=0;i<8;i++)
      {
        bool wini=true;
        for(int j=0;j<3;j++)
        {
          if(find(p1_move.begin(),p1_move.end(),win[i][j])!=p1_move.end());
          else
          {
            wini=false;
            break;
          }
        }
        if(wini)
        {
           string.setString("Player 1 Wins !");
           window.draw(string);
           reset();
           return;
        }
      }
      for(int i=0;i<8;i++)
      {
        bool wini=true;
        for(int j=0;j<3;j++)
        {
          if(find(p2_move.begin(),p2_move.end(),win[i][j])!=p2_move.end());
          else
          {
            wini=false;
            break;
          }
        }
        if(wini)
        {
           string.setString("Player 2 Wins !");
           window.draw(string);
           reset();
           return;
        }
      }
    }

    void drawcircles()
    {
      for(int i: p1_move)
      {
        circle[i].setRadius(20);
        int x=(i/3)*75+280;
        int y=(i%3)*115+245;
        circle[i].setOutlineThickness(3.f);
        circle[i].setOutlineColor(Color::Green);
        circle[i].setPosition(y,x);
        window.draw(circle[i]);
      }
      for(int i: p2_move)
      {
        circle[i].setRadius(20);
        int x=(i/3)*75+280;
        int y=(i%3)*115+245;
        circle[i].setOutlineThickness(3.f);
        circle[i].setOutlineColor(Color::Red);
        circle[i].setPosition(y,x);
        window.draw(circle[i]);
      }  
}

void reset()
{
  window.display();
  sf::sleep(sf::seconds(3));
  t_moves=2;
  p1_move.clear();
  p2_move.clear();
  for(int i=0;i<8;i++)
  {
    occ[i]=0;
  }
}

};

int main()
{
    Game a;
    a.run();
}
