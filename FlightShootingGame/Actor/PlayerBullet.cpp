#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(const Vector2& position)
	: DrawableActor("!")
{
	this->position = position;
	yPosition = (float)position.y;
}

void PlayerBullet::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//--position.y;

	yPosition -= speed * deltaTime;
	// 이동 시 프레임 시간을 반드시 고려해야 함

	position.y = (int) yPosition;
	//roundf = 소수점 버리기

	if (position.y < 0.0f) 
	{
		Destroy();
		return;
	}
}
