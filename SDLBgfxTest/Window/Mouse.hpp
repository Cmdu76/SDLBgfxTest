#pragma once

#include "../EngineIntegration.hpp"

#include "../Math/Vector2.hpp"
#include "Window.hpp"

namespace NAMESPACE_NAME
{

class Mouse
{
public:
	// Call this at every frame beginning
	static void Refresh();
	static void HandleEvent(const SDL_Event& event);

	static void SetPositionGlobal(const Vector2i& mousePos);
	static Vector2i GetPositionGlobal();

	static void SetPositionCurrentWindow(const Vector2i& mousePos);
	static Vector2i GetPositionCurrentWindow();

	static bool HasMouseMoved();
	static Vector2i GetMouseMovement();

	static bool HasWheelMoved();
	static I32 GetWheel();
	static bool HasHorizontalWheelMoved();
	static I32 GetHorizontalWheel();

	static Window* GetCurrentWindow();

	enum class Button
	{
		Left,
		Middle,
		Right,
		X1,
		X2,

		Count
	};
	static bool IsHold(Button button);
	static bool IsPressed(Button button);
	static bool IsReleased(Button button);

private:
	static Mouse& GetInstance();

	Mouse();

	// NonCopyable & NonMovable
	Mouse(const Mouse&) = delete;
	Mouse& operator=(const Mouse&) = delete;
	Mouse(Mouse&&) = delete;
	Mouse& operator=(Mouse&&) = delete;

	Vector2i mPosition;
	Vector2i mMouseMovement;
	U32 mPreviousButtonMask;
	U32 mButtonMask;
	I32 mWheel;
	I32 mHorizontalWheel;
};

} // namespace NAMESPACE_NAME