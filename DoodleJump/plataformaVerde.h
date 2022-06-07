#ifndef PLATAFORMAVERDE_H
#define PLATAFORMAVERDE_H
#include <vector>
#include "Player.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class plataformaVerde {
public:
	plataformaVerde();
	void Update();
	void Draw(RenderWindow &window);
	bool CollideWith(Player &p);
	void MoveCam(Player &p);
	
private:
	Texture m_plataverde;
	Sprite s_plataverde;
	struct Punto {
		int x,y;
	};
	std::vector<Punto> v;
};

#endif

