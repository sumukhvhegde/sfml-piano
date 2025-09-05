// Include libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>

// Main
int main() {
	// Define window
	const int w = 1200;
	const int h = 400;
	sf::RenderWindow app(sf::VideoMode({ w, h }), "Piano");

	// Keyboard input
	sf::Keyboard::Scan wKeys[] = {
		// Major keys
		sf::Keyboard::Scan::Tab,
		sf::Keyboard::Scan::Q,
		sf::Keyboard::Scan::W,
		sf::Keyboard::Scan::E,
		sf::Keyboard::Scan::R,
		sf::Keyboard::Scan::T,
		sf::Keyboard::Scan::Y,
		sf::Keyboard::Scan::U,
		sf::Keyboard::Scan::I,
		sf::Keyboard::Scan::O,
		sf::Keyboard::Scan::P,
		sf::Keyboard::Scan::LBracket,
		sf::Keyboard::Scan::RBracket,
		sf::Keyboard::Scan::Backslash,
	};

	sf::Keyboard::Scan bKeys[] = {
		// Minor keys
		sf::Keyboard::Scan::Num1,
		sf::Keyboard::Scan::Num3,
		sf::Keyboard::Scan::Num4,
		sf::Keyboard::Scan::Num6,
		sf::Keyboard::Scan::Num7,
		sf::Keyboard::Scan::Num8,
		sf::Keyboard::Scan::Num0,
		sf::Keyboard::Scan::Hyphen,
		sf::Keyboard::Scan::Backspace
	};

	// Disable key repeat
	app.setKeyRepeatEnabled(false);

	// Load font
	sf::Font font;
	if (!font.openFromFile("fonts/Roboto-Regular.ttf")) {
		std::cerr << "Error loading font!\n";
		return EXIT_FAILURE;
	}

	// Key labels
	std::string whiteLabels[] = {
		"A", "B", "C", "D", "E", "F", "G", 
		"A", "B", "C", "D", "E", "F", "G"
	};

	std::string blackLabels[] = {
		"A#", "C#", "D#", "F#", "G#",
		"A#", "C#", "D#", "F#" 
	};

	// Import sound
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("res/CNote.mp3")) {
		throw std::runtime_error("Failed to load the sound!");
	}

	// Pitch shift
	sf::Sound sound_A1(buffer); sound_A1.setPitch(0.5f * std::pow(2, -3 / 12.f));
	sf::Sound sound_A1s(buffer); sound_A1s.setPitch(0.5f * std::pow(2, -2 / 12.f));
	sf::Sound sound_B1(buffer); sound_B1.setPitch(0.5f * std::pow(2, -1 / 12.f));
	sf::Sound sound_C2(buffer);	sound_C2.setPitch(0.5f);
	sf::Sound sound_C2s(buffer); sound_C2s.setPitch(std::pow(2, -11 / 12.f));
	sf::Sound sound_D2(buffer);	sound_D2.setPitch(std::pow(2, -10 / 12.f));
	sf::Sound sound_D2s(buffer); sound_D2s.setPitch(std::pow(2, -9 / 12.f));
	sf::Sound sound_E2(buffer); sound_E2.setPitch(std::pow(2, -8 / 12.f));
	sf::Sound sound_F2(buffer); sound_F2.setPitch(std::pow(2, -7 / 12.f));
	sf::Sound sound_F2s(buffer); sound_F2s.setPitch(std::pow(2, -6 / 12.f));
	sf::Sound sound_G2(buffer); sound_G2.setPitch(std::pow(2, -5 / 12.f));
	sf::Sound sound_G2s(buffer); sound_G2s.setPitch(std::pow(2, -4 / 12.f));
	sf::Sound sound_A2(buffer); sound_A2.setPitch(std::pow(2, -3 / 12.f));
	sf::Sound sound_A2s(buffer); sound_A2s.setPitch(std::pow(2, -2 / 12.f));
	sf::Sound sound_B2(buffer); sound_B2.setPitch(std::pow(2, -1 / 12.f));
	sf::Sound sound_C3(buffer);
	sf::Sound sound_C3s(buffer); sound_C3s.setPitch(std::pow(2, 1 / 12.f));
	sf::Sound sound_D3(buffer); sound_D3.setPitch(std::pow(2, 2 / 12.f));
	sf::Sound sound_D3s(buffer); sound_D3s.setPitch(std::pow(2, 3 / 12.f));
	sf::Sound sound_E3(buffer); sound_E3.setPitch(std::pow(2, 4 / 12.f));
	sf::Sound sound_F3(buffer); sound_F3.setPitch(std::pow(2, 5 / 12.f));
	sf::Sound sound_F3s(buffer); sound_F3s.setPitch(std::pow(2, 6 / 12.f));
	sf::Sound sound_G3(buffer); sound_G3.setPitch(std::pow(2, 7 / 12.f));

	// Key shapes
	sf::RectangleShape whiteKeys, blackKeys; 

	// White keys
	whiteKeys.setFillColor(sf::Color::White);
	whiteKeys.setOutlineThickness(-1.f);
	whiteKeys.setOutlineColor(sf::Color::Black);

	// While window is open
	while (app.isOpen()) {
		// Handle events
		while (std::optional event = app.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				app.close();
			} else if (event->is<sf::Event::Resized>()) {
				app.setView(sf::View(sf::FloatRect({ 0.f, 0.f }, sf::Vector2f(app.getSize()))));
			} else if (auto key = event->getIf<sf::Event::KeyPressed>()) {
				if (key->scancode == wKeys[0]) sound_A1.play();
				if (key->scancode == wKeys[1]) sound_B1.play();
				if (key->scancode == wKeys[2]) sound_C2.play();
				if (key->scancode == wKeys[3]) sound_D2.play();
				if (key->scancode == wKeys[4]) sound_E2.play();
				if (key->scancode == wKeys[5]) sound_F2.play();
				if (key->scancode == wKeys[6]) sound_G2.play();
				if (key->scancode == wKeys[7]) sound_A2.play();
				if (key->scancode == wKeys[8]) sound_B2.play();
				if (key->scancode == wKeys[9]) sound_C3.play();
				if (key->scancode == wKeys[10]) sound_D3.play();
				if (key->scancode == wKeys[11]) sound_E3.play();
				if (key->scancode == wKeys[12]) sound_F3.play();
				if (key->scancode == wKeys[13]) sound_G3.play();

				if (key->scancode == bKeys[0]) sound_A1s.play();
				if (key->scancode == bKeys[1]) sound_C2s.play();
				if (key->scancode == bKeys[2]) sound_D2s.play();
				if (key->scancode == bKeys[3]) sound_F2s.play();
				if (key->scancode == bKeys[4]) sound_G2s.play();
				if (key->scancode == bKeys[5]) sound_A2s.play();
				if (key->scancode == bKeys[6]) sound_C3s.play();
				if (key->scancode == bKeys[7]) sound_D3s.play();
				if (key->scancode == bKeys[8]) sound_F3s.play();
			}
		}

		// Get window size
		float xWindow = app.getView().getSize().x;
		float yWindow = app.getView().getSize().y;

		// Clear window
		app.clear(sf::Color(16, 15, 20));

		// Draw major keys
		int wKeyN = 14, bKeyN = 9;
		float wKeyWidth = xWindow / wKeyN;

		for (int i = 0; i < wKeyN; ++i) {
			whiteKeys.setSize({ wKeyWidth, yWindow });
			whiteKeys.setPosition({ i * wKeyWidth, 0.f });
			
			if (sf::Keyboard::isKeyPressed(wKeys[i])) whiteKeys.setFillColor(sf::Color(96, 96, 96));
			else whiteKeys.setFillColor(sf::Color::White);
			
			app.draw(whiteKeys);
		}

		// Draw minor keys
		int blackKeyPositions[] = { 1, 3, 4, 6, 7, 8, 10, 11, 13 };
		
		for (int i = 0; i < bKeyN; ++i) {
			int pos = blackKeyPositions[i];

			blackKeys.setSize({ wKeyWidth / 2, yWindow * 0.6f });
			blackKeys.setPosition({ (pos - 0.25f) * wKeyWidth, 0.f });

			if (sf::Keyboard::isKeyPressed(bKeys[i]))
				blackKeys.setFillColor(sf::Color(31, 31, 36));
			else
				blackKeys.setFillColor(sf::Color::Black);
			
			app.draw(blackKeys);
		}

		// Draw white key labels
		for (int i = 0; i < wKeyN; ++i) {
			sf::Text label(font);
			label.setString(whiteLabels[i]);
			label.setCharacterSize(16);
			label.setFillColor(sf::Color::Black);

			// Center the text on each white key
			float x = i * wKeyWidth + wKeyWidth / 2.f - label.getLocalBounds().size.x / 2.f;
			float y = yWindow - 30.f;
			label.setPosition({ x, y });

			app.draw(label);
		}
		
		// Draw black key labels
		for (int i = 0; i < bKeyN; ++i) {
			sf::Text label(font);
			label.setString(blackLabels[i]);
			label.setCharacterSize(14);
			label.setFillColor(sf::Color::White);

			int pos = blackKeyPositions[i];
			float x = (pos - 0.25f) * wKeyWidth + (wKeyWidth / 4.f) - label.getLocalBounds().size.x / 2.f;
			float y = yWindow * 0.6f - 20.f;
			label.setPosition({ x, y });

			app.draw(label);
		}

		// Display
		app.display();
	}

	return EXIT_SUCCESS;
}