#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"

class physicsSceneApp : public aie::Application {
public:

	physicsSceneApp();
	virtual ~physicsSceneApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	PhysicsScene*		m_physicsScene;
};