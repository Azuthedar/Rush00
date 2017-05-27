/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:35:03 by jbuys             #+#    #+#             */
/*   Updated: 2017/05/27 08:35:04 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include "AGameObject.class.hpp"
#include "../main.hpp"

class Player: virtual public AGameObject
{
    public:
    Player();
    Player(Player const & src);
    ~Player();
    Player& operator=(Player const & src);
    void render();
    void Fire();
    void movement();
    virtual void movement(int ch);
    private:

};
