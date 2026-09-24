g++ core/framework.cpp extra/deltaTime.cpp extra/camera.cpp \
    core/mouse.cpp core/keyboard.cpp core/window.cpp \
    object/object.cpp extra/debug.cpp core/draw.cpp \
    physics/collision.cpp animation/spritesheet.cpp "$1" \
    -Iinclude -Llib -lSDL3 -lSDL3_image \
    -o "$2"

echo
echo "Compilation finished. Press Enter to close..."
read