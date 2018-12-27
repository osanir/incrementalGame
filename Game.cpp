#include "Game.h"

Game::Game() 
: window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Incremental Game", Style::Default) 
, panel({3, 3}, {10, 10})
, button({300, 300}, "COOKIE")
{
    window.setFramerateLimit(60);
    clock.restart();
}

void Game::run(){
    boosterList.createBoosters();

    while(window.isOpen() ){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    Event e;
    while( window.pollEvent(e) ){
        switch (e.type){
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                
                break;
            default:
                break;
        }
        if( button.clicked(window) ){
            cout << "Clicked to: " << button.getText() << endl;
        }

    }
}

void Game::update(){

    // EVERY SECONDS
    if( clock.getElapsedTime().asMilliseconds() > 1000 ){
        boosterList.addBooster(0);
        boosterList.harvestAll();
        clock.restart();
    }
    //boosterList.printBoosters();
    button.update();

}

void Game::render(){
    window.clear(Color::Magenta);
    panel.draw(window);
    button.draw(window);
    window.display();
}
