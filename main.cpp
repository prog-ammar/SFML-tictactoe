#include<iostream>
#include <SFML/Graphics.hpp>
#include <thread>

using namespace std;
using namespace sf;

class game
{
    private:
    RenderWindow window;
    VertexArray line1;
    VertexArray line2;
    VertexArray line3;
    VertexArray line4;
    CircleShape circle[9];
    int arr[9];
    bool track[9]={false};
    int l;
    int move;

    public:
    game():
    window(VideoMode(640, 480), "Tic-Tac-Toe"),line1(Lines, 2),line2(Lines, 2),line3(Lines, 2),line4(Lines, 2),move(0),l(0)
    {
        while(window.isOpen())
        {
            Event ev;
            while(window.pollEvent(ev))
            {
                if(ev.type==Event::Closed)
                {
                   window.close();
                }
            }
           window.clear(Color::White);
           drawlines();
           moves();
           drawll();
           window.display();
        }
    }
    void drawlines()
    {
      line1[0].position = Vector2f(240.f, 80.f);
      line1[0].color  = Color::Black;
      line1[1].position = Vector2f(240.f,400.f);
      line1[1].color = Color::Black;

      line2[0].position = Vector2f(400.f, 80.f);
      line2[0].color  = Color::Black;
      line2[1].position = Vector2f(400.f,400.f);
      line2[1].color = Color::Black;

      line3[0].position = Vector2f(120.f, 170.f);
      line3[0].color  = Color::Black;
      line3[1].position = Vector2f(520.f,170.f);
      line3[1].color = Color::Black;

      line4[0].position = Vector2f(120.f, 290.f);
      line4[0].color  = Color::Black;
      line4[1].position = Vector2f(520.f,290.f);
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
        arr[l]=1;
        track[l]=true;
        l++;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num2))
      {
        arr[l]=2;
        track[l]=true;
        l++;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num3))
      {
        arr[l]=3;
        track[l]=true;
        l++;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num4))
      {
        arr[l]=4;
        track[l]=true;
        l++;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num5))
      {
        arr[l]=5;
        track[l]=true;
        l++;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num6))
      {
        arr[l]=6;
        track[l]=true;
        l++;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num7))
      {
        arr[l]=7;
        track[l]=true;
        l++;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num8))
      {
        arr[l]=8;
        track[l]=true;
        l++;
      }
      else if(Keyboard::isKeyPressed(Keyboard::Num9))
      {
        arr[l]=9;
        track[l]=true;
        l++;
      }
    }
    void drawll()
    {
      for(int j=0;j<=l;j++)
       {
       for(int i=0;i<9;i++)
      {
        if(arr[j]==i+1 &&track[j])
        {
          circle[i].setOutlineThickness(3.f);
          int x=(i%3)*130+160;
          int y=(i/3)*100+110;
          circle[i].setPosition(Vector2f(x,y));
          circle[i].setRadius(25.0f);
          circle[i].setFillColor(Color::Green);
          window.draw(circle[i]);
        }
      }
    }
    }
};

int main()
{
    game a;
    return 0;
}