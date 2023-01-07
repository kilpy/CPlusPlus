#include <iostream>
#include <stdlib.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>

using std::ostream;
using std::endl;
using std::istream;
using std::string;
using sf::Vector2f;

//implement a celestialbody class
class CelestialBody{
public:
//value constructor
CelestialBody(double xPos, double yPos, double xVelo,
double yVelo, double Mass, string fileName, double universeradius, sf::Vector2u Size){
xPosition = xPos;
yPosition = yPos;
xVelocity = xVelo;
yVelocity = yVelo;
mass = Mass;
filename = fileName;
universeRadius = universeradius;
size = Size;
//load image, texture and sprite
image.loadFromFile(filename);
texture.loadFromImage(image);
sprite.setTexture(texture);

//setPosition();

}

//setter for netForce
void set_netForce(double force){
netForce = force;}

//empty constructor
CelestialBody(void){
xPosition = 0;
yPosition = 0;
xVelocity = 0;
yVelocity = 0;
mass = 0;
filename = "empty";
}
//getter functions to return private members
double get_xPosition(void){
return xPosition;}

double get_yPosition(void){
return yPosition;}

double get_xVelocity(void){
return xVelocity;}

double get_yVelocity(void){
return yVelocity;}

double get_mass(void){
return mass;}

double get_netForce(void){
return netForce;}

double get_xAcceleration(void){
return xAcceleration;}

double get_yAcceleration(void){
return yAcceleration;}
void setPosition(void){
xPosition = ((xPosition / universeRadius) * (size.x / 2)) + (size.x / 2);
yPosition = ((yPosition / universeRadius) * (size.y / 2)) + (size.y / 2);
sprite.setPosition(xPosition, yPosition);
}

//mutator function to modify velocitys
void set_xPosition(double position){
xPosition = position;}
void set_yPosition(double position){
yPosition = position;}
void set_xVelocity(double velocity){
yVelocity = velocity;
}
void set_yVelocity(double velocity){
xVelocity = velocity;
}
void set_xAcceleration(double accel){
xAcceleration = accel;}
void set_yAcceleration(double accel){
yAcceleration = accel;}
//calculate the net force (Fx and Fy) at current time t acting on
//this celestial body object
//void set_netForce(){

//moves object due to velocity for given time
void step(double seconds);
//overload insertion operator to read in values
friend istream& operator>>(istream& in, CelestialBody& celestialBody){
in >> celestialBody.xPosition >> celestialBody.yPosition;
in >> celestialBody.xVelocity >> celestialBody.yVelocity;
in >> celestialBody.mass;
in >> celestialBody.filename;

if(!celestialBody.image.loadFromFile(celestialBody.filename))
	return in;
celestialBody.texture.loadFromImage(celestialBody.image);
celestialBody.sprite.setTexture(celestialBody.texture);
celestialBody.sprite.setPosition(celestialBody.xPosition,celestialBody.yPosition);

return in;
}

friend ostream& operator<<(ostream& out, CelestialBody& celestialBody){
out << "Xposition: " << celestialBody.xPosition << endl;
out << "Yposition: " << celestialBody.yPosition << endl;
out << "xvelocity: " << celestialBody.xVelocity << endl;
out << "yvelocity: " << celestialBody.yVelocity << endl;
out << "mass: " << celestialBody.mass << endl;
return out;
}

virtual void draw(sf::RenderWindow& window){
 window.draw(sprite);
}

private:
double xPosition;
double yPosition;
double xVelocity;
double yVelocity;
double mass;
string filename;
sf::Image image;
sf::Texture texture;
sf::Sprite sprite;
double universeRadius;
sf::Vector2u size;
double netForce;
double xAcceleration;
double yAcceleration;
};
