#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Panel{
public:
    Panel(Vector2f pos, Vector2f size);
    void draw(RenderWindow& window);
private:
    Vector2f _pos;
    Vector2f _size;
    const int tileSize = 32;
    Texture _texture;
    Sprite _sprites[9];
};

class Button{
public:
    Button(Vector2f pos, string text);
    void draw(RenderWindow& window);

    void update();
    bool clicked(RenderWindow& window);
    bool isInside(Vector2f pos);
    bool isInside(Vector2i pos);
    
    // Getters
    Vector2f getSize();
    Vector2f getPosition();
    string getText();
private:
    Vector2f _pos;
    Vector2f _size;
    char _state;
    Texture _texture[3];
    Sprite _sprite;

    Vector2f _imagePoints[2];   // 1 for icon, 2 for text

    Texture _textureIcon;
    Sprite _spriteIcon;

    Text _text;
    Font _font;

};

class Label{
public:
    Label(float x, float y, string text);

private:

};