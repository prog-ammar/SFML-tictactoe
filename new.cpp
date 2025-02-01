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
    vector <int> move;
    public:
    Game(): window(VideoMode(800,800),"Tic-Tac-Toe"),line1(Lines,2),line2(Lines,2),line3(Lines,2),line4(Lines,2)
    {}
    void run()
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
        window.display();
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
        if(Keyboard::isKeyPressed(Keyboard::Num1))
      {
        move.push_back(0);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num2))
      {
        move.push_back(1);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num3))
      {
        move.push_back(2);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num4))
      {
        move.push_back(3);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num5))
      {
        move.push_back(4);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num6))
      {
        move.push_back(5);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num7))
      {
        move.push_back(6);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num8))
      {
        move.push_back(7);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num9))
      {
        move.push_back(8);
      }
    }

    void drawcircles()
    {
      for(int i: move)
      {
        circle[i].setRadius(20);
        int x=(i/3)*75+280;
        int y=(i%3)*115+245;
        circle[i].setOutlineThickness(3.f);
        circle[i].setFillColor((i%2==0)?Color::Green:Color::Red);
        circle[i].setPosition(y,x);
        window.draw(circle[i]);
      }   
    }
};

int main()
{
    Game a;
    a.run();
}
