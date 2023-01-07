#include "CelestialBody.cpp"
#include <string>
#include <vector>
#include <math.h>
using std::endl;
using std::ostream;
using std::istream;
using std::string;
using std::vector;
using std::cin;
using std::cout;

class Universe
{
public:
//default constructor
Universe(sf::RenderWindow& window)
{
 cin >> numPlanets;
 cin >> radius;
 //for each planet..
 for(; numPlanets > 0; numPlanets--)
 {
  cin >> xpos;
  cin >> ypos;
  cin >> xvelo;
  cin >> yvelo;
  cin >> mass;
  cin >> filename;
  size = window.getSize();

  //create a new planet with the info got
  CelestialBody* planet = new CelestialBody(xpos,ypos,xvelo,yvelo,mass,filename, radius, size);
  planets.push_back(planet);
 }
}

virtual void draw(sf::RenderWindow& window)
{
 for(vector<CelestialBody*>::iterator it = planets.begin(); it!= planets.end();it++)
  {
	(*it)->draw(window);
  }
}

void step(double seconds){

double deltaX;
double deltaY;
double deltaR;
double force;
double forceY;
double forceX;
double netForce;
double xAccel;
double yAccel;
double xVeloNew;
double yVeloNew;
double xPosNew;
double yPosNew;

 for(int i = 0; planets[i+1] != NULL; i++)
{
//get the difference in positions from i to the next one
deltaX = planets[i]->get_xPosition() - planets[i+1]->get_xPosition();
deltaY = planets[i]->get_yPosition() - planets[i+1]->get_yPosition();
deltaR = sqrt((deltaX * deltaX)+(deltaY * deltaY));

//get and set netforce
force = (Grav_const * (planets[i]->get_mass()) * (planets[i+1]->get_mass())) / (deltaR * deltaR);
forceY = (force * deltaY) / (deltaR);
forceX = (force * deltaX) / (deltaR);
netForce = forceX + forceY;
planets[i]->set_netForce(netForce);
planets[i+1]->set_netForce(netForce);

//get and set acceleration
xAccel = forceX / planets[i]->get_mass();
yAccel = forceY / planets[i]->get_mass();
planets[i]->set_xAcceleration(xAccel);
planets[i]->set_yAcceleration(yAccel);

//calculate new velocity using the acceleration and time
xVeloNew = planets[i]->get_xVelocity() + (seconds * xAccel);
yVeloNew = planets[i]->get_yVelocity() + (seconds * yAccel);
planets[i]->set_xVelocity(xVeloNew);
planets[i]->set_yVelocity(yVeloNew);

//calculate new position
xPosNew = planets[i]->get_xPosition() + (seconds * planets[i]->get_xVelocity());
yPosNew = planets[i]->get_yPosition() + (seconds * planets[i]->get_yVelocity());
planets[i]->set_xPosition(xPosNew);
planets[i]->set_yPosition(yPosNew);
}

}

//friend istream& operator>>(istream& in, Universe universe){
//in >> universe.numPlanets >> universe.radius;
//in >> universe.xpos >> universe.ypos;
//in >> universe.xvelo >> universe.yvelo;
//in >> universe.mass >> universe.filename;
//return in;
//}

double get_G(void){
return Grav_const;}
friend ostream& operator<<(ostream& out, Universe universe){
 for(vector<CelestialBody*>::iterator it = universe.planets.begin(); it!= universe.planets.end(); it++)
 {
	out << **it << endl;
 }
return out;
}
private:
int numPlanets;
double radius;
sf::Vector2u size;
//make a vector of celestialbodies
vector<CelestialBody*> planets;

//temp variables to hold scanned values
double xpos,ypos,xvelo,yvelo,mass;
string filename;

//values for forces
const double Grav_const = (6.67*pow(10,-11));
};
