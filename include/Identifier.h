#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

namespace Components {
    enum Type {
        Base,
        Physics,
        Graphics,
        Input
    };

    enum ID {
        kStandardPhysics,
        kShipGraphics,
        kPlayerInput,
    };
};

namespace GameObjects {
    enum Type {
        kUnknownObject   = 0,
        kShipObject      = 1 << 0,
        kAsteroid        = 1 << 1,
        kNumObjects      = 1 << 2,
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
