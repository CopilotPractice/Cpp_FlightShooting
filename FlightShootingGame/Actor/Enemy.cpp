#include "Enemy.h"
#include "Engine/Engine.h"
#include "Actor/EnemyBullet.h"

Enemy::Enemy(const char* image, int yPosition)
	:DrawableActor(image)
{
	

	int random = Random(1, 10);
	if (random % 2 == 0)
	{
		direction = Direction::Left;

		xPosition = (float)(Engine::Get().ScreenSize().x - width);
	}
	else {
		direction = Direction::Right;

		xPosition = 0.0;
	}

	this->position = Vector2((int)xPosition, yPosition);
}

void Enemy::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// �� ��ġ ���.

	// �¿� �̵�.
	float factor = direction == Direction::Left ? -1.0f : 1.0f;

	xPosition += speed * factor * deltaTime;
	position.x = (int)xPosition;

	// ȭ�� �� ����� ����.
	if (xPosition < 0.0f || position.x > Engine::Get().ScreenSize().x - width)
	{
		Destroy();
	}

	static float elapsedTime = 0.0f;
	static float fireInterval = RandomPercent(1.0f, 2.0f);

	elapsedTime += deltaTime;

	if (elapsedTime < fireInterval) 
	{
		return;
	}

	elapsedTime = 0.0f;
	fireInterval = RandomPercent(1.0f, 2.0f);

	// ź�� ����.
	Engine::Get().AddActor(
		new EnemyBullet(Vector2(position.x + width / 2, position.y))
	);
}
