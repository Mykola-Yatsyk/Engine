#include "Render.h"

Render::Render() : m_run(false), m_engine(nullptr)
{
	Log(LOG::CLASS);
}

Render& Render::getRender()
{
	static Render render;
	return render;
}

void Render::init()
{
}

void Render::setViewPort(const unsigned short width, const unsigned short height)
{
	Log(LOG::MESSAGE).print("ViewPort %ix%i", width, height);
}

void Render::draw()
{
}

Render::~Render()
{
	Log(LOG::CLASS);
}