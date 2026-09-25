g++ -std=c++17 core/framework.cpp extra/deltaTime.cpp extra/camera.cpp \
    core/mouse.cpp core/keyboard.cpp core/window.cpp \
    object/object.cpp extra/debug.cpp core/draw.cpp \
    physics/collision.cpp animation/spritesheet.cpp \
    animation/animationManager.cpp animation/animation.cpp \
    ui/ui.cpp "$1" \
    -Iinclude -Llib -lSDL3 -lSDL3_image -lSDL3_ttf \
    -o "$2"

echo
echo "Compilation finished. Press Enter to close..."
read