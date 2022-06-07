#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Score.h"
using namespace sf;

class Player {
public:
	Player();
	void Update();
	void Bounce();
	void Bounce2();
	void Draw(RenderWindow &window);
	int GetX() const;
	int GetY() const;
	int GetH() const;
	void SetY(int auxy);
	void SetH(int auxh);
	float GetB() const;
	void LevelONE();
	void LevelTWO();
	void LevelFINAL();
private:
	Texture m_personaje;
	Sprite s_personaje;
	int x=250, y=250, h=250;
	float b=0;
//	Score m_score;
};

#endif

