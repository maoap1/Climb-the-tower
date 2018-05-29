#pragma once

/// <summary>
/// Pure interface for GameObjects, that can be damaged (i.e. player, enemies).
/// Grants function Damage()
/// </summary>
class Damagable {
public:
	virtual void Damage(int damageType, int value) = 0;
	virtual ~Damagable() {}
};