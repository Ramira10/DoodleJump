#ifndef PLATAFORMAAZUL_H
#define PLATAFORMAAZUL_H
#include <vector>
#include "Player.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class plataformaAzul {
public:
	plataformaAzul();
	void Update();
	void Draw(RenderWindow &window);
	bool CollideWith(Player &p);
	void MoveCam(Player &p);
	
private:
	Texture m_platazul;
	Sprite s_platazul;
	struct Punto {
		int x,y;
	};
	std::vector<Punto> v;
};

#endif

