#ifndef SCORES_H
#define SCORES_H
#include "Scene.h"
#include <vector>
#include "Game.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Scores : public Scene {
public:
	Scores();
	void Update (Game & game) override;
	void Draw (RenderWindow & window) override;
	void Load ();
private:
	Texture m_fondo;
	Sprite s_fondo;
	Text m_text1, m_text2, m_score1, m_score2, m_score3, m_score4, m_score5, scores;
	Font m_fuente;
	std::vector<int> puntajes;
};

#endif

