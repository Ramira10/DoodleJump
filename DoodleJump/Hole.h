#ifndef HOLE_H
#define HOLE_H
#include "Player.h"
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Hole {
public:
	Hole();
	void Draw(RenderWindow &window);
	bool CollideWith(Player &p);
	void MoveCam(Player &p);
	
private:
	Texture m_hole;
	Sprite s_hole;
	struct Punto {
		int x,y;
	};
	std::vector<Punto> v;
};

#endif

