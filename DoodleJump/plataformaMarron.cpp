#include "plataformaMarron.h"
#include <vector>
using namespace std;

plataformaMarron::plataformaMarron() {
	m_platamarron.loadFromFile("imagenes/platamarron.png");
	s_platamarron.setTexture(m_platamarron);
	
	for(int i=0;i<1;i++) {
		Punto p;
		p.x = rand() % 500;
		p.y = 450;
		v.push_back(p);
	}
}


void plataformaMarron::Update ( ) {
	
}

void plataformaMarron::Draw(RenderWindow &window) {
	for(int i=0;i<v.size();i++) {
		if(v[i].x>435){
			v[i].x = v[i].x - (v[i].x-435);
		}
		s_platamarron.setPosition(v[i].x,v[i].y);
		window.draw(s_platamarron);
	}
}

bool plataformaMarron::CollideWith(Player &p){
	for(int i=0;i<v.size();i++) {
		if((p.GetX()+50>v[i].x) && (p.GetX()+20<v[i].x+68)
			&& (p.GetY()+70>v[i].y) && (p.GetY()+70<v[i].y+14) && (p.GetB()>0)) {
			p.Bounce();
			v.pop_back();
			for(int i=0;i<1;i++) {
				Punto p;
				p.x = rand() % 500;
				p.y = 800;
				v.push_back(p);
			}
		}
	}
}

void plataformaMarron::MoveCam(Player &p){
	for(int i=0;i<v.size();i++) {
		int auxY = p.GetY();
		int auxH = p.GetH();
		auxY = auxH;
		p.SetY(auxY);
		p.SetH(auxH);
		v[i].y = v[i].y - p.GetB();
		if(v[i].y>700) {
			v[i].y = 0;
			v[i].x = rand()%500;
		}
	}
}

