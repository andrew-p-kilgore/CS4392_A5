#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>	

class Bone_Animation
{
public:
	Bone_Animation();
	~Bone_Animation();

	struct Bone {
		Bone* parent = NULL;
		glm::mat4 matrix;
		Bone* sibling = NULL;
		std::vector<Bone*> children;
		Bone(Bone* parent_, glm::mat4 matrix_) {
			parent = parent_;
			matrix = matrix_;
		}
	};
	Bone* root;

	void init();
	void update(float delta_time);
	void reset();

public:

	// Here the head of each vector is the root bone
	std::vector<glm::vec3> scale_vector;
	std::vector<glm::vec3> rotation_degree_vector;
	std::vector<glm::vec4> colors;

	glm::vec3 root_position;

	float x1 = 0.0f;
	float y1 = 0.0f;
	float z1 = 0.0f;
	float x2 = 0.0f;
	float y2 = 0.0f;
	float z2 = 0.0f;
	float x3 = 0.0f;
	float y3 = 0.0f;
	float z3 = 0.0f;
};

