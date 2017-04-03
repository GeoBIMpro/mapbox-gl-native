// This file is generated.
// Edit platform/darwin/scripts/generate-style-code.js, then run `make darwin-style-code`.
#import "MGLRasterStyleLayer.h"

NS_ASSUME_NONNULL_BEGIN

namespace mbgl {
    namespace style {
        class RasterLayer;
    }
}

@interface MGLRasterStyleLayer (Private)

- (instancetype)initWithRawLayer:(mbgl::style::RasterLayer *)rawLayer source:(MGLSource *)source;

@end

NS_ASSUME_NONNULL_END
