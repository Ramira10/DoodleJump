#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Player::Player() {
	m_personaje.loadFromFile("imagenes/pj.png");
	s_personaje.setTexture(m_personaje);
}

void Player::Update ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Right) or Keyboard::isKeyPressed(Keyboard::D)) {
		/// Voltea el sprite y cambia la dirección en X.
		s_personaje.setTextureRect(IntRect(0,0,80,65));
		x+= 4;
	}
	if(Keyboard::isKeyPressed(Keyboard::Left) or Keyboard::isKeyPressed(Keyboard::A)){
		/// Voltea el sprite y cambia la dirección en -X.
		s_personaje.setTextureRect(IntRect(80,0,-80,65));
		x-= 4;	
	}
	/// El jugador sobrepasa los limites de la coordenada x.
	if(x > 500) {
		x = -20;
	}
	if(x < -40) {
		x = (500 - 50)+40;
	}
	b+=0.2;
	y+=b;
	if(y>700) b=-10;
	s_personaje.setPosition(x,y);
}

void Player::Bounce ( ) {
	b = -10;
}

void Player::Bounce2 ( ) {
	b = -20;
}

void Player::Draw(RenderWindow &window) {
	window.draw(s_personaje);
}

int Player::GetX ( ) const {
	return x;
}

int Player::GetY ( ) const {
	return y;
}

int Player::GetH ( ) const {
	return h;
}

void Player::SetY (int auxy) {
	y = auxy;
}

void Player::SetH (int auxh) {
	h = auxh;
}

float Player::GetB ( ) const {
	return b;
}

void Player::LevelONE ( ) {
	y+=b;
	if(y>700) b=-10;
	if(Keyboard::isKeyPressed(Keyboard::Right) or Keyboard::isKeyPressed(Keyboard::D)) {
		x+= 8;
	}
	if(Keyboard::isKeyPressed(Keyboard::Left) or Keyboard::isKeyPressed(Keyboard::A)){
		x-= 8;	
	}
}

void Player::LevelTWO ( ) {
	b+=0.1;
	y+=b;
	if(y>700) b=-20;
	if(Keyboard::isKeyPressed(Keyboard::Right) or Keyboard::isKeyPressed(Keyboard::D)) {
		x+= 8;
	}
	if(Keyboard::isKeyPressed(Keyboard::Left) or Keyboard::isKeyPressed(Keyboard::A)){
		x-= 8;	
	}
}

void Player::LevelFINAL ( ) {
	b+=0.15;
	y+=b;
	if(y>700) b=-30;
	if(Keyboard::isKeyPressed(Keyboard::Right) or Keyboard::isKeyPressed(Keyboard::D)) {
		x+= 10;
	}
	if(Keyboard::isKeyPressed(Keyboard::Left) or Keyboard::isKeyPressed(Keyboard::A)){
		x-= 10;	
	}
}
