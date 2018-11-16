// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_IMAGE_GENERATED_CODE_H_
#define FLATBUFFERS_GENERATED_IMAGE_GENERATED_CODE_H_

#include "flatbuffers/flatbuffers.h"

namespace generated_code {

struct Dimensions;

struct Image;

MANUALLY_ALIGNED_STRUCT(2) Dimensions FLATBUFFERS_FINAL_CLASS {
 private:
  uint16_t width_;
  uint16_t height_;

 public:
  Dimensions() {
    memset(this, 0, sizeof(Dimensions));
  }
  Dimensions(uint16_t _width, uint16_t _height)
      : width_(flatbuffers::EndianScalar(_width)),
        height_(flatbuffers::EndianScalar(_height)) {
  }
  uint16_t width() const {
    return flatbuffers::EndianScalar(width_);
  }
  uint16_t height() const {
    return flatbuffers::EndianScalar(height_);
  }
};
STRUCT_END(Dimensions, 4);

struct Image FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_DIM = 4,
    VT_PIXELS = 6,
    VT_TIMESTAMP = 8
  };
  const Dimensions *dim() const {
    return GetStruct<const Dimensions *>(VT_DIM);
  }
  const flatbuffers::Vector<uint8_t> *pixels() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_PIXELS);
  }
  uint64_t timestamp() const {
    return GetField<uint64_t>(VT_TIMESTAMP, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<Dimensions>(verifier, VT_DIM) &&
           VerifyOffset(verifier, VT_PIXELS) &&
           verifier.Verify(pixels()) &&
           VerifyField<uint64_t>(verifier, VT_TIMESTAMP) &&
           verifier.EndTable();
  }
};

struct ImageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_dim(const Dimensions *dim) {
    fbb_.AddStruct(Image::VT_DIM, dim);
  }
  void add_pixels(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> pixels) {
    fbb_.AddOffset(Image::VT_PIXELS, pixels);
  }
  void add_timestamp(uint64_t timestamp) {
    fbb_.AddElement<uint64_t>(Image::VT_TIMESTAMP, timestamp, 0);
  }
  explicit ImageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ImageBuilder &operator=(const ImageBuilder &);
  flatbuffers::Offset<Image> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Image>(end);
    return o;
  }
};

inline flatbuffers::Offset<Image> CreateImage(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Dimensions *dim = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> pixels = 0,
    uint64_t timestamp = 0) {
  ImageBuilder builder_(_fbb);
  builder_.add_timestamp(timestamp);
  builder_.add_pixels(pixels);
  builder_.add_dim(dim);
  return builder_.Finish();
}

inline flatbuffers::Offset<Image> CreateImageDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Dimensions *dim = 0,
    const std::vector<uint8_t> *pixels = nullptr,
    uint64_t timestamp = 0) {
  return generated_code::CreateImage(
      _fbb,
      dim,
      pixels ? _fbb.CreateVector<uint8_t>(*pixels) : 0,
      timestamp);
}

inline const generated_code::Image *GetImage(const void *buf) {
  return flatbuffers::GetRoot<generated_code::Image>(buf);
}

inline const generated_code::Image *GetSizePrefixedImage(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<generated_code::Image>(buf);
}

inline bool VerifyImageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<generated_code::Image>(nullptr);
}

inline bool VerifySizePrefixedImageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<generated_code::Image>(nullptr);
}

inline void FinishImageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<generated_code::Image> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedImageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<generated_code::Image> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace generated_code

#endif  // FLATBUFFERS_GENERATED_IMAGE_GENERATED_CODE_H_
