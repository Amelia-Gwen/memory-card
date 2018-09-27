#ifndef BRUGLESCO_MEMORY_PLAYER_H
#define BRUGLESCO_MEMORY_PLAYER_H

namespace memory {

	class Player
	{
	public:
		explicit Player(unsigned identity);

		void scorePoint();

		void reset();

		unsigned getIdentity() const;

		unsigned getScore() const;
	private:
		const unsigned identity;
		unsigned score{ 0 };
	};

}

#endif // !BRUGLESCO_MEMORY_PLAYER_H
