#pragma once
#include <string>


namespace kiko
{

	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		bool Initialize();
		void Shutdown();

		void CreateWindow(const std::string& title, int width, int height);
		void BeginFrame();
		void EndFrame();

		void SetColor(int r, int g, int b, int a);
		void DrawLine(int x1, int y1, int x2, int y2);
		void DrawPoint(int x, int y);

		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }

	private:
		int m_width = 0;
		int m_height = 0;

		SDL_Renderer* m_renderer = nullptr;
		SDL_Window* m_window = nullptr;
	};
}