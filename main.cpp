/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:48:54 by jbuys             #+#    #+#             */
/*   Updated: 2017/05/27 08:48:55 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
