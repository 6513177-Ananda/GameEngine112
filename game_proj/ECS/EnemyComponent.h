#pragma once

#include "ECS.h"
#include "Components.h"
#include "../Vector2D.h"

// This component still got some bug

class EnemyComponent : public Component
{
public:
	int health = 100;
	Vector2D player;

	EnemyComponent(Vector2D v): velocity(v)
	{}

	~EnemyComponent()
	{}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		//transform->velocity += Vector2D(1, 1);
	}

	void update() override
	{
		if (health > 0)
		{
			std::cout << velocity.x << std::endl;
			if (transform->position.x < player.x)
			{
				transform->position.x += velocity.x * transform->speed;
			}
			if (transform->position.x > player.x)
			{
				transform->position.x -= velocity.x * transform->speed;
			}
			if (transform->position.y > player.y)
			{
				transform->position.y -= velocity.y * transform->speed;
			}
			if (transform->position.y < player.y)
			{
				transform->position.y += velocity.y * transform->speed;
			}
		}
	}
private:
	// int health = 100;
	TransformComponent* transform;
	Vector2D velocity;
};