#pragma once

#include "../EngineIntegration.hpp"

#include <bgfx/bgfx.h>

namespace NAMESPACE_NAME
{

class Shader
{
public:
    Shader();
	~Shader();

	bool Initialize(const char* vertexModule, const char* fragmentModule = nullptr);
	void Destroy();

	bool IsValid() const;

	bool HasVertexModule() const;
	bool HasFragmentModule() const;

	void Submit(bgfx::ViewId viewId);

private:
	bgfx::ShaderHandle CreateModule(const char* filename);

private:
	bgfx::ProgramHandle mShaderProgram;
	bgfx::ShaderHandle mVertexModule;
	bgfx::ShaderHandle mFragmentModule;
};

} // namespace NAMESPACE_NAME