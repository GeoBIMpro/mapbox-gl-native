#pragma once

#include <mbgl/gl/attribute.hpp>
#include <mbgl/gl/uniform.hpp>

#include <cstdint>

namespace mbgl {
namespace attributes {

// Layout attributes

MBGL_DEFINE_ATTRIBUTE(int16_t, 2, a_pos);
MBGL_DEFINE_ATTRIBUTE(int16_t, 2, a_extrude);
MBGL_DEFINE_ATTRIBUTE(int16_t, 4, a_pos_offset);
MBGL_DEFINE_ATTRIBUTE(uint16_t, 2, a_texture_pos);

template <std::size_t N>
struct a_data {
    static auto name() { return "a_data"; }
    using Type = gl::Attribute<uint8_t, N>;
};

template <std::size_t N>
struct a_offset {
    static auto name() { return "a_offset"; }
    using Type = gl::Attribute<int16_t, N>;
};

// Paint attributes

struct a_color {
    static auto name() { return "a_color"; }
    using Type = gl::Attribute<float, 2>;
};

struct a_fill_color {
    static auto name() { return "a_fill_color"; }
    using Type = gl::Attribute<float, 2>;
};

struct a_halo_color {
    static auto name() { return "a_halo_color"; }
    using Type = gl::Attribute<float, 2>;
};

struct a_stroke_color {
    static auto name() { return "a_stroke_color"; }
    using Type = gl::Attribute<float, 2>;
};

struct a_outline_color {
    static auto name() { return "a_outline_color"; }
    using Type = gl::Attribute<float, 2>;
};

struct a_opacity {
    static auto name() { return "a_opacity"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_stroke_opacity {
    static auto name() { return "a_stroke_opacity"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_blur {
    static auto name() { return "a_blur"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_radius {
    static auto name() { return "a_radius"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_width {
    static auto name() { return "a_width"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_height {
    static auto name() { return "a_height"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_base {
    static auto name() { return "a_base"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_gap_width {
    static auto name() { return "a_gapwidth"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_stroke_width {
    static auto name() { return "a_stroke_width"; }
    using Type = gl::Attribute<float, 1>;
};

template <>
struct a_offset<1> {
    static auto name() { return "a_offset"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_halo_width {
    static auto name() { return "a_halo_width"; }
    using Type = gl::Attribute<float, 1>;
};

struct a_halo_blur {
    static auto name() { return "a_halo_blur"; }
    using Type = gl::Attribute<float, 1>;
};

} // namespace attributes
} // namespace mbgl
