#ifndef BRUGLESCO_MEMORY_EXPRESSIONS_H
#define BRUGLESCO_MEMORY_EXPRESSIONS_H

#include <fstream>
#include <random>

namespace bruglesco {

	static std::random_device rd;
	static std::mt19937 generator(rd());

	constexpr unsigned screen_width = 1500u;
	constexpr unsigned screen_height = 800u;

	constexpr float menu_button_width = 256.f;
	constexpr float menu_button_height = 256.f;

	constexpr float play_button_x = 622.f;
	constexpr float play_button_y = 96.f;
	constexpr float six_button_x = 95.f;
	constexpr float eight_button_x = 446.f;
	constexpr float twelve_button_x = 797.f;
	constexpr float sixteen_button_x = 1148.f;
	constexpr float pair_button_y = 448.f;

	constexpr float play_string_x_offset = 18.f;
	constexpr float play_string_y_offset = 28.f;
	constexpr float six_string_x_offset = 80.f;
	constexpr float eight_string_x_offset = 40.f;
	constexpr float twelve_string_x_offset = 15.f;
	constexpr float sixteen_string_x_offset = 8.f;
	constexpr float pair_string_x_offset = 40.f;
	constexpr float pair_string_y_offset = 100.f;

	constexpr float game_button_width = 128.f;
	constexpr float game_button_height = 64.f;

	constexpr float pause_x = 1244.f;
	constexpr float reset_x = 1372.f;
	constexpr float pause_offset = 12.f;
	constexpr float reset_offset = 5.f;

	constexpr float display_x = 1244.f;
	constexpr float player_one_display_y = 64.f;
	constexpr float player_two_display_y = 432.f;
	constexpr float display_offset = 20.f;

	constexpr float display_width = 256.f;
	constexpr float display_height = 368.f;

	constexpr float canvas_width = screen_width - display_width;
	constexpr float canvas_height = static_cast<float>(screen_height);

	constexpr float player_string_x = 1265.f;
	constexpr float player_one_string_y = 72.f;
	constexpr float player_two_string_y = 440.f;

	constexpr float player_card_x = 1250.f;
	constexpr float player_card_x_offset = 10.f;
	constexpr float player_one_card_y = 120.f;
	constexpr float player_two_card_y = 488.f;

	constexpr float card_width = 128.f;
	constexpr float card_height = 128.f;

	constexpr unsigned max_pairs = 16u;

	constexpr float win_width = screen_width - 300.f;
	constexpr float win_height = screen_height - 150.f;
	constexpr float win_x = 150.f;
	constexpr float win_y = 75.f;
	constexpr float winstring_x = 400.f;
	constexpr float winstring_y = 100.f;
	constexpr float player_winstring_x = winstring_x - 50.f;
	constexpr float player_winstring_y = winstring_y + 200.f;

	enum class DeckSize
	{
		six = 6,
		eight = 8,
		twelve = 12,
		sixteen = 16
	};

	enum class CardState
	{
		unmatched,
		checking,
		matched
	};

	enum class menuMouseIn
	{
		none,
		play,
		six,
		eight,
		twelve,
		sixteen
	};

	enum class gameMouseIn
	{
		none,
		pause,
		reset
	};

	enum class winState
	{
		none,
		draw,
		playerOne,
		playerTwo
	};
}

#endif // !BRUGLESCO_MEMORY_EXPRESSIONS_H
