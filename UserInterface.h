#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class MenuArea{
public:
    MenuArea(float x, float y, float width, float height);
    void draw(RenderWindow& window);
private:
    float _x, _y, _width, _height;
    const int tileSize = 32;
    Texture _texture;
    Sprite _sprites[9];
};