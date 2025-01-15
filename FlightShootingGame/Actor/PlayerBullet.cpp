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
	// �̵� �� ������ �ð��� �ݵ�� ����ؾ� ��

	position.y = (int) yPosition;
	//roundf = �Ҽ��� ������

	if (position.y < 0.0f) 
	{
		Destroy();
		return;
	}
}
