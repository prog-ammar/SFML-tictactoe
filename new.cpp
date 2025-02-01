#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game
{
    private:
    RenderWindow window;

    public:
    Game(): window(VideoMode(800,800),"Tic-Tac-Toe")
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
        drawlines();
        window.clear(Color::White);
        window.display();
      }
    }
    void drawlines()
    {
        VertexArray line1(Lines,2);
        line1[0].position = Vector2f(100.f, 100.f);
        line1[0].color  = Color::Black;
        line1[1].position = Vector2f(100.f,200.f);
        line1[1].color = Color::Black;
        window.draw(line1);
    }
};

int main()
{
    Game a;
    a.run();
}
