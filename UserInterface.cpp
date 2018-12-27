#include "UserInterface.h"

MenuArea::MenuArea(float x, float y, float width, float height){
    _x      = x * tileSize;
    _y      = y * tileSize;
    _width  = width * tileSize;
    _height = height * tileSize;
    
    if( !_texture.loadFromFile("res/texture/grey_panel.png") ){
        // error handle
    }


    for( int i=0; i<9; i++)
        _sprites[i].setTexture(_texture);

    // setting texture rects
    _sprites[0].setTextureRect(IntRect(0, 0, tileSize, tileSize));
    _sprites[1].setTextureRect(IntRect(tileSize, 0, tileSize, tileSize));
    _sprites[2].setTextureRect(IntRect(2*tileSize, 0, tileSize, tileSize));
    _sprites[3].setTextureRect(IntRect(0, tileSize, tileSize, tileSize));
    _sprites[4].setTextureRect(IntRect(tileSize, tileSize, tileSize, tileSize));
    _sprites[5].setTextureRect(IntRect(2*tileSize, tileSize, tileSize, tileSize));
    _sprites[6].setTextureRect(IntRect(0, 2*tileSize, tileSize, tileSize));
    _sprites[7].setTextureRect(IntRect(tileSize, 2*tileSize, tileSize, tileSize));
    _sprites[8].setTextureRect(IntRect(2*tileSize, 2*tileSize, tileSize, tileSize));


    // corner settings
    _sprites[0].setPosition({_x, _y});
    _sprites[2].setPosition({_x + _width, _y});
    _sprites[6].setPosition({_x, _y + _height});
    _sprites[8].setPosition({_x + _width, _y + _height});
}

void MenuArea::draw(RenderWindow& window){
    for( int j = _y; j <= _y + _height; j += tileSize){
        for( int i = _x; i <= _x + _width; i+= tileSize){
            if( j == _y ){                     // TOP
                if( i == _x ){                      // left
                    window.draw(_sprites[0]);
                }                          
                else if( i == _x + _width ){        // right
                    window.draw(_sprites[2]);
                }
                else{                               // mid
                    _sprites[1].setPosition({float(i), float(j)});
                    window.draw(_sprites[1]);
                }
            }
            else if( j == _y + _width ){      // BOTTOM
                if( i == _x ){                      // left
                    window.draw(_sprites[6]);
                }
                else if( i == _x + _width ){        // right
                    window.draw(_sprites[8]);
                }
                else {
                    _sprites[7].setPosition({float(i), float(j)});// mid
                    window.draw(_sprites[7]);
                }
            } else{                          // CENTER
                if( i == _x ){                      // left
                    _sprites[3].setPosition({i,j});
                    window.draw(_sprites[3]);
                }                          
                else if( i == _x + _width ){        // right
                    _sprites[5].setPosition({i,j});
                    window.draw(_sprites[5]);
                }    
                else {
                    _sprites[4].setPosition({float(i), float(j)});// mid
                    window.draw(_sprites[4]);
                }
            }
        }
    }
}