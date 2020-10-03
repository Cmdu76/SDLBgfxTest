#pragma once

#include "../EngineIntegration.hpp"

#include <vector>
#ifdef ENGINE_DEBUG
#include <string>
#endif // ENGINE_DEBUG

#include "Keyboard.hpp"
#include "Mouse.hpp"

namespace NAMESPACE_NAME
{

class EventSystem
{
public:
	enum class ButtonActionType
	{
		None,
		Pressed,
		Released,
		Hold
	};

	class EventBase
	{
	protected:
		EventBase() = default;

#ifdef ENGINE_DEBUG
		std::string name;
#endif // ENGINE_DEBUG
		U32 hash;
		bool active;
	};

	class EventKey : public EventBase
	{
	public:
		Keyboard::Key key;
		ButtonActionType action;
		U32 modifiers;
	private:
		friend class EventSystem;
		EventKey() = default;
	};

	class EventMouseButton : public EventBase
	{
	public:
		Mouse::Button button;
		ButtonActionType action;
	private:
		friend class EventSystem;
		EventMouseButton() = default;
	};

public:
	static void Update();

	static bool IsKeyActive(const char* name);
	static bool IsKeyActive(U32 hash);
	static U32 GetKeyCount();
	static U32 AddKey(const char* name, Keyboard::Key key, ButtonActionType action, U32 modifiers = static_cast<U32>(Keyboard::Modifier::None));
	static void RemoveKeyAtIndex(U32 index);
	static void RemoveKey(const char* name);
	static void RemoveKey(U32 hash);

	static bool IsMouseButtonActive(const char* name);
	static bool IsMouseButtonActive(U32 hash);
	static U32 GetMouseButtonCount();
	static U32 AddMouseButton(const char* name, Mouse::Button mouseButton, ButtonActionType action);
	static void RemoveMouseButtonAtIndex(U32 index);
	static void RemoveMouseButton(const char* name);
	static void RemoveMouseButton(U32 hash);

	static void SetMouseMoveThreshold(F32 mouseMoveThreshold);
	static F32 GetMouseMoveThreshold();
	static bool HasMouseMoved();
	static Vector2f GetMouseDelta();

	static bool ShouldClose();
	static void ResetShouldClose();

private:
	static U32 HashFct(const char* name);

	static EventSystem& GetInstance();

	EventSystem();
	void HandleEvent(const SDL_Event& event);

	// NonCopyable & NonMovable
	EventSystem(const EventSystem&) = delete;
	EventSystem& operator=(const EventSystem&) = delete;
	EventSystem(Mouse&&) = delete;
	EventSystem& operator=(EventSystem&&) = delete;

	std::vector<EventKey> mKeys;
	std::vector<EventMouseButton> mMouseButtons;
	F32 mMouseMoveTreshold;
	bool mShouldClose;
};

} // namespace NAMESPACE_NAME