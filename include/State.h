#ifndef STATE_H_
#define STATE_H_

#include <memory>

namespace States {
    enum ID {
        kNullState,
        kTitleState,
        kMainMenuState,
        kGameplayState,
        kLoadingState,
        kPausedState
    };
};

class State {
    public:
        typedef std::unique_ptr<State> Ptr;

        struct Context {
            Context(sf::RenderWindow& window,
                    TextureHolder& textures,
                    FontHolder& fonts);

            sf::RenderWindow* window;
            sf::TextureHolder* textures;
            sf::FontHolder* fonts;
        };

        virtual void update(sf::Time delta_time) = 0;
        virtual void draw() const = 0;
        virtual void handleEvent(const sf::Event& event) = 0;

        // virtual void onEnter(){}
        // virtual void onExit(){}

        // virtual void onHidden(){}
        // virtual void onRevealed(){}
    private:
        States::ID id;
};

#endif /* STATE_H_ */
