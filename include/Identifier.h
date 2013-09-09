#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

namespace Components {
    
    // Component types. Only needed by GameObjects.
    // i.e. GameObjects are only concerned with the interface of the component.
    enum Type {
        Base,
        Physics,
        Graphics,
        Input
    };

    // Refer to actual component implementations.
    // Only needed by GameObjectFactory to instantiate the correct
    // components when wiring up an object.
    enum ID {
        kStandardPhysics,
        kShipGraphics,
        kPlayerInput,
    };
};

namespace GameObjects {

    // Types of game objects
    enum Type {
        kUnknownObject,
        kShipObject,
        kAsteroid,
        kNumObjects
    };
}

namespace Textures {
    enum Identifier {
        kEmpty
    };
};

namespace Fonts {
    enum Identifier {
        kDefaultFont
    };
};

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

#endif /* IDENTIFIER_H_ */
