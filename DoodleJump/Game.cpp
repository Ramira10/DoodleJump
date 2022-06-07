#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
using namespace sf;

Game::Game() : m_window(VideoMode(500,700),"Doodle Jump") {
	m_window.setFramerateLimit(60);
	m_scene = new Menu();
}

void Game::Run ( ) {
	while(m_window.isOpen()) {
		ProcessEvents();
		Update();
		Draw();
		if (m_next_scene) {
			delete m_scene;
			m_scene = m_next_scene;
			m_next_scene = nullptr;
		}
	}
}

void Game::Update ( ) {
	m_scene->Update(*this);
}

void Game::Draw ( ) {
	m_scene->Draw(m_window);
}

void Game::ProcessEvents ( ) {
	Event e;
	while(m_window.pollEvent(e)) {
		if(e.type == Event::Closed)
			m_window.close();
	}
}

void Game::SetScene (Scene *next_scene) {
	m_next_scene = next_scene;
}
