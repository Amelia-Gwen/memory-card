#ifndef BRUGLESCO_MEMORY_EXPRESSIONS_H
#define BRUGLESCO_MEMORY_EXPRESSIONS_H

#include <fstream>
#include <random>

static std::random_device rd;
static std::mt19937 generator(rd());
static std::ofstream debuggStream("DebugLog.txt");

constexpr unsigned window_width = 1500u;
constexpr unsigned window_height = 800u;

constexpr float menu_button_width = 256.f;
constexpr float menu_button_height = 256.f;

constexpr float play_button_x = 622.f;
constexpr float play_button_y = 96.f;
constexpr float six_button_x = 95.f;
constexpr float eight_button_x = 446.f;
constexpr float twelve_button_x = 797.f;
constexpr float sixteen_button_x = 1148.f;
constexpr float pair_button_y = 448.f;

constexpr float game_button_width = 128.f;
constexpr float game_button_height = 64.f;

constexpr float pause_x = 1244.f;
constexpr float reset_x = 1372.f;

constexpr float display_x = 1244.f;
constexpr float player_one_display_y = 64.f;
constexpr float player_two_display_y = 432.f;

constexpr float display_width = 256.f;
constexpr float display_height = 368.f;

constexpr float player_string_x = 1265.f;
constexpr float player_one_string_y = 72.f;
constexpr float player_two_string_y = 440.f;

enum class DeckSize
{
	six = 6,
	eight = 8,
	twelve = 12,
	sixteen = 16
};

#endif // !BRUGLESCO_MEMORY_EXPRESSIONS_H
