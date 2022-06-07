#ifndef MATCH_H
#define MATCH_H
#include "Scene.h"
#include "Player.h"
#include "plataformaAzul.h"
#include "plataformaVerde.h"
#include "plataformaMarron.h"
#include "Score.h"
#include "Hole.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;

class Match : public Scene {
public:
	Match();
	void Update (Game & game) override;
	void Draw (RenderWindow & window) override;
private:
	Texture m_fondo;
	Sprite s_fondo;
	Player m_jugador;
	plataformaVerde m_plataverde;
	plataformaAzul m_platazul;
	plataformaMarron m_platamarron;
	Hole m_hole;
	Hole m_hole2;
	Score m_score;
};

#endif

