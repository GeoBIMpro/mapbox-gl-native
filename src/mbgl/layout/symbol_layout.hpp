#pragma once

#include <mbgl/map/mode.hpp>
#include <mbgl/style/layers/symbol_layer_properties.hpp>
#include <mbgl/layout/symbol_feature.hpp>
#include <mbgl/layout/symbol_instance.hpp>
#include <mbgl/text/bidi.hpp>
#include <mbgl/style/layers/symbol_layer_impl.hpp>

#include <memory>
#include <map>
#include <unordered_set>
#include <vector>

namespace mbgl {

class GeometryTileLayer;
class CollisionTile;
class SymbolBucket;
class Anchor;

namespace style {
class BucketParameters;
class Filter;
class Layer;
} // namespace style

class SymbolLayout {
public:
    SymbolLayout(const style::BucketParameters&,
                 const std::vector<const style::Layer*>&,
                 const GeometryTileLayer&,
                 IconDependencies&,
                 uintptr_t,
                 GlyphDependencies&);

    void prepare(const GlyphPositionMap& glyphs, const IconAtlasMap& icons);

    std::unique_ptr<SymbolBucket> place(CollisionTile&);

    bool hasSymbolInstances() const;

    enum State {
        Pending,  // Waiting for the necessary glyphs or icons to be available.
        Placed    // The final positions have been determined, taking into account prior layers.
    };

    State state = Pending;

    std::map<std::string,
        std::pair<style::IconPaintProperties::Evaluated, style::TextPaintProperties::Evaluated>> layerPaintProperties;

private:
    void addFeature(const size_t,
                    const SymbolFeature&,
                    const std::pair<Shaping, Shaping>& shapedTextOrientations,
                    const PositionedIcon& shapedIcon,
                    const GlyphPositions& face);

    bool anchorIsTooClose(const std::u16string& text, const float repeatDistance, const Anchor&);
    std::map<std::u16string, std::vector<Anchor>> compareText;

    void addToDebugBuffers(CollisionTile&, SymbolBucket&);

    // Adds placed items to the buffer.
    template <typename Buffer>
    void addSymbol(Buffer&, const SymbolQuad&, float scale,
                    const bool keepUpright, const style::SymbolPlacementType, const float placementAngle,
                    WritingModeType writingModes);

    const std::string sourceLayerName;
    const std::string bucketName;
    const float overscaling;
    const float zoom;
    const MapMode mode;

    style::SymbolLayoutProperties::PossiblyEvaluated layout;
    float textMaxSize;
    
    uintptr_t spriteAtlasMapIndex; // Actually a pointer to the SpriteAtlas for this symbol's layer, but don't use it from worker threads!

    const uint32_t tileSize;
    const float tilePixelRatio;

    bool sdfIcons = false;
    bool iconsNeedLinear = false;

    std::vector<SymbolInstance> symbolInstances;
    std::vector<SymbolFeature> features;

    BiDi bidi; // Consider moving this up to geometry tile worker to reduce reinstantiation costs; use of BiDi/ubiditransform object must be constrained to one thread
};

} // namespace mbgl
