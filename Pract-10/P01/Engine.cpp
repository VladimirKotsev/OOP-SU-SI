#include "Engine.h"

Engine::Engine(char* producer, char* description, unsigned horsePower) 
	: CarPart(producer, description)
{
	this->horsePower = horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine)
{
	os << (CarPart&)engine;
	return os << "- " << engine.horsePower << " hp";
}
