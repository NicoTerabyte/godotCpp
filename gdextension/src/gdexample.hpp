#ifndef GDEXAMPLE_HPP
#define GDEXAMPLE_HPP

#include <godot_cpp/classes/sprite2d.hpp>
// we will work
// mostly in the godot environment
// that's why we defined this namespace
// having that defined means that everything under it will most likely
//have godot:: written before the use of the so said class
namespace godot
{
	//since we are gonna create a personalised node we are gonna
	//inherit the same capabilites the sprite2d has
	// so our node will be able to have the same behavior and work
	// like a sprite2d as well other than making other behavior for it
	class GDExample : public Sprite2D
	{
	GDCLASS(GDExample, Sprite2D);

		private:
			double time_passed;
			double amplitude;

		protected:
			static void _bind_methods();

		public:
			void		set_amplitude(const double amplitude);
			double	get_amplitude() const;
			GDExample();
			~GDExample();

			void		_process(double delta) override;
	};

};

#endif
