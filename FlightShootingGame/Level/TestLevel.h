#pragma once

#include "Level/Level.h"

class TestLevel : public Level
{
	// RTTI ����.
	RTTI_DECLARATIONS(TestLevel, Level)

public:
	TestLevel();
	~TestLevel();

	virtual void Update(float deltaTime) override;
	
private:
	void SpawnEnemy(float deltaTime);

	void ProcessCollisionPlayerBulletAndEnemy();

	// �� ź��� �÷��̾��� �浹 ó��.
	void ProcessCollisionPlayerAndEnemyBullet();

private:
	int score = 0;

};