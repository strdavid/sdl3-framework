#pragma once

struct Vec2 {
    float x, y;

    Vec2 operator+(const Vec2& other) const {
        return { x + other.x, y + other.y };
    }

    Vec2 operator-(const Vec2& other) const {
        return { x - other.x, y - other.y };
    }

    Vec2 operator*(float scalar) const {
        return { x * scalar, y * scalar };
    }

    Vec2 operator/(float scalar) const {
        return { x / scalar, y / scalar };
    }
};


struct Vec2i {
    int x, y;

    Vec2i operator+(const Vec2i& other) const {
        return { x + other.x, y + other.y };
    }

    Vec2i operator-(const Vec2i& other) const {
        return { x - other.x, y - other.y };
    }

    Vec2i operator*(float scalar) const {
        return {
            static_cast<int>(x * scalar),
            static_cast<int>(y * scalar)
        };
    }

    Vec2i operator/(float scalar) const {
        return {
            static_cast<int>(x / scalar),
            static_cast<int>(y / scalar)
        };
    }
};


struct Vec3 {
    float x, y, z;

    Vec3 operator+(const Vec3& other) const {
        return {
            x + other.x,
            y + other.y,
            z + other.z
        };
    }

    Vec3 operator-(const Vec3& other) const {
        return {
            x - other.x,
            y - other.y,
            z - other.z
        };
    }

    Vec3 operator*(float scalar) const {
        return {
            x * scalar,
            y * scalar,
            z * scalar
        };
    }

    Vec3 operator/(float scalar) const {
        return {
            x / scalar,
            y / scalar,
            z / scalar
        };
    }
};


struct Vec3i {
    int x, y, z;

    Vec3i operator+(const Vec3i& other) const {
        return {
            x + other.x,
            y + other.y,
            z + other.z
        };
    }

    Vec3i operator-(const Vec3i& other) const {
        return {
            x - other.x,
            y - other.y,
            z - other.z
        };
    }

    Vec3i operator*(float scalar) const {
        return {
            static_cast<int>(x * scalar),
            static_cast<int>(y * scalar),
            static_cast<int>(z * scalar)
        };
    }

    Vec3i operator/(float scalar) const {
        return {
            static_cast<int>(x / scalar),
            static_cast<int>(y / scalar),
            static_cast<int>(z / scalar)
        };
    }
};
