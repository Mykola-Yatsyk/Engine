#include "Render.h"

Render::Render() : m_run(false), m_engine(nullptr)
{
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
}