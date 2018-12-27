#include "Game.h"

Game::Game() : window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Incremental Game", Style::Default) {
    window.setFramerateLimit(60);
    clock.restart();
}

void Game::run(){
    boosterList.createBoosters();
    boosterList.printBoosters();

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
    }
}

void Game::update(){

    // EVERY SECONDS
    if( clock.getElapsedTime().asMilliseconds() > 1000 ){
        boosterList.addBooster(0);
        boosterList.harvestAll();
        clock.restart();
    }
    boosterList.printBoosters();
}

void Game::render(){
    window.clear(Color::Black);
    //window.draw();
    window.display();
}
