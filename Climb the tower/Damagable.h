#pragma once

class Damagable {
public:
	virtual void Damage(int damageType, int value) = 0;
	virtual ~Damagable() {}
};