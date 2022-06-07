#include "Menu.h"
#include "Game.h"
#include "Match.h"
#include "Scores.h"
#include <SFML/Window/Keyboard.hpp>
using namespace sf;

Menu::Menu() {
	m_fondo.loadFromFile("imagenes/fondomenu.png");
	s_fondo.setTexture(m_fondo);
	
	m_fuente.loadFromFile("fuentes/al-seana.ttf");
	m_text1.setFont(m_fuente);
	m_text2.setFont(m_fuente);
	m_text3.setFont(m_fuente);
	
	m_text1.setString("Doodle Jump");
	m_text1.setFillColor(Color::Red);
	m_text1.setPosition(50,110);
	m_text1.setCharacterSize(100);
	
	m_text2.setString("<Presione 'Espacio' para comenzar a jugar>");
	m_text2.setFillColor(Color::Black);
	m_text2.setPosition(25,600);
	m_text2.setCharacterSize(30);
	
	m_text3.setString("<Presione 'P' para ver la tabla de posiciones>");
	m_text3.setFillColor(Color::Black);
	m_text3.setPosition(15,650);
	m_text3.setCharacterSize(30);
}

void Menu::Update (Game & game) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Space))
		game.SetScene(new Match());
	if(Keyboard::isKeyPressed(Keyboard::Key::P))
		game.SetScene(new Scores());
}

void Menu::Draw (RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(s_fondo);
	window.draw(m_text1);
	window.draw(m_text2);
	window.draw(m_text3);
	window.display();
}

