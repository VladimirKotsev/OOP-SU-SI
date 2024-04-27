#include "Engine.h"

Engine::Engine(const char* producer, const char* description, unsigned horsePower)
	: CarPart(producer, description)
{
	this->horsePower = horsePower;
}

unsigned Engine::getHorsePower() const
{
	return this->horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine)
{
	os << (CarPart&)engine;
	return os << "- " << engine.horsePower << " hp";
}
