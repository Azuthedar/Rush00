#include "main.hpp"

void render(){
    Draw *draw = new Draw();
    draw->getWin();
}

void update(){
    Draw *draw = new Draw();
    draw->drawBox();
}

int main(){
    while (1)
    {
        update();
        render();
    }
    endwin();
    return 0;
}