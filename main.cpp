// library
#include <SFML/Graphics.hpp>
#include <iostream>

// main program
int main()
{
    // create window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title");

    // hide mouse cursor
    // window.setMouseCursorVisible(false);

    // while window is still open
    while (window.isOpen())
    {
        // handle events
        while (std::optional event = window.pollEvent())
        {
            // when close button is clicked
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }
            
            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                window.setView(sf::View(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize()))));
            }

            // when mouse wheel is scrolled
            else if (auto* mouse = event->getIf<sf::Event::MouseWheelScrolled>())
            {
                if (mouse->wheel == sf::Mouse::Wheel::Vertical)
                    std::cout << "Vertical ";
                if (mouse->wheel == sf::Mouse::Wheel::Horizontal)
                    std::cout << "Horizontal ";
                std::cout << "Scroll " << mouse->delta << '\n';
            }

            // when mouse enter window
            else if (event->is<sf::Event::MouseEntered>())
            {
                std::cout << "Enter window\n";
            }

            // when mouse leave window
            else if (event->is<sf::Event::MouseLeft>())
            {
                std::cout << "Leave window\n";
            }

            // when mouse button is pressed
            else if (auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouse->button == sf::Mouse::Button::Left)
                {
                    std::cout << "Left button is pressed\n";
                }
            }

            // when mouse button is released
            else if (auto* mouse = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouse->button == sf::Mouse::Button::Left)
                {
                    std::cout << "Left button is released\n";
                }
            }

            // when mouse is moved
            else if (auto* mouse = event->getIf<sf::Event::MouseMoved>())
            {
                std::cout << "x = " << mouse->position.x << ", y = " << mouse->position.y << '\n';
            }
        }

        // set mouse position to center of window
        // sf::Mouse::setPosition({400, 300}, window);

        // fill window with color
        window.clear(sf::Color(64, 64, 64));

        // display
        window.display();
    }
    
    // program end successfully
    return 0;
}