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

	// 새 위치 계산.

	// 좌우 이동.
	float factor = direction == Direction::Left ? -1.0f : 1.0f;

	xPosition += speed * factor * deltaTime;
	position.x = (int)xPosition;

	// 화면 밖 벗어나면 삭제.
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

	// 탄약 생성.
	Engine::Get().AddActor(
		new EnemyBullet(Vector2(position.x + width / 2, position.y))
	);
}
