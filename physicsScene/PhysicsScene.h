#pragma once
#include "PhysicsObject.h"
#include <glm\ext.hpp>
#include <vector>

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();
	
	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);
	void update(float deltaTime);
	void updateGizmos();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	glm::vec2 getGravity() const { return m_gravity; }

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	float getTimeStep() const { return m_timeStep; }

protected:
	glm::vec2					m_gravity;
	float						m_timeStep = 0.01f;
	std::vector<PhysicsObject*> m_actors;
};

