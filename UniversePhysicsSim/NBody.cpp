
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

//#include "CelestialBody.cpp"
#include "Universe.cpp"
using std::cout;
using std::endl;
using std::cin;
//
//double calc_netForce(CelestialBody& planet1, CelestialBody& planet2,
//			double seconds);
int main(int argc, char* argv[])
{
 //get the command line arguements T and deltat
 //double Tmax;
 //double Tdelta;

 //generate a window
 sf::RenderWindow window(sf::VideoMode(1920,1080), "The Universe");

 //load music (extra credit!)
 sf::Music music;
 if(!music.openFromFile("music.wav"))
	return -1;

 //declare a universe!
 Universe Milky_Way(window);

while(window.isOpen())
{

 sf::Event event;
 while(window.pollEvent(event))
 {
	music.play();
	if(event.type == sf::Event::Closed)
		window.close();
 }
 window.clear();
 Milky_Way.step(60);
 Milky_Way.draw(window);
 window.display();
}
 return 0;
}

//double calc_netForce(CelestialBody& planet1, CelestialBody& planet2,
//			double seconds){
//double deltaX;
//double deltaY;
//deltaX = (planet1.xPosition) - (planet2.xPosition);
//deltaY = (planet1.yPosition) - (planet2.yPosition);
//cout << deltaX << endl;
//cout << deltaY << endl;

//double deltaR;
//deltaR = (((deltaX)^2)+((deltaY)^2)^.5)
//cout << deltaR << endl;
//}
