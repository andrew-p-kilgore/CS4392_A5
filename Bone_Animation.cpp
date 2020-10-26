#include "Bone_Animation.h"



Bone_Animation::Bone_Animation()
{
}


Bone_Animation::~Bone_Animation()
{
}

void Bone_Animation::init()
{
	root_position = { 2.0f,1.0f,2.0f };

	scale_vector =
	{
		{1.0f,1.0f,1.0f},
		{0.5f,4.0f,0.5f},
		{0.5f,3.0f,0.5f},
		{0.5f,2.0f,0.5f}
	};

	rotation_degree_vector = 
	{
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f}
	};

	colors = 
	{
		{0.7f,0.0f,0.0f,1.0f},
		{0.7f,0.7f,0.0f,1.0f},
		{0.7f,0.0f,0.7f,1.0f},
		{0.0f,0.7f,0.7f,1.0f}
	};
	x1 = x2 = x3 = 0.0f;
	y1 = y2 = y3 = 0.0f;
	z1 = z2 = z3 = 0.0f;

	glm::mat4 root_mat = glm::mat4(1.0f);
	root_mat = glm::translate(root_mat, root_position);
	root = new Bone(NULL, root_mat);
	root->children.push_back(new Bone(root, glm::translate(root_mat, glm::vec3(0.0, 2.5, 0.0))));
	root->children.push_back(new Bone(root, glm::translate(root_mat, glm::vec3(0.0, 6.0, 0.0))));
	root->children.push_back(new Bone(root, glm::translate(root_mat, glm::vec3(0.0, 8.5, 0.0))));
	root->children[0]->sibling = root->children[1];
	root->children[1]->sibling = root->children[2];
}

void Bone_Animation::update(float delta_time)
{
	root->children[0]->matrix = glm::translate(root->matrix, glm::vec3(0.0, 2.5, 0.0));
	root->children[1]->matrix = glm::translate(root->matrix, glm::vec3(0.0, 6.0, 0.0));
	root->children[2]->matrix = glm::translate(root->matrix, glm::vec3(0.0, 8.5, 0.0));

	root->children[0]->matrix = glm::translate(root->children[0]->matrix, glm::vec3{ 0.0, -2.0, 0.0 });
	root->children[1]->matrix = glm::translate(root->children[1]->matrix, glm::vec3{ 0.0, -5.5, 0.0 });
	root->children[2]->matrix = glm::translate(root->children[2]->matrix, glm::vec3{ 0.0, -8.0, 0.0 });
	for (int i = 0; i < root->children.size(); i++) {
		root->children[i]->matrix = glm::rotate(root->children[i]->matrix, glm::radians(x1), glm::vec3{ 1.0, 0.0, 0.0 });
		root->children[i]->matrix = glm::rotate(root->children[i]->matrix, glm::radians(y1), glm::vec3{ 0.0, 1.0, 0.0 });
		root->children[i]->matrix = glm::rotate(root->children[i]->matrix, glm::radians(z1), glm::vec3{ 0.0, 0.0, 1.0 });
	}
	root->children[0]->matrix = glm::translate(root->children[0]->matrix, glm::vec3{ 0.0, 2.0, 0.0 });
	root->children[1]->matrix = glm::translate(root->children[1]->matrix, glm::vec3{ 0.0, 5.5, 0.0 });
	root->children[2]->matrix = glm::translate(root->children[2]->matrix, glm::vec3{ 0.0, 8.0, 0.0 });

	root->children[1]->matrix = glm::translate(root->children[1]->matrix, glm::vec3{ 0.0, -1.5, 0.0 });
	root->children[2]->matrix = glm::translate(root->children[2]->matrix, glm::vec3{ 0.0, -4.0, 0.0 });
	for (int i = 1; i < root->children.size(); i++) {
		root->children[i]->matrix = glm::rotate(root->children[i]->matrix, glm::radians(x2), glm::vec3{ 1.0, 0.0, 0.0 });
		root->children[i]->matrix = glm::rotate(root->children[i]->matrix, glm::radians(y2), glm::vec3{ 0.0, 1.0, 0.0 });
		root->children[i]->matrix = glm::rotate(root->children[i]->matrix, glm::radians(z2), glm::vec3{ 0.0, 0.0, 1.0 });
	}
	root->children[1]->matrix = glm::translate(root->children[1]->matrix, glm::vec3{ 0.0, 1.5, 0.0 });
	root->children[2]->matrix = glm::translate(root->children[2]->matrix, glm::vec3{ 0.0, 4.0, 0.0 });

	root->children[2]->matrix = glm::translate(root->children[2]->matrix, glm::vec3{ 0.0, -1.0, 0.0 });
	root->children[2]->matrix = glm::rotate(root->children[2]->matrix, glm::radians(x3), glm::vec3{ 1.0, 0.0, 0.0 });
	root->children[2]->matrix = glm::rotate(root->children[2]->matrix, glm::radians(y3), glm::vec3{ 0.0, 1.0, 0.0 });
	root->children[2]->matrix = glm::rotate(root->children[2]->matrix, glm::radians(z3), glm::vec3{ 0.0, 0.0, 1.0 });
	root->children[2]->matrix = glm::translate(root->children[2]->matrix, glm::vec3{ 0.0, 1.0, 0.0 });
}

void Bone_Animation::reset()
{
}

