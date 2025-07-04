#include "Enemy.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Enemy::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("take_damage", "damage"), &Enemy::take_damage);
	ClassDB::bind_method(D_METHOD("change_pace", "new_pace"), &Enemy::change_pace);
	ClassDB::bind_method(D_METHOD("get_health"), &Enemy::get_health);

	ClassDB::bind_method(D_METHOD("set_health", "hp"), &Enemy::set_health);
	ClassDB::bind_method(D_METHOD("set_movement_speed", "speed"), &Enemy::set_movement_speed);
	ClassDB::bind_method(D_METHOD("get_movement_speed"), &Enemy::get_movement_speed);
}

Enemy::Enemy()
{
	std::cout<<"Standard constructor called"<<std::endl;
	this->mvm_speed = 50.0;
	this->hp = 100.0;
}

Enemy::Enemy(double mvm_speed, double hp)
{
	std::cout<<"base constructor of the enemy called"<<std::endl;
	this->mvm_speed = mvm_speed;
	this->hp = hp;
}

Enemy::~Enemy()
{}

void Enemy::_ready()
{
	// Called when the node enters the scene tree
}

void Enemy::_process(double delta)
{
	// Called every frame - add movement logic here
}

void Enemy::take_damage(double damage)
{
	this->hp -= damage;
	if (this->hp <= 0) {
		queue_free(); // Remove from scene when health reaches 0
	}
}

void Enemy::change_pace(double new_pace)
{
	this->mvm_speed = new_pace;
}

double Enemy::get_health() const
{
	return (this->hp);
}

void Enemy::set_health(double hp)
{
	this->hp = hp;
}

void Enemy::set_movement_speed(double speed)
{
	this->mvm_speed = speed;
}

double Enemy::get_movement_speed() const
{
	return this->mvm_speed;
}
