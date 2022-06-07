#ifndef PLATAFORMAMARRON_H
#define PLATAFORMAMARRON_H
#include "Player.h"
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class plataformaMarron {
public:
	plataformaMarron();
	void Update();
	void Draw(RenderWindow &window);
	bool CollideWith(Player &p);
	void MoveCam(Player &p);
	
private:
	Texture m_platamarron;
	Sprite s_platamarron;
	struct Punto {
		int x,y;
	};
	std::vector<Punto> v;
};

#endif

