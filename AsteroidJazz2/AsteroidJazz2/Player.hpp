#ifndef BOOK_PLAYER_HPP
#define BOOK_PLAYER_HPP

#include <SFML/Graphics.hpp>

#include <ActionTarget.hpp> //ActionTarget
#include <Entity.hpp>


    class Player : public Entity , public ActionTarget<int>
    {
        public:
            Player(const Player&) = delete;
            Player& operator=(const Player&) = delete;
            Player(World& World);
        
            virtual bool isCollide(const Entity& other) const;
            virtual void update(sf::Time deltaTime);
            void processEvents();
            void shoot();
            void goToHyperspace();
            virtual void onDestroy();

        private:
            sf::Time _timeSinceLastShoot;

            bool _is_moving;
            int _rotation;

    };
#endif
