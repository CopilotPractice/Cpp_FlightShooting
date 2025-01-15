#include "EnemyBullet.h"
#include "Engine/Engine.h"

EnemyBullet::EnemyBullet(const Vector2& position)
	: DrawableActor("o")
{
	//위치 설정.
	this->position = position;
	yPosition = (float)position.y;
}

void EnemyBullet::Update(float deltaTime)
{
	Super::Update(deltaTime);

	yPosition += speed * deltaTime;
	position.y = (int)yPosition;

	if (yPosition >= Engine::Get().ScreenSize().y)
	{
		Destroy();
	}
}
