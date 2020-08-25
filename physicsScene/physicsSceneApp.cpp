#include "PhysicsSceneApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Sphere.h"
#include <Gizmos.h>

PhysicsSceneApp::PhysicsSceneApp() {

}

PhysicsSceneApp::~PhysicsSceneApp() {

}

bool PhysicsSceneApp::startup() {
	// increase the 2D line count to maximize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, 0));
	m_physicsScene->setTimeStep(0.01f);

	Sphere* ball1 = new Sphere(glm::vec2(-40.0f, 0.0f), glm::vec2(60.0f, 0.0f),
		8.0f, 8.0f, glm::vec4(1, 0, 0, 1));
	m_physicsScene->addActor(ball1);

	Sphere* ball2 = new Sphere(glm::vec2(40.0f, 0.0f), glm::vec2(-30.0f, 0.0f),
		2.0f, 6.0f, glm::vec4(0, 1, 0, 1));
	m_physicsScene->addActor(ball2);

	Sphere* ball3 = new Sphere(glm::vec2(60.0f, 0.0f), glm::vec2(-30.0f, 0.0f),
		1.0f, 4.0f, glm::vec4(0, 0, 1, 1));
	m_physicsScene->addActor(ball3);

	return true;
}

void PhysicsSceneApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsSceneApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// clear the buffer
	aie::Gizmos::clear();

	// update the PhysicsScene
	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsSceneApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.0f;
	aie::Gizmos::draw2D(glm::ortho<float>(
		-100.0f, 100.0f,
		-100.0f / aspectRatio, 100.0f / aspectRatio,
		-1.0f, 1.0f));

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}