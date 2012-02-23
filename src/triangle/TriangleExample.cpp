/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "Scene.h"
#include "Camera.h"

#include "AbstractExample.h"
#include "Triangle.h"

namespace Magnum { namespace Examples {

class TriangleExample: public AbstractExample {
    public:
        inline TriangleExample(int& argc, char** argv): AbstractExample(argc, argv, "Triangle example") {
            /* Every scene needs a camera */
            camera = new Camera(&scene);

            /* Add triangle to the scene */
            new Triangle(&scene);
        }

    protected:
        inline void viewportEvent(const Math::Vector2<GLsizei>& size) {
            camera->setViewport(size);
        }

        inline void drawEvent() {
            camera->draw();
            swapBuffers();
        }

    private:
        Scene scene;
        Camera* camera;
};

}}

MAGNUM_EXAMPLE_MAIN(Magnum::Examples::TriangleExample)