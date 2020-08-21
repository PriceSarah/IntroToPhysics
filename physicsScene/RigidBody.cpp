#include "RigidBody.h"

RigidBody::RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass) : PhysicsObject(shapeID)
{
	//m_shapeID = shapeID;
	m_position = position;
	m_velocity = velocity;
	m_rotation = rotation;
	m_mass = mass;
}

void RigidBody::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	//Apply gravity
	applyForce(gravity * m_mass);
	//Calculate the change in position
	m_position += m_velocity * timeStep;
}

void RigidBody::applyForce(glm::vec2 force)
{
	//Calculate the change in Velocity
	m_velocity += force / m_mass;
}

void RigidBody::applyForceToActor(RigidBody* otherActor, glm::vec2 force)
{
	//Apply the force to the other
	otherActor->applyForce(force);
	applyForce(-force);

}
