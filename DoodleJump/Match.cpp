#include "Match.h"
#include "Menu.h"
#include "Game.h"
#include "GameOver.h"
#include <SFML/Window/Keyboard.hpp>
using namespace sf;

Match::Match() {
	m_fondo.loadFromFile("imagenes/fondo.png");
	s_fondo.setTexture(m_fondo);
}

void Match::Update (Game & game) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
		game.SetScene(new Menu());
	
	m_plataverde.CollideWith(m_jugador);
	m_platazul.CollideWith(m_jugador);
	m_platamarron.CollideWith(m_jugador);
	
	if( (m_score.GetScore()>1000 and m_hole.CollideWith(m_jugador)==true) or (m_score.GetScore()>5000 and m_hole2.CollideWith(m_jugador)==true)){
		game.SetScene(new GameOver(m_score.GetScore()));
	}
	
	if(m_jugador.GetY() < m_jugador.GetH()){
		m_plataverde.MoveCam(m_jugador);
		m_platazul.MoveCam(m_jugador);
		m_platamarron.MoveCam(m_jugador);
		m_hole.MoveCam(m_jugador);
		m_hole2.MoveCam(m_jugador);
	}
	
	if(m_jugador.GetY() == m_jugador.GetH() && m_jugador.GetB() < 0){
		m_score.Update();
	}
	
	m_jugador.Update();
	m_platazul.Update();
	
	if(m_score.GetScore() > 1000 and m_score.GetScore() < 2000){
		m_jugador.LevelONE();
	}
	if(m_score.GetScore() > 3000 and m_score.GetScore() < 4000){
		m_jugador.LevelTWO();
		m_platazul.Update();
	}
	if(m_score.GetScore() > 5000){
		m_jugador.LevelFINAL();
		m_platazul.Update();
	}
	
	if (m_jugador.GetY() > 700) {
		game.SetScene(new GameOver(m_score.GetScore()));
	}
}

void Match::Draw (RenderWindow & window) {
	window.clear(Color(255,255,255,255));
	window.draw(s_fondo);
	m_jugador.Draw(window);
	m_plataverde.Draw(window);
	m_platazul.Draw(window);
	m_platamarron.Draw(window);
	m_score.Draw(window);
	
	if(m_score.GetScore()>1000){
		m_hole.Draw(window);
	}
	if(m_score.GetScore()>5000){
		m_hole2.Draw(window);
	}
	
	window.display();
}

