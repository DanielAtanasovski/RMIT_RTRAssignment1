#pragma once

#include "Scene.h"
#include "../shaders/Shader.h"
#include "../drawing/Light.h"

class SceneModern : public Scene {
public:
	// Inherited via Scene
	virtual void Init(HUD* hud, Camera* camera) override;
	virtual void Run() override;
	virtual void Done() override;
	virtual void Recalculate() override;

protected:
	void setupBuffers();
	void setupMaterials();
	void setupLights();

	// Inherited via Scene
	virtual void SetupDraw();
	virtual void Draw() override;

	unsigned int _vertexBuffer, _vertexArray, _faceBuffer;
	Shader* _shader = nullptr;

	std::vector<unsigned int> _faceIds;
	// Ensuring that we arent binding arrays that havent been created yet
	bool firstRun = true;

	// Lights
	int _numLights = 1;

	// Debug Colours
	const std::array<glm::vec3, 5> _Colours = {
		glm::vec3(1.0, 0.0, 0.0), // RED
		glm::vec3(0.0, 1.0, 0.0), // GREEN
		glm::vec3(0.0, 0.0, 1.0), // BLUE
		glm::vec3(1.0, 1.0, 0.0), // YELLOW
		glm::vec3(1.0, 1.0, 1.0), // WHITE
	};

	// Type, Ambient, Diffuse, Specular, Direction, Position, Constant, Linear, Quadratic
	std::array<Light, 1> _lights = {
		Light(LightType::Directional, _Colours[4] * glm::vec3(0.6), glm::vec3(0.7, 0.4, 0.2), glm::vec3(0.8, 0.8, 0.8), glm::vec3(0, 0, 1), glm::vec3(0), 0, 0, 0)
	};
};