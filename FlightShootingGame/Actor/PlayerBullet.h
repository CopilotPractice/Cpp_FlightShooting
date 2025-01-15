#pragma once

#include <Actor/DrawableActor.h>

class PlayerBullet : public DrawableActor
{
	RTTI_DECLARATIONS(PlayerBullet, DrawableActor)

public:
	PlayerBullet(const Vector2& position);

	virtual void Update(float deltaTime) override;

private:

	// �̵� �ӷ�(ĭ / ��)
	float speed = 20.0f;

	float yPosition = 0.0f;

};
