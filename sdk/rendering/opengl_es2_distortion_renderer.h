/*
 * Copyright 2020 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef CARDBOARD_SDK_RENDERING_OPENGL_ES2_DISTORTION_RENDERER_H_
#define CARDBOARD_SDK_RENDERING_OPENGL_ES2_DISTORTION_RENDERER_H_

#include <array>

#ifdef __ANDROID__
#include <GLES2/gl2.h>
#endif
#ifdef __APPLE__
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#endif
#include "distortion_renderer.h"

namespace cardboard {
namespace rendering {

// @brief OpenGL ES2.0 concrete implementation of DistortionRenderer.
class OpenGlEs2DistortionRenderer : public DistortionRenderer {
 public:
  OpenGlEs2DistortionRenderer();
  ~OpenGlEs2DistortionRenderer();
  void SetMesh(const CardboardMesh* mesh, CardboardEye eye) override;
  void RenderEyeToDisplay(
      int target_display, int x, int y, int width, int height,
      const CardboardEyeTextureDescription* left_eye,
      const CardboardEyeTextureDescription* right_eye) const override;

 private:
  void RenderDistortionMesh(
      const CardboardEyeTextureDescription* eye_description,
      CardboardEye eye) const;

  std::array<GLuint, 2> vertices_vbo_;  // One per eye.
  std::array<GLuint, 2> uvs_vbo_;
  std::array<GLuint, 2> elements_vbo_;
  std::array<int, 2> elements_count_;

  GLuint program_;
  GLuint attrib_pos_;
  GLuint attrib_tex_;
  GLuint uniform_start_;
  GLuint uniform_end_;
};

}  // namespace rendering
}  // namespace cardboard

#endif  // CARDBOARD_SDK_RENDERING_OPENGL_ES2_DISTORTION_RENDERER_H_
