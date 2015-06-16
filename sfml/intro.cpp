#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");

    sf::CircleShape circle(20);
    sf::Vector2<float> pos(0, 0);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(380, 280);

    sf::Font font;
    font.loadFromFile("inconsolata.otf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(10, 10);

    sf::Text pos_text;
    pos_text.setFont(font);
    pos_text.setCharacterSize(24);
    pos_text.setPosition(10, 40);
    pos_text.setColor(sf::Color::Yellow);

    sf::Text mouse_text;
    mouse_text.setFont(font);
    mouse_text.setCharacterSize(24);
    mouse_text.setPosition(10, 70);
    mouse_text.setColor(sf::Color::Cyan);

    sf::Clock clock;

    sf::Music music;
    music.openFromFile("epoq.ogg");
    music.play();
    music.setLoop(true);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Right:
                            circle.move(10, 0);
                            break;
                        case sf::Keyboard::Left:
                            circle.move(-10, 0);
                            break;
                        case sf::Keyboard::Up:
                            circle.move(0, -10);
                            break;
                        case sf::Keyboard::Down:
                            circle.move(0, 10);
                    }
            }
        }

        sf::Time time = clock.getElapsedTime();
        float secs = time.asSeconds();
        string secs_str = to_string(secs) + " s";

        text.setString(secs_str);
        pos = circle.getPosition();
        pos_text.setString(to_string(int(pos.x)) + ", " + to_string(int(pos.y)));
        sf::Vector2i mpos = sf::Mouse::getPosition();
        mouse_text.setString(to_string(mpos.x) + ", " + to_string(mpos.y));

        music.setPitch(pow(2, (mpos.x / 100) / 12.0));
        music.setVolume((1024 - mpos.y)/10);

        cout << music.getPitch() << " " << music.getVolume() << endl;

        window.clear();
        window.draw(circle);
        window.draw(text);
        window.draw(pos_text);
        window.draw(mouse_text);
        window.display();
    }

    return EXIT_SUCCESS;
}
