#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Score {
public:
	Score();
	void Update();
	int GetScore();
	void Draw(RenderWindow &window);
private:
	Font m_fuente;
	Text scoreText;
	int score = 0;
};

#endif

