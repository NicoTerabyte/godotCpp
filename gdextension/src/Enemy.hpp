#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot
{
	class Enemy : public Sprite2D
	{
		GDCLASS(Enemy, Sprite2D)

		private:
			double	mvm_speed;
			double	hp;

		protected:
			static void _bind_methods();

		public:
			Enemy();
			Enemy(double mvm_speed, double hp);
			~Enemy();
			void _ready() override;
			void _process(double delta) override;

			void	take_damage(double damage);
			void	change_pace(double mvm_speed);
			double	get_health() const;

			void    set_health(double hp);
			void    set_movement_speed(double speed);
			double  get_movement_speed() const;
	};

} // namespace godot

#endif
