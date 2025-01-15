#pragma once

#include "Level/Level.h"

class TestLevel : public Level
{
	// RTTI 적용.
	RTTI_DECLARATIONS(TestLevel, Level)

public:
	TestLevel();
	~TestLevel();

	virtual void Update(float deltaTime) override;
	
private:
	void SpawnEnemy(float deltaTime);

	void ProcessCollisionPlayerBulletAndEnemy();

	// 적 탄약과 플레이어의 충돌 처리.
	void ProcessCollisionPlayerAndEnemyBullet();

private:
	int score = 0;

};