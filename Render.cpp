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

void Render::draw()
{
}

Render::~Render()
{
	Log(LOG::CLASS);
}